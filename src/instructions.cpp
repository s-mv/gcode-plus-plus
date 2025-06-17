#include "bytecode.hpp"
#include "machine.hpp"
#include <cmath>

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

inline void extractCoordinates(const std::vector<gpp::Word> &words, f64 &x,
                               f64 &y, f64 &z) {
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

inline void extractArcParams(const std::vector<gpp::Word> &words, f64 &x,
                             f64 &y, f64 &z, f64 &i, f64 &j, f64 &k, f64 &r) {
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

inline f64 findParameter(const std::vector<gpp::Word> &words, char letter) {
  for (const gpp::Word &operand : words) {
    if (operand.word == letter) {
      return operand.arg;
    }
  }
  return NAN;
}

inline void applyCurrentPositionDefaults(f64 &x, f64 &y, f64 &z,
                                         const gpp::Vec3D position) {
  if (std::isnan(x))
    x = position.x;
  if (std::isnan(y))
    y = position.y;
  if (std::isnan(z))
    z = position.z;
}

inline void getPlaneCoordinates(const gpp::Plane plane, f64 x, f64 y, f64 z,
                                f64 &x_plane, f64 &y_plane, f64 &z_plane) {
  switch (plane) {
  case gpp::plane_xy:
    x_plane = x;
    y_plane = y;
    z_plane = z;
    break;
  case gpp::plane_yz:
    x_plane = y;
    y_plane = z;
    z_plane = x;
    break;
  case gpp::plane_xz:
    x_plane = z;
    y_plane = x;
    z_plane = y;
    break;
  }
}

inline void getCurrentPlanePosition(const gpp::Plane plane, f64 &x0, f64 &y0,
                                    const gpp::Vec3D position) {
  switch (plane) {
  case gpp::plane_xy:
    x0 = position.x;
    y0 = position.y;
    break;
  case gpp::plane_yz:
    x0 = position.y;
    y0 = position.z;
    break;
  case gpp::plane_xz:
    x0 = position.z;
    y0 = position.x;
    break;
  }
}

inline void getArcCenterOffsets(const gpp::Plane plane, f64 i, f64 j, f64 k,
                                f64 &offset_x, f64 &offset_y) {
  switch (plane) {
  case gpp::plane_xy:
    offset_x = i;
    offset_y = j;
    break;
  case gpp::plane_yz:
    offset_x = j;
    offset_y = k;
    break;
  case gpp::plane_xz:
    offset_x = k;
    offset_y = i;
    break;
  }
}

#define SIMPLE_GCODE_CASE(code, cmd)                                           \
  case code:                                                                   \
    return {.command = cmd};

#define SINGLE_ARG_GCODE_CASE(code, cmd, arg_val)                              \
  case code:                                                                   \
    return {.command = cmd, .arguments = {arg_val}};

gpp::Instruction
gpp::BytecodeEmitter::handle_g(f64 arg, const std::vector<gpp::Word> &words,
                               int line, int column) {
  switch (static_cast<int>(arg)) {
  case 0:
  case 1:
  case 92: {
    f64 x, y, z;
    extractCoordinates(words, x, y, z);
    if (std::isnan(x))
      x = machine->position.x;
    if (std::isnan(y))
      y = machine->position.y;
    if (std::isnan(z))
      z = machine->position.z;

    Command command = (arg == 0)   ? move_rapid
                      : (arg == 1) ? move_linear
                                   : set_origin_offsets;

    return {.command = command, .arguments = {x, y, z}};
  }

  case 2:
  case 3: {
    f64 x, y, z, i, j, k, r;
    extractArcParams(words, x, y, z, i, j, k, r);

    REQUIRE_CONDITION(machine->feedRate != 0,
                      "Feed rate should be non-zero for feed_arc to run!");

    REQUIRE_CONDITION(std::isnan(r) ||
                          (std::isnan(i) && std::isnan(j) && std::isnan(k)),
                      "Both r and i/j/k are defined!");

    REQUIRE_CONDITION(
        arcOffetsAligned(machine->plane, i, j, k),
        std::string("Arc isn't aligned to the current plane, i.e. the ") +
            machine->planeToString(machine->plane) + " plane.");

    applyCurrentPositionDefaults(x, y, z, machine->position);
    if (std::isnan(i))
      i = 0;
    if (std::isnan(j))
      j = 0;
    if (std::isnan(k))
      k = 0;

    f64 x0, y0, x1, y1, xc, yc, z2;
    int rotation = (arg == 2) ? 1 : -1;

    getCurrentPlanePosition(machine->plane, x0, y0, machine->position);
    getPlaneCoordinates(machine->plane, x, y, z, x1, y1, z2);

    Vec2D a = {x0, y0};
    Vec2D b = {x1, y1};

    if (!std::isnan(r)) {
      Vec2D delta = b - a;
      f64 len = sqrt(delta.dot(delta));

      REQUIRE_CONDITION(len <= 2 * r, "Radius too small for arc!");

      Vec2D midpoint = (a + b) * 0.5;
      f64 h = sqrt(r * r - (len * len) / 4.0);
      Vec2D perpendicular = {-delta.y, delta.x};

      f64 perpendicularLen = sqrt(perpendicular.x * perpendicular.x +
                                  perpendicular.y * perpendicular.y);
      REQUIRE_CONDITION(
          perpendicularLen != 0,
          "Invalid arc calculation: zero-length perpendicular vector.");

      perpendicular.x /= perpendicularLen;
      perpendicular.y /= perpendicularLen;

      Vec2D center = midpoint + perpendicular * h * rotation;
      xc = center.x;
      yc = center.y;
    } else {
      f64 offset_x, offset_y;
      getArcCenterOffsets(machine->plane, i, j, k, offset_x, offset_y);
      xc = x0 + offset_x;
      yc = y0 + offset_y;
    }

    return {.command = arc_feed,
            .arguments = {x1, y1, xc, yc, static_cast<f64>(rotation), z2}};
  }

  case 4: {
    f64 p = findParameter(words, 'p');
    REQUIRE_CONDITION(!std::isnan(p),
                      "Missing dwell time (p<>) with signature.");
    return {.command = dwell, .arguments = {p}};
  }

  case 10: {
    f64 l = findParameter(words, 'l');
    f64 p = findParameter(words, 'p');
    f64 x, y, z;
    extractCoordinates(words, x, y, z);
    if (std::isnan(x))
      x = 0;
    if (std::isnan(y))
      y = 0;
    if (std::isnan(z))
      z = 0;

    if (l == 1) {
      return {.command = set_tool_length_offset, .arguments = {p, z}};
    } else if (l == 2) {
      int pi = static_cast<int>(p);
      REQUIRE_CONDITION(pi >= 1 && pi <= 6, "Invalid coordinate system number");
      return {.command = set_wcs_coordinates, .arguments = {p, x, y, z}};
    } else if (l == 20) {
      // TODO
      return {.command = no_command};
    }
    break;
  }

    SINGLE_ARG_GCODE_CASE(17, select_plane, plane_xy)
    SINGLE_ARG_GCODE_CASE(18, select_plane, plane_yz)
    SINGLE_ARG_GCODE_CASE(19, select_plane, plane_xz)
    SINGLE_ARG_GCODE_CASE(20, use_length_units, Unit::inch)
    SINGLE_ARG_GCODE_CASE(21, use_length_units, Unit::mm)
    SINGLE_ARG_GCODE_CASE(90, use_distance_mode, absolute)
    SINGLE_ARG_GCODE_CASE(91, use_distance_mode, relative)

  case 43: {
    f64 h = findParameter(words, 'h');
    REQUIRE_CONDITION(!std::isnan(h), "Missing offset index (h<>).");
    return {.command = use_tool_length_offset, .arguments = {h}};
  }

  default:
    if (arg >= 54 && arg <= 59) {
      return {.command = use_workspace, .arguments = {arg - 53}};
    }
    break;
  }

  return {.command = no_command};
}

gpp::Instruction
gpp::BytecodeEmitter::handle_m(f64 arg, const std::vector<gpp::Word> &words,
                               int line, int column) {
  int m_code = static_cast<int>(arg);

  switch (m_code) {
    SIMPLE_GCODE_CASE(0, program_stop)
    SIMPLE_GCODE_CASE(1, optional_program_stop)
    SIMPLE_GCODE_CASE(2, program_end)
    SIMPLE_GCODE_CASE(3, start_spindle_clockwise)
    SIMPLE_GCODE_CASE(4, start_spindle_counterclockwise)
    SIMPLE_GCODE_CASE(5, stop_spindle_turning)
    SIMPLE_GCODE_CASE(6, change_tool)
    SIMPLE_GCODE_CASE(100, write_parameters_to_file)

  default:
    if (m_code > 100) {
      return {.command = write_parameter_to_file, .arguments = {arg - 100}};
    }
    break;
  }

  return {.command = no_command};
}