#include "machine.hpp"

#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include "bytecode.hpp"
#include "canvas.hpp"
#include "gpp.hpp"
#include "util.hpp"

gpp::Machine::Machine()
    : emitter(std::make_shared<gpp::BytecodeEmitter>(*this)), input("\n"),
      canvasXY(0, 0), canvasYZ(0, 0), canvasXZ(0, 0) {
  reset();
}

gpp::Machine::Machine(std::string input)
    : emitter(std::make_shared<gpp::BytecodeEmitter>(*this)), input(input),
      canvasXY(512, 512), canvasYZ(512, 512), canvasXZ(512, 512) {
  reset();

  initTools("config/tools.txt");

  std::cout << "Initialized machine!\n";
  // printSpecs();
}

void gpp::Machine::reset(std::string code) {
  emitter = std::make_shared<BytecodeEmitter>(*this, code);

  reset();
}

void gpp::Machine::reset() {
  emitterStashed = false;
  position = {0, 0, 0};
  g92offset = {0, 0, 0};
  g5xoffset = {0, 0, 0};
  toolOffset = 0;

  for (Vec3D &offset : workOffsets)
    offset = {0, 0, 0};

  unit = Unit::mm;
  distanceMode = absolute;
  plane = plane_xy;

  feedRate = 0;
  rawFeedRate = 0;
  feedMode = units_per_minute;

  spindleDirection = off;
  spindleMode = fixed_rpm;
  spindleSpeed = 0;
  rawSpindleSpeed = 0;

  retractMode = old_z;
  motionControlMode = exact_stop;

  selectedTool = 0;
  currentTool = 1;
  tools.clear();

  activeInstruction = {.word = '0'};
  memory.clear();

  plotToCanvas = false;

  handlers[Command::move_linear] =
      std::bind(&Machine::move_linear, this, std::placeholders::_1);
  handlers[Command::move_rapid] =
      std::bind(&Machine::move_rapid, this, std::placeholders::_1);

  handlers[Command::set_feed_rate] =
      std::bind(&Machine::set_feed_rate, this, std::placeholders::_1);
  handlers[Command::set_feed_mode] =
      std::bind(&Machine::set_feed_mode, this, std::placeholders::_1);

  handlers[Command::use_length_units] =
      std::bind(&Machine::use_length_units, this, std::placeholders::_1);
  handlers[Command::use_distance_mode] =
      std::bind(&Machine::use_distance_mode, this, std::placeholders::_1);
  handlers[Command::select_plane] =
      std::bind(&Machine::select_plane, this, std::placeholders::_1);
  handlers[Command::arc_feed] =
      std::bind(&Machine::arc_feed, this, std::placeholders::_1);

  handlers[Command::dwell] =
      std::bind(&Machine::dwell, this, std::placeholders::_1);
  handlers[Command::set_origin_offsets] =
      std::bind(&Machine::set_origin_offsets, this, std::placeholders::_1);

  handlers[Command::start_spindle_clockwise] =
      std::bind(&Machine::start_spindle_clockwise, this, std::placeholders::_1);
  handlers[Command::start_spindle_counterclockwise] = std::bind(
      &Machine::start_spindle_counterclockwise, this, std::placeholders::_1);
  handlers[Command::stop_spindle_turning] =
      std::bind(&Machine::stop_spindle_turning, this, std::placeholders::_1);
  handlers[Command::set_spindle_speed] =
      std::bind(&Machine::set_spindle_speed, this, std::placeholders::_1);
  handlers[Command::set_spindle_mode] =
      std::bind(&Machine::set_spindle_mode, this, std::placeholders::_1);

  handlers[Command::select_tool] =
      std::bind(&Machine::select_tool, this, std::placeholders::_1);
  handlers[Command::change_tool] =
      std::bind(&Machine::change_tool, this, std::placeholders::_1);

  handlers[Command::program_stop] =
      std::bind(&Machine::program_stop, this, std::placeholders::_1);
  handlers[Command::optional_program_stop] =
      std::bind(&Machine::optional_program_stop, this, std::placeholders::_1);
  handlers[Command::program_end] =
      std::bind(&Machine::program_end, this, std::placeholders::_1);

  handlers[Command::use_tool_length_offset] =
      std::bind(&Machine::use_tool_length_offset, this, std::placeholders::_1);
  handlers[Command::set_tool_length_offset] =
      std::bind(&Machine::set_tool_length_offset, this, std::placeholders::_1);

  handlers[Command::set_wcs_coordinates] =
      std::bind(&Machine::set_wcs_coordinates, this, std::placeholders::_1);
  handlers[Command::use_workspace] =
      std::bind(&Machine::use_workspace, this, std::placeholders::_1);

  handlers[Command::set_retract_mode] =
      std::bind(&Machine::set_retract_mode, this, std::placeholders::_1);
  handlers[Command::set_motion_control_mode] =
      std::bind(&Machine::set_motion_control_mode, this, std::placeholders::_1);

  /* these are probably temporary */
  handlers[Command::write_parameter_to_file] = std::bind(
      &gpp::Machine::write_parameter_to_file, this, std::placeholders::_1);
  handlers[Command::write_parameters_to_file] = std::bind(
      &gpp::Machine::write_parameters_to_file, this, std::placeholders::_1);
}

