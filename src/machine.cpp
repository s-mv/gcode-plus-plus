#include "machine.hpp"

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "canvas.hpp"
#include "gpp.hpp"
#include "util.hpp"

/// helper
gpp::Machine::Machine(std::string input)
    : input(input), emitter(input), canvasXY(512, 512), canvasYZ(512, 512),
      canvasXZ(512, 512) {
  this->position = (Vec3D){0, 0, 0};
  this->g92offset = (Vec3D){0, 0, 0};
  this->unit = Unit::mm;
  this->distanceMode = absolute;
  this->plane = plane_xy;
  this->feedRate = 0;
  this->spindleDirection = off;
  this->spindleSpeed = 0;
  this->emitter.machine = this;
  initTools("config/tools.txt");

  std::cout << "Initialized machine!\n";
  // printSpecs();

  handlers[Command::move_linear] =
      std::bind(&gpp::Machine::move_linear, this, std::placeholders::_1);
  handlers[Command::move_rapid] =
      std::bind(&gpp::Machine::move_rapid, this, std::placeholders::_1);
  handlers[Command::set_feed_rate] =
      std::bind(&gpp::Machine::set_feed_rate, this, std::placeholders::_1);
  handlers[Command::use_length_units] =
      std::bind(&gpp::Machine::use_length_units, this, std::placeholders::_1);
  handlers[Command::use_distance_mode] =
      std::bind(&gpp::Machine::use_distance_mode, this, std::placeholders::_1);
  handlers[Command::select_plane] =
      std::bind(&gpp::Machine::select_plane, this, std::placeholders::_1);
  handlers[Command::arc_feed] =
      std::bind(&gpp::Machine::arc_feed, this, std::placeholders::_1);

  handlers[Command::dwell] =
      std::bind(&gpp::Machine::dwell, this, std::placeholders::_1);
  handlers[Command::set_origin_offsets] =
      std::bind(&gpp::Machine::set_origin_offsets, this, std::placeholders::_1);

  handlers[Command::start_spindle_clockwise] = std::bind(
      &gpp::Machine::start_spindle_clockwise, this, std::placeholders::_1);
  handlers[Command::start_spindle_counterclockwise] =
      std::bind(&gpp::Machine::start_spindle_counterclockwise, this,
                std::placeholders::_1);
  handlers[Command::stop_spindle_turning] = std::bind(
      &gpp::Machine::stop_spindle_turning, this, std::placeholders::_1);
  handlers[Command::set_spindle_speed] =
      std::bind(&gpp::Machine::set_spindle_speed, this, std::placeholders::_1);

  handlers[Command::select_tool] =
      std::bind(&gpp::Machine::select_tool, this, std::placeholders::_1);
  handlers[Command::change_tool] =
      std::bind(&gpp::Machine::change_tool, this, std::placeholders::_1);

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

gpp::Instruction gpp::Machine::next() {
  Instruction instruction = emitter.next();

  if (instruction.command == no_command)
    return instruction;

  handlers[instruction.command](instruction.arguments);

  if (spindleDirection != off)
    saveCanvases();

  return instruction;
}

void gpp::Machine::printSpecs() {}

void gpp::Machine::initTools(std::string file) {
  tools = {};

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
    tools.push_back(tool);
  }
}

void gpp::Machine::move_linear(std::vector<f64> args) {
  Vec3D prev = position;
  position = resolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_linear(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";

  drawLinesOnPlanes(prev, position);
}

void gpp::Machine::move_rapid(std::vector<f64> args) {
  Vec3D prev = position;
  position = resolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_rapid(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";

  drawLinesOnPlanes(prev, position);
}

void gpp::Machine::set_feed_rate(std::vector<f64> args) {
  feedRate = args.at(0);
  std::cout << "set_feed_rate(" << feedRate << ")\n";
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

  std::cout << "use_length_units(";
  std::cout << plane;
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
                 ? resolvePosition(first_end, second_end, axis_end_point)
             : plane == plane_yz
                 ? resolvePosition(axis_end_point, first_end, second_end)
                 : resolvePosition(first_end, axis_end_point, second_end);

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

  std::cout << "set_origin_offsets(" << g92offset.x << ", " << g92offset.y
            << ", " << g92offset.z << ")\n";
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
  spindleSpeed = args.at(0);
  std::cout << "set_spindle_speed(" << spindleSpeed << ")\n";
}

void gpp::Machine::select_tool(std::vector<f64> args) {
  selectedTool = args.at(0);
  std::cout << "select_tool(" << selectedTool << ")\n";
}

void gpp::Machine::change_tool(std::vector<f64> args) {
  currentTool = selectedTool;
  std::cout << "change_tool(" << currentTool << ")\n";
}

void gpp::Machine::program_stop(std::vector<f64> args) {
  std::cout << "program_stop()\n";
}

void gpp::Machine::optional_program_stop(std::vector<f64> args) {
  std::cout << "optional_program_stop()\n";
}

void gpp::Machine::program_end(std::vector<f64> args) {
  set_origin_offsets({0, 0, 0});
  stop_spindle_turning({});

  std::cout << "program_end()\n";
}

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
  std::cout << "write_parameters_to_file(";

  std::ofstream file(".data.txt");
  if (!file) {
    std::cerr << "Failed to open .data.txt for writing\n";
    return;
  }

  for (size_t i = 1; i < memory.size(); ++i) {
    file << "#" << i << " = " << memory[i] << "\n";
  }

  file.close();

  std::cout << ")\n";
}

void gpp::Machine::saveCanvases() {
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

const char *gpp::Machine::planeToString(Plane plane) {
  return plane == plane_xy ? "XY" : (plane == plane_yz ? "YZ" : "XZ");
}

gpp::Vec3D gpp::Machine::resolvePosition(const f64 x, const f64 y,
                                         const f64 z) {
  if (std::isnan(x) && std::isnan(y) && std::isnan(z))
    ; // TODO, error handling and handling individual axes

  Vec3D delta = {x, y, z};
  delta = delta * unitMultiplier(unit);

  if (distanceMode == DistanceMode::relative)
    return position + delta;
  else {
    return g92offset + delta;
  }
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
  canvasYZ.drawLine(from.x, from.z, to.x, to.z, 0, 0, b);
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
