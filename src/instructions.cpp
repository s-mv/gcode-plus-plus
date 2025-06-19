#include "bytecode.hpp"
#include "machine.hpp"
#include <cmath>
#include <vector>

// I don't particularly like macros but that's life
#define GCODE_ERROR(message)                                                   \
  do {                                                                         \
    prettyPrintError(message, getLineFromSource(line), line, column);          \
    exit(0);                                                                   \
  } while (0)

#define REQUIRE_CONDITION(condition, message)                                  \
  do {                                                                         \
    if (!(condition)) {                                                        \
      GCODE_ERROR(message);                                                    \
    }                                                                          \
  } while (0)

inline void
gpp::BytecodeEmitter::extractCoordinates(const std::vector<gpp::Word> &words,
                                         f64 &x, f64 &y, f64 &z) {
  x = y = z = NAN;
  for (const gpp::Word &operand : words) {
    switch (operand.word) {
    case 'x':
      x = operand.arg;
      break;
    case 'y':
      y = operand.arg;
      break;
    case 'z':
      z = operand.arg;
      break;
    }
  }
}

inline void
gpp::BytecodeEmitter::extractArcParams(const std::vector<Word> &words, f64 &x,
                                       f64 &y, f64 &z, f64 &i, f64 &j, f64 &k,
                                       f64 &r) {
  x = y = z = i = j = k = r = NAN;
  for (const gpp::Word &operand : words) {
    switch (operand.word) {
    case 'x':
      x = operand.arg;
      break;
    case 'y':
      y = operand.arg;
      break;
    case 'z':
      z = operand.arg;
      break;
    case 'i':
      i = operand.arg;
      break;
    case 'j':
      j = operand.arg;
      break;
    case 'k':
      k = operand.arg;
      break;
    case 'r':
      r = operand.arg;
      break;
    }
  }
}

inline f64 gpp::BytecodeEmitter::findParameter(const std::vector<Word> &words,
                                               char letter) {
  for (const gpp::Word &operand : words) {
    if (operand.word == letter) {
      return operand.arg;
    }
  }
  return NAN;
}

inline void gpp::BytecodeEmitter::applyCurrentPositionDefaults(Vec3D &delta) {
  auto pos = machine->getLogicalPosition();
  if (std::isnan(delta.x))
    delta.x = pos.x;
  if (std::isnan(delta.y))
    delta.y = pos.y;
  if (std::isnan(delta.z))
    delta.z = pos.z;
}

inline gpp::Vec2D gpp::BytecodeEmitter::getPlaneCoordinates(const Plane plane,
                                                            const Vec3D &pos) {
  switch (plane) {
  case gpp::plane_xy:
    return {pos.x, pos.y};
  case gpp::plane_yz:
    return {pos.y, pos.z};
  case gpp::plane_xz:
    return {pos.z, pos.x};
  }
  return {0, 0}; // fallback
}

inline gpp::Vec2D
gpp::BytecodeEmitter::getCurrentPlanePosition(const Plane plane,
                                              const Vec3D &position) {
  return getPlaneCoordinates(plane, position);
}

inline gpp::Vec2D
gpp::BytecodeEmitter::getArcCenterOffsets(const gpp::Plane plane, f64 i, f64 j,
                                          f64 k) {
  switch (plane) {
  case gpp::plane_xy:
    return {i, j};
  case gpp::plane_yz:
    return {j, k};
  case gpp::plane_xz:
    return {k, i};
  }
  return {0, 0}; // fallback
}

#define SIMPLE_MCODE_CASE(code, cmd)                                           \
  case code:                                                                   \
    list.push_back({.word = 'm',                                               \
                    .arg = code,                                               \
                    .commentOrMessage = false,                                 \
                    .command = {.command = cmd}});                             \
    break;

#define SINGLE_ARG_GCODE_CASE(code, cmd, arg_val)                              \
  case code:                                                                   \
    list.push_back({.word = 'g',                                               \
                    .arg = code,                                               \
                    .commentOrMessage = false,                                 \
                    .command = {.command = cmd, .arguments = {arg_val}}});     \
    break;