f64 gpp::Machine::getMemory(i64 address) {
  if (address < 0 || address >= memory.size()) {
    return NAN; // TODO replace with error later
  }

  return memory.at(address);
}

void gpp::Machine::setMemory(i64 address, f64 value) {
  if (address < 0)
    return;
  if (address >= memory.size()) {
    memory.resize(address + 1);
  }

  memory.at(address) = value;
}

std::string gpp::Machine::getCurrentLine() {
  int line = emitter->executionStack.empty()
                 ? 0
                 : emitter->executionStack.top().linePointer;
  return emitter->getLineFromSource(line);
}

SafeInstruction gpp::Machine::next() {
  while (emitter->bytecode.empty()) {
    if (!emitter->fetchInstructions())
      return Instruction{no_command};

    VerboseInstruction vi = emitter->verboseInstructions.front();
    emitter->verboseInstructions.pop_front();

    if (vi.word == 'e') {
      gpp::Error error = std::get<gpp::Error>(vi.instruction);
      emitter->bytecode.push_back(gpp::Error(error));
    }

    if (vi.word == 'c') {
      emitter->words.clear();
    } else if (vi.word == 'g') {
      handle_g(emitter->verboseInstructions, vi.arg, emitter->words, 0, 0);
    } else if (vi.word == 'f') {
      f64 f = emitter->findParameter(emitter->words, 'f');
      emitter->bytecode.push_back(
          Instruction{.command = gpp::set_feed_rate, .arguments = {f}});
    } else if (vi.word == 'm') {
      handle_m(emitter->verboseInstructions, vi.arg, emitter->words, 0, 0);
    } else if (vi.word == 's') {
      f64 s = emitter->findParameter(emitter->words, 's');
      emitter->bytecode.push_back(
          Instruction{.command = gpp::set_spindle_speed, .arguments = {s}});
    } else if (vi.word == 't') {
      f64 t = emitter->findParameter(emitter->words, 't');

      if (tools.find(t) == tools.end())
        emitter->bytecode.push_back(gpp::Error(
            ErrorType::MACHINE_ERROR, "Tool does not exist!",
            emitter->getLineFromSource(emitter->line), emitter->line));
      else
        emitter->bytecode.push_back(
            Instruction{.command = gpp::select_tool, .arguments = {t}});
    }
  }

  SafeInstruction safeInstruction = emitter->bytecode.front();
  emitter->bytecode.pop_front();

  if (std::holds_alternative<Error>(safeInstruction)) {
    Error &err = std::get<Error>(safeInstruction);
    return safeInstruction;
  }

  Instruction instruction = std::get<Instruction>(safeInstruction);

  if (instruction.command == no_command)
    return instruction;

  handlers[instruction.command](instruction.arguments);

  if (spindleDirection != off)
    saveCanvases();

  return instruction;
}

void gpp::Machine::bind(std::shared_ptr<gpp::BytecodeEmitter> tempEmitter) {
  emitterStashed = true;
  emitterStash = emitter;
  emitter = tempEmitter;
}

void gpp::Machine::unbind() {
  emitter = emitterStash;
  emitterStashed = false;
}

void gpp::Machine::printSpecs() {
  std::cout << "--- Machine Specifications ---\n";

  std::cout << "Position: " << position << "\n";
  std::cout << "G5x Offset: " << g5xoffset << "\n";
  std::cout << "G92/G52 Offset: " << g92offset << "\n";
  std::cout << "Tool Length Offset (G43): " << toolOffset << "\n";

  std::cout << "Work Offsets (G54–G59):\n";
  for (int i = 0; i < 6; ++i) {
    std::cout << "  G5" << (4 + i) << ": " << workOffsets[i] << "\n";
  }

  std::cout << "Unit: " << (unit == mm ? "mm" : "inch") << "\n";
  std::cout << "Distance Mode: "
            << (distanceMode == absolute ? "Absolute" : "Relative") << "\n";

  std::cout << "Plane: ";
  switch (plane) {
  case plane_xy:
    std::cout << "XY\n";
    break;
  case plane_yz:
    std::cout << "YZ\n";
    break;
  case plane_xz:
    std::cout << "XZ\n";
    break;
  default:
    std::cout << "Unknown\n";
    break;
  }

  std::cout << "Feed Rate: " << feedRate << " "
            << (unit == mm ? "mm/min" : "in/min") << "\n";

  std::cout << "Spindle Direction: "
            << (spindleDirection == clockwise          ? "CW"
                : spindleDirection == counterclockwise ? "CCW"
                                                       : "Off")
            << "\n";

  std::cout << "Spindle Speed: " << spindleSpeed << " RPM\n";
  std::cout << "Selected Tool: " << selectedTool << "\n";
  std::cout << "Current Tool: " << currentTool << "\n";

  std::cout << "Tools Loaded: " << tools.size() << "\n";
  for (const auto &[id, tool] : tools) {
    std::cout << "  Tool " << id << ": " << tool << "\n";
  }

  std::cout << "-------------------------------\n";
}

void gpp::Machine::initTools(std::string file) {
  tools.clear();

  std::ifstream fp(file);
  std::string line;
  bool header_skipped = false;

  while (std::getline(fp, line)) {
    if (line.empty() || line[0] == '#')
      continue;

    std::istringstream iss(line);
    Tool tool;

    if (!(iss >> tool.pocket >> tool.fms >> tool.tlo >> tool.diam >>
          tool.holder)) {
      std::cerr << "Failed to parse numeric fields: " << line << "\n";
      continue;
    }

    std::getline(iss >> std::ws, tool.description);
    tools[tool.pocket] = tool;
  }
}

void gpp::Machine::move_linear(std::vector<f64> args) {
  Vec3D prev = position;
  Vec3D delta = {args.at(0), args.at(1), args.at(2)};
  position = resolvePosition(delta);

  std::cout << "move_linear" << delta << "\n";

  handleCSSMode();

  drawLinesOnPlanes(prev, position);
}

void gpp::Machine::move_rapid(std::vector<f64> args) {
  Vec3D prev = position;
  Vec3D delta = {args.at(0), args.at(1), args.at(2)};
  position = resolvePosition(delta);

  std::cout << "move_rapid" << delta << "\n";

  handleCSSMode();

  drawLinesOnPlanes(prev, position);
}

void gpp::Machine::set_feed_rate(std::vector<f64> args) {
  rawFeedRate = args.at(0) * unitMultiplier(unit);

  feedRate = (feedMode == units_per_minute) ? rawFeedRate
             : (feedMode == inverse_time)
                 ? 1.0 / rawFeedRate
                 : rawFeedRate * std::abs(spindleSpeed);

  std::cout << "set_feed_rate(" << feedRate << ")\n";
}

void gpp::Machine::set_feed_mode(std::vector<f64> args) {
  feedMode = (FeedMode)args.at(0);
  rawFeedRate = NAN;

  std::cout << "set_feed_mode(";
  std::cout << (feedMode == units_per_minute
                    ? "units_per_minute"
                    : (feedMode == inverse_time ? "inverse_time"
                                                : "units_per_revolution"));
  std::cout << ")\n";
}

void gpp::Machine::use_length_units(std::vector<f64> args) {
  unit = (Unit)args.at(0);

  std::cout << "use_length_units(";
  std::cout << unitToString(unit);
  std::cout << ")\n";
}

void gpp::Machine::use_distance_mode(std::vector<f64> args) {
  distanceMode = (DistanceMode)args.at(0);

  std::cout << "use_distance_mode(";
  std::cout << (distanceMode == absolute ? "absolute" : "relative");
  std::cout << ")\n";
};

void gpp::Machine::select_plane(std::vector<f64> args) {
  plane = (Plane)args.at(0);

  std::cout << "select_plane(";
  std::cout << (plane == plane_xy ? "XY" : (plane == plane_yz ? "YZ" : "XZ"));
  std::cout << ")\n";
}