void gpp::BytecodeEmitter::handle_g(std::vector<VerboseInstruction> &list,
                                    f64 arg,
                                    const std::vector<gpp::Word> &words,
                                    int line, int column) {
  switch (static_cast<int>(arg)) {
  case 0:
  case 1:
  case 92: {
    Vec3D delta;
    this->extractCoordinates(words, delta.x, delta.y, delta.z);
    this->applyCurrentPositionDefaults(delta);

    Command command = (arg == 0)   ? move_rapid
                      : (arg == 1) ? move_linear
                                   : set_origin_offsets;

    list.push_back({.word = 'g',
                    .arg = arg,
                    .commentOrMessage = false,
                    .command = {.command = command,
                                .arguments = {delta.x, delta.y, delta.z}}});

    break;
  }

  case 2:
  case 3: {
    Vec3D delta;
    f64 i, j, k, r;
    this->extractArcParams(words, delta.x, delta.y, delta.z, i, j, k, r);

    REQUIRE_CONDITION(machine->feedRate != 0,
                      "Feed rate should be non-zero for feed_arc to run!");

    REQUIRE_CONDITION(std::isnan(r) ||
                          (std::isnan(i) && std::isnan(j) && std::isnan(k)),
                      "Both r and i/j/k are defined!");

    REQUIRE_CONDITION(
        arcOffetsAligned(machine->plane, i, j, k),
        std::string("Arc isn't aligned to the current plane, i.e. the ") +
            machine->planeToString(machine->plane) + " plane.");

    this->applyCurrentPositionDefaults(delta);
    if (std::isnan(i))
      i = 0;
    if (std::isnan(j))
      j = 0;
    if (std::isnan(k))
      k = 0;

    int rotation = (arg == 2) ? 1 : -1;

    gpp::Vec2D currentPos =
        this->getCurrentPlanePosition(machine->plane, machine->position);
    gpp::Vec2D targetPos = this->getPlaneCoordinates(machine->plane, delta);
    gpp::Vec2D center;

    if (!std::isnan(r)) {
      gpp::Vec2D delta = targetPos - currentPos;
      f64 len = sqrt(delta.dot(delta));

      REQUIRE_CONDITION(len <= 2 * r, "Radius too small for arc!");

      gpp::Vec2D midpoint = (currentPos + targetPos) * 0.5;
      f64 h = sqrt(r * r - (len * len) / 4.0);
      gpp::Vec2D perpendicular = {-delta.y, delta.x};

      f64 perpendicularLen = sqrt(perpendicular.x * perpendicular.x +
                                  perpendicular.y * perpendicular.y);
      REQUIRE_CONDITION(
          perpendicularLen != 0,
          "Invalid arc calculation: zero-length perpendicular vector.");

      perpendicular = perpendicular * (1.0 / perpendicularLen);
      center = midpoint + perpendicular * h * rotation;
    } else {
      gpp::Vec2D offset = this->getArcCenterOffsets(machine->plane, i, j, k);
      center = currentPos + offset;
    }

    list.push_back(
        {.word = 'g',
         .arg = arg,
         .commentOrMessage = false,
         .command = {.command = arc_feed,
                     .arguments = {targetPos.x, targetPos.y, center.x, center.y,
                                   static_cast<f64>(rotation), delta.z}}});

    break;
  }

  case 4: {
    f64 p = this->findParameter(words, 'p');
    REQUIRE_CONDITION(!std::isnan(p),
                      "Missing dwell time (p<>) with signature.");

    list.push_back({.word = 'g',
                    .arg = arg,
                    .commentOrMessage = false,
                    .command = {.command = dwell, .arguments = {p}}});
    break;
  }
  case 10: {
    f64 l = this->findParameter(words, 'l');
    f64 p = this->findParameter(words, 'p');
    f64 x, y, z;
    this->extractCoordinates(words, x, y, z);
    if (std::isnan(x))
      x = 0;
    if (std::isnan(y))
      y = 0;
    if (std::isnan(z))
      z = 0;

    if (l == 1) {
      list.push_back({.word = 'g',
                      .arg = arg,
                      .commentOrMessage = false,
                      .command = {.command = set_tool_length_offset,
                                  .arguments = {p, z}}});
    } else if (l == 2) {
      int pi = static_cast<int>(p);
      REQUIRE_CONDITION(pi >= 1 && pi <= 6, "Invalid coordinate system number");

      list.push_back({.word = 'g',
                      .arg = arg,
                      .commentOrMessage = false,
                      .command = {.command = set_wcs_coordinates,
                                  .arguments = {p, x, y, z}}});
    } else if (l == 20) {
      // TODO

      list.push_back({.word = 'g',
                      .arg = arg,
                      .commentOrMessage = false,
                      .command = {.command = no_command}});
    }

    break;
  }

    SINGLE_ARG_GCODE_CASE(17, select_plane, plane_xy);
    SINGLE_ARG_GCODE_CASE(18, select_plane, plane_yz);
    SINGLE_ARG_GCODE_CASE(19, select_plane, plane_xz);
    SINGLE_ARG_GCODE_CASE(20, use_length_units, Unit::inch);
    SINGLE_ARG_GCODE_CASE(21, use_length_units, Unit::mm);
    SINGLE_ARG_GCODE_CASE(90, use_distance_mode, absolute);
    SINGLE_ARG_GCODE_CASE(91, use_distance_mode, relative);

  case 43: {
    f64 h = this->findParameter(words, 'h');

    // this assumes that the tool changer is non-random
    if (h == 0 || std::isnan(h))
      h = machine->currentTool;

    h = machine->tools.at(h).tlo;

    list.push_back(
        {.word = 'g',
         .arg = arg,
         .commentOrMessage = false,
         .command = {.command = use_tool_length_offset, .arguments = {h}}});

    break;
  }

  default:
    if (arg >= 54 && arg <= 59) {
      list.push_back(
          {.word = 'g',
           .arg = arg,
           .commentOrMessage = false,
           .command = {.command = use_workspace, .arguments = {arg - 53}}});
    }
    break;
  }
}

void gpp::BytecodeEmitter::handle_m(std::vector<VerboseInstruction> &list,
                                    f64 arg,
                                    const std::vector<gpp::Word> &words,
                                    int line, int column) {
  int m_code = static_cast<int>(arg);

  switch (m_code) {
    SIMPLE_MCODE_CASE(0, program_stop);
    SIMPLE_MCODE_CASE(1, optional_program_stop);
    SIMPLE_MCODE_CASE(2, program_end);
    SIMPLE_MCODE_CASE(3, start_spindle_clockwise);
    SIMPLE_MCODE_CASE(4, start_spindle_counterclockwise);
    SIMPLE_MCODE_CASE(5, stop_spindle_turning);
    SIMPLE_MCODE_CASE(6, change_tool);
    SIMPLE_MCODE_CASE(100, write_parameters_to_file);

  default:
    if (m_code > 100) {
      list.push_back({.word = 'm',
                      .arg = arg,
                      .commentOrMessage = false,
                      .command = {.command = write_parameter_to_file,
                                  .arguments = {arg - 100}}});
    }
    break;
  }
}