void gpp::Machine::arc_feed(std::vector<f64> args) {
  f64 first_end = args.at(0);
  f64 second_end = args.at(1);
  f64 first_axis = args.at(2);
  f64 second_axis = args.at(3);
  int rotation = args.at(4);
  f64 axis_end_point = args.at(5);

  Vec3D prev = position;
  position = plane == plane_xy
                 ? resolvePosition({first_end, second_end, axis_end_point})
             : plane == plane_yz
                 ? resolvePosition({axis_end_point, first_end, second_end})
                 : resolvePosition({first_end, axis_end_point, second_end});

  std::cout << "arc_feed(" << first_end << ", " << second_end << ", "
            << first_axis << ", " << second_axis << ", " << rotation << ", "
            << axis_end_point << ")\n";

  if (spindleDirection == off)
    return;

  Vec2D start, center;
  if (plane == plane_xy) {
    start = {prev.x, prev.y};
    center = {prev.x + first_axis, prev.y + second_axis};
  } else if (plane == plane_yz) {
    start = {prev.y, prev.z};
    center = {prev.y + first_axis, prev.z + second_axis};
  } else {
    start = {prev.x, prev.z};
    center = {prev.x + first_axis, prev.z + second_axis};
  }

  Vec2D end;
  if (plane == plane_xy)
    end = {position.x, position.y};
  else if (plane == plane_yz)
    end = {position.y, position.z};
  else
    end = {position.x, position.z};

  f64 start_angle = atan2(start.y - center.y, start.x - center.x);
  f64 end_angle = atan2(end.y - center.y, end.x - center.x);

  if (rotation == 0 && end_angle > start_angle)
    end_angle -= 2 * M_PI;
  else if (rotation == 1 && end_angle < start_angle)
    end_angle += 2 * M_PI;

  f64 radius = sqrt((start - center).dot(start - center));

  if (plane == plane_xy)
    canvasXY.drawArc(center.x, center.y, radius, start_angle, end_angle, 0, 0,
                     0);
  else if (plane == plane_yz)
    canvasYZ.drawArc(center.x, center.y, radius, start_angle, end_angle, 0, 0,
                     0);
  else
    canvasXZ.drawArc(center.x, center.y, radius, start_angle, end_angle, 0, 0,
                     0);
}

void gpp::Machine::dwell(std::vector<f64> args) {
  std::cout << "dwell(" << args.at(0) << ")\n";
}

void gpp::Machine::set_origin_offsets(std::vector<f64> args) {
  Vec3D logical_position = {args.at(0), args.at(1), args.at(2)};
  logical_position = logical_position * unitMultiplier(unit);
  g92offset = position - logical_position;

  std::cout << "set_origin_offsets" << g92offset << "\n";
}

void gpp::Machine::start_spindle_clockwise(std::vector<f64> args) {
  spindleDirection = clockwise;
  std::cout << "start_spindle_clockwise()";
  if (spindleSpeed == 0)
    std::cout << " -- !spindle speed is zero! --";
  std::cout << "\n";
}

void gpp::Machine::start_spindle_counterclockwise(std::vector<f64> args) {
  spindleDirection = counterclockwise;
  std::cout << "start_spindle_counterclockwise()";
  if (spindleSpeed == 0)
    std::cout << " -- !spindle speed is zero! --";
  std::cout << "\n";
}

void gpp::Machine::stop_spindle_turning(std::vector<f64> args) {
  spindleDirection = off;
  std::cout << "stop_spindle_turning()\n";
}

void gpp::Machine::set_spindle_speed(std::vector<f64> args) {
  rawSpindleSpeed = args.at(0);

  if (spindleMode == constant_surface_speed)
    handleCSSMode();
  else
    spindleSpeed = rawSpindleSpeed;

  std::cout << "set_spindle_speed(" << spindleSpeed << ")\n";
  handleCSSMode();
}

void gpp::Machine::set_spindle_mode(std::vector<f64> args) {
  spindleMode = (SpindleMode)args.at(0);
  std::cout << "set_spindle_mode(";
  std::cout << (spindleMode == fixed_rpm ? "fixed_rpm"
                                         : "constant_surface_speed");
  std::cout << ")\n";

  handleCSSMode();
}

void gpp::Machine::select_tool(std::vector<f64> args) {
  selectedTool = args.at(0);
  std::cout << "select_tool(" << selectedTool << ")\n";
}

void gpp::Machine::change_tool(std::vector<f64> args) {
  currentTool = selectedTool;
  std::cout << "change_tool(" << currentTool << ")\n";
  handleCSSMode();
}

void gpp::Machine::program_stop(std::vector<f64> args) {
  std::cout << "program_stop()\n";
}

void gpp::Machine::optional_program_stop(std::vector<f64> args) {
  std::cout << "optional_program_stop()\n";
}

void gpp::Machine::program_end(std::vector<f64> args) {
  std::cout << "program_end()\n";
}

void gpp::Machine::use_tool_length_offset(std::vector<f64> args) {
  toolOffset = args.at(0);
  std::cout << "use_tool_length_offset(" << toolOffset << ")\n";
}

void gpp::Machine::set_tool_length_offset(std::vector<f64> args) {
  tools.at((int)args.at(0)).tlo = args.at(1);
  std::cout << "set_tool_length_offset(" << args.at(0) << ", " << args.at(1)
            << ")\n";
}

void gpp::Machine::set_wcs_coordinates(std::vector<f64> args) {
  int p = args.at(0);
  workOffsets[p - 1] = {args.at(1), args.at(2), args.at(3)};
  std::cout << "set_wcs_coordinates(" << p << ", " << workOffsets[p - 1].x
            << ", " << workOffsets[p - 1].y << ", " << workOffsets[p - 1].z
            << ")\n";
}

void gpp::Machine::use_workspace(std::vector<f64> args) {
  int offsetIndex = args.at(0);
  g5xoffset = workOffsets[offsetIndex - 1];

  std::cout << "use_workspace(" << offsetIndex << ")\n";
}

void gpp::Machine::set_retract_mode(std::vector<f64> args) {
  retractMode = (RetractMode)args.at(0);

  std::cout << "set_retract_mode(";
  std::cout << (retractMode == old_z ? "old_z" : "r_plane");
  std::cout << ")\n";
}

void gpp::Machine::set_motion_control_mode(std::vector<f64> args) {
  motionControlMode = (MotionControlMode)args.at(0);

  std::cout << "set_motion_control_mode(";
  std::cout << (motionControlMode == exact_stop
                    ? "exact_stop"
                    : (motionControlMode == exact_path ? "exact_path"
                                                       : "continuous"));
  std::cout << ")\n";
}

/* probably temporary */
void gpp::Machine::write_parameter_to_file(std::vector<f64> args) {
  std::cout << "write_parameter_to_file(" << args.at(0) << ")\n";
  std::ofstream file(".data.txt");
  if (!file) {
    std::cerr << "Failed to open .data.txt for writing\n";
    return;
  }

  file << "#" << args.at(0) << " = " << memory[args.at(0)] << "\n";

  file.close();
}

void gpp::Machine::write_parameters_to_file(std::vector<f64> args) {
  std::ofstream file(".data.txt");
  if (!file) {
    std::cerr << "Failed to open .data.txt for writing\n";
    return;
  }

  for (size_t i = 1; i < memory.size(); ++i) {
    file << "#" << i << " = " << memory[i] << "\n";
  }

  file.close();

  std::cout << "write_parameters_to_file()\n";
}

void gpp::Machine::enableCanvas() { canvasEnabled = true; }

void gpp::Machine::saveCanvases() {
  if (!canvasEnabled)
    return;
  canvasXY.save("output/canvas_xy.png");
  canvasYZ.save("output/canvas_yz.png");
  canvasXZ.save("output/canvas_xz.png");
}

/* helpers */

f64 gpp::Machine::unitMultiplier(Unit unit) {
  switch (unit) {
  case Unit::mm:
    return 1.0;
  case Unit::cm:
    return 10.0;
  case Unit::inch:
    return 25.4;
  }
  return 1.0; // fallback
}

const char *gpp::Machine::unitToString(Unit unit) {
  switch (unit) {
  case Unit::mm:
    return "mm";
  case Unit::cm:
    return "cm";
  case Unit::inch:
    return "in";
  }
  return "unknown";
}

void gpp::Machine::handleCSSMode() {
  if (spindleMode != constant_surface_speed)
    return;

  Vec3D pos = getLogicalPosition();

  f64 radius = 0.0;
  switch (plane) {
  case plane_xy:
    radius = std::hypot(pos.x, pos.y);
    break;
  case plane_yz:
    radius = std::hypot(pos.y, pos.z);
    break;
  case plane_xz:
    radius = std::hypot(pos.x, pos.z);
    break;
  }

  if (radius > 0.0) {
    f64 surface_speed_mm_per_min =
        rawSpindleSpeed * unitMultiplier(unit); // Convert to mm/min
    spindleSpeed = (surface_speed_mm_per_min * 1000.0) / (2.0 * M_PI * radius);
  } else {
    spindleSpeed = 0.0;
  }

  if (feedMode == units_per_revolution) {
    feedRate = rawFeedRate * spindleSpeed;
  }
}

const char *gpp::Machine::planeToString(Plane plane) {
  return plane == plane_xy ? "XY" : (plane == plane_yz ? "YZ" : "XZ");
}

gpp::Vec3D gpp::Machine::getLogicalPosition() {
  return position - g92offset - g5xoffset + Vec3D{0, 0, toolOffset};
}

gpp::Vec3D gpp::Machine::resolvePosition(const Vec3D delta) {
  if (std::isnan(delta.x) && std::isnan(delta.y) && std::isnan(delta.z))
    return position;

  Vec3D currentLogical = getLogicalPosition();
  Vec3D targetLogical = {
      std::isnan(delta.x) ? (distanceMode == relative ? 0 : currentLogical.x)
                          : delta.x,
      std::isnan(delta.y) ? (distanceMode == relative ? 0 : currentLogical.y)
                          : delta.y,
      std::isnan(delta.z) ? (distanceMode == relative ? 0 : currentLogical.z)
                          : delta.z};

  if (distanceMode == DistanceMode::relative)
    targetLogical = currentLogical + targetLogical;

  Vec3D targetMachine =
      targetLogical + g92offset + g5xoffset - Vec3D{0, 0, toolOffset};
  return targetMachine;
}

void gpp::Machine::drawLineOnPlane(Canvas &canvas, Plane plane, Vec3D from,
                                   Vec3D to) {
  if (spindleDirection == off)
    return;

  int b = spindleDirection == clockwise ? 255 : 0;

  if (plane == plane_xy)
    canvas.drawLine(from.x, from.y, to.x, to.y, 0, 0, b);
  else if (plane == plane_yz)
    canvas.drawLine(from.y, from.z, to.y, to.z, 0, 0, b);
  else if (plane == plane_xz)
    canvas.drawLine(from.x, from.z, to.x, to.z, 0, 0, b);
}

void gpp::Machine::drawLinesOnPlanes(Vec3D from, Vec3D to) {
  if (spindleDirection == off)
    return;

  int b = spindleDirection == clockwise ? 255 : 0;

  canvasXY.drawLine(from.x, from.y, to.x, to.y, 0, 0, b);
  canvasYZ.drawLine(from.y, from.z, to.y, to.z, 0, 0, b);
  canvasXZ.drawLine(from.x, from.z, to.x, to.z, 0, 0, b);
}

std::ostream &operator<<(std::ostream &os, const gpp::Tool &tool) {
  os << "[Tool]"
     << " Pocket: " << tool.pocket << ", FMS: " << tool.fms
     << ", TLO: " << tool.tlo << ", Diameter: " << tool.diam
     << ", Holder: " << tool.holder << ", Description: \"" << tool.description
     << "\"";
  return os;
}

std::ostream &operator<<(std::ostream &os, const gpp::Vec3D &v) {
  return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

gpp::Vec3D gpp::Vec3D::operator+(const Vec3D &rhs) {
  return {x + rhs.x, y + rhs.y, z + rhs.z};
}

gpp::Vec3D gpp::Vec3D::operator-(const Vec3D &rhs) {
  return {x - rhs.x, y - rhs.y, z - rhs.z};
}

gpp::Vec3D gpp::Vec3D::operator*(f64 scalar) {
  return {x * scalar, y * scalar, z * scalar};
}

bool gpp::Vec3D::operator==(const Vec3D &rhs) {
  return x == rhs.x && y == rhs.y && z == rhs.z;
}

f64 gpp::Vec3D::dot(const Vec3D &rhs) {
  return x * rhs.x + y * rhs.y + z * rhs.z;
}

gpp::Vec3D gpp::Vec3D::cross(const Vec3D &rhs) {
  return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
}

gpp::Vec2D gpp::Vec2D::operator+(const Vec2D &rhs) {
  return {x + rhs.x, y + rhs.y};
}

gpp::Vec2D gpp::Vec2D::operator-(const Vec2D &rhs) {
  return {x - rhs.x, y - rhs.y};
}

gpp::Vec2D gpp::Vec2D::operator*(f64 scalar) {
  return {x * scalar, y * scalar};
}

f64 gpp::Vec2D::dot(const Vec2D &rhs) { return x * rhs.x + y * rhs.y; }

gpp::Vec3D gpp::Vec2D::cross(const Vec2D &rhs) {
  return {0, 0, x * rhs.y - y * rhs.x};
}
