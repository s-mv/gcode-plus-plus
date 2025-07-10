#include <algorithm>
#include <cmath>
#include <vector>

#include "bytecode.hpp"
#include "gpp.hpp"
#include "machine.hpp"

#define GCODE_ERROR(message, source)                                           \
  do {                                                                         \
    emitter.bytecode.push_back(                                                \
        gpp::Error(ErrorType::GENERAL_ERROR, message, source, line, column));  \
    return;                                                                    \
  } while (0)

#define EXTRACT_CANNED_CYCLE_PARAMS()                                          \
  f64 x, y, z;                                                                 \
  f64 r = emitter.findParameter(words, 'r');                                   \
  f64 l_real = emitter.findParameter(words, 'l');                              \
  emitter.extractCoordinates(words, x, y, z);                                  \
  r *= unitMultiplier(unit);                                                   \
  if (std::isnan(l_real))                                                      \
    l_real = 1;                                                                \
  int l = static_cast<int>(l_real);

#define VALIDATE_CANNED_CYCLE_PARAMS(cycle_num)                                \
  do {                                                                         \
    REQUIRE_CONDITION(feedRate > 0, gpp::ErrorType::MACHINE_ERROR,             \
                      "Feed rate must be set before G" +                       \
                          std::to_string(cycle_num) + " is used!",             \
                      'g');                                                    \
    REQUIRE_CONDITION(!std::isnan(z), gpp::ErrorType::PARAMETER_ERROR,         \
                      "Missing Z<> for G" + std::to_string(cycle_num) + "!",   \
                      'g');                                                    \
    REQUIRE_CONDITION(!std::isnan(r), gpp::ErrorType::PARAMETER_ERROR,         \
                      "Missing R<> for G" + std::to_string(cycle_num) + "!",   \
                      'g');                                                    \
  } while (0)

#define SETUP_CANNED_CYCLE_POSITION()                                          \
  Vec3D current = getLogicalPosition();                                        \
  Vec3D target_position = {x, y, z};                                           \
  if (std::isnan(x))                                                           \
    x = current.x;                                                             \
  if (std::isnan(y))                                                           \
    y = current.y;                                                             \
  f64 old_z = current.z;                                                       \
  f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

#define MOVE_TO_RETRACT_PLANE()                                                \
  if (distanceMode == absolute) {                                              \
    if (old_z < r) {                                                           \
      emitter.bytecode.push_back(                                              \
          Instruction{.command = gpp::move_rapid,                              \
                      .arguments = {current.x, current.y, r}});                \
      current.z = r;                                                           \
    }                                                                          \
  } else {                                                                     \
    if (r > 0) {                                                               \
      emitter.bytecode.push_back(                                              \
          Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});    \
      current.z = r;                                                           \
    }                                                                          \
  }

#define FINAL_RETRACT_MOVE()                                                   \
  if (distanceMode == absolute) {                                              \
    emitter.bytecode.push_back(Instruction{                                    \
        .command = gpp::move_rapid,                                            \
        .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});        \
  } else {                                                                     \
    emitter.bytecode.push_back(Instruction{                                    \
        .command = gpp::move_rapid,                                            \
        .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});    \
  }

#define REQUIRE_CONDITION(condition, error_type, message, word_)               \
  do {                                                                         \
    if (!(condition)) {                                                        \
      gpp::VerboseInstruction vInst = emitter.verboseInstructions.front();     \
      if (vInst.line == -1)                                                    \
        vInst.line = emitter.line;                                             \
      if (vInst.column == -1)                                                  \
        vInst.column = emitter.column;                                         \
      emitter.bytecode.push_back(gpp::Error(                                   \
          error_type, message, emitter.getLineFromSource(vInst.line),          \
          vInst.line, vInst.column));                                          \
      return;                                                                  \
    }                                                                          \
  } while (0)

#define PUSH_INSTR(letter, value, is_msg, cmd, ...)                            \
  list.push_back({.word = letter,                                              \
                  .arg = value,                                                \
                  .commentOrMessage = is_msg,                                  \
                  .command = {.command = cmd, .arguments = {__VA_ARGS__}}})

#define SIMPLE_MCODE_CASE(code, cmd)                                           \
  case code:                                                                   \
    PUSH_INSTR('m', code, false, cmd);                                         \
    break;

#define SINGLE_ARG_GCODE_CASE(code, cmd, arg_val)                              \
  case code:                                                                   \
    PUSH_INSTR('g', code, false, cmd, arg_val);                                \
    break;

inline void
gpp::BytecodeEmitter::extractCoordinates(const std::vector<gpp::Word> &words,
                                         f64 &x, f64 &y, f64 &z) {
  x = y = z = NAN;
  for (const gpp::Word &operand : words) {
    switch (operand.word) {
    case 'x':
      x = operand.arg * machine->unitMultiplier(machine->unit);
      break;
    case 'y':
      y = operand.arg * machine->unitMultiplier(machine->unit);
      break;
    case 'z':
      z = operand.arg * machine->unitMultiplier(machine->unit);
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

f64 gpp::BytecodeEmitter::findParameter(const std::vector<Word> &words,
                                        char letter) {
  for (const gpp::Word &operand : words) {
    if (operand.word == letter) {
      return operand.arg;
    }
  }
  return NAN;
}

inline void gpp::BytecodeEmitter::applyCurrentPositionDefaults(Vec3D &delta) {
  if (machine->distanceMode == relative) {
    if (std::isnan(delta.x))
      delta.x = 0;
    if (std::isnan(delta.y))
      delta.y = 0;
    if (std::isnan(delta.z))
      delta.z = 0;

    return;
  }

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

void gpp::BytecodeEmitter::handle_g(std::deque<VerboseInstruction> &list,
                                    f64 arg,
                                    const std::vector<gpp::Word> &words,
                                    int line, int column) {
  VerboseInstruction verboseInstruction = {
      .word = 'g',
      .arg = arg,
      .line = line,
      .column = column,
      .commentOrMessage = false,
      .instruction = Instruction{.command = no_command}};

  if ((0 <= arg && arg <= 3) || (81 <= arg && arg <= 89))
    stickyArgs.g = arg;

  list.push_back(verboseInstruction);
}

void gpp::BytecodeEmitter::handle_m(std::deque<VerboseInstruction> &list,
                                    f64 arg,
                                    const std::vector<gpp::Word> &words,
                                    int line, int column) {
  VerboseInstruction verboseInstruction = {
      .word = 'm',
      .arg = arg,
      .commentOrMessage = false,
      .instruction = Instruction{.command = no_command}};

  list.push_back(verboseInstruction);
}

void gpp::Machine::handle_g(std::deque<gpp::VerboseInstruction> &list, f64 arg,
                            const std::vector<Word> &words, int line,
                            int column) {
  int arg_i = static_cast<int>(arg);

  switch (arg_i) {
  case 0:
  case 1:
  case 92: {
    Vec3D delta;
    emitter.extractCoordinates(words, delta.x, delta.y, delta.z);

    REQUIRE_CONDITION(
        !(std::isnan(delta.x) && std::isnan(delta.y) && std::isnan(delta.z)),
        ErrorType::PARAMETER_ERROR,
        "All axes missing for G" + std::to_string(arg_i) + "!", 'g');

    emitter.applyCurrentPositionDefaults(delta);

    Command command = (arg == 0)   ? gpp::move_rapid
                      : (arg == 1) ? gpp::move_linear
                                   : gpp::set_origin_offsets;

    emitter.bytecode.push_back(Instruction{
        .command = command, .arguments = {delta.x, delta.y, delta.z}});
    break;
  }

  case 2:
  case 3: {
    Vec3D delta;
    f64 i, j, k, r;
    emitter.extractArcParams(words, delta.x, delta.y, delta.z, i, j, k, r);

    REQUIRE_CONDITION(feedRate != 0, ErrorType::MACHINE_ERROR,
                      "Feed rate should be non-zero for feed_arc to run!", 'g');

    const bool both_defined =
        !std::isnan(r) && (!std::isnan(i) || !std::isnan(j) || !std::isnan(k));

    REQUIRE_CONDITION(!both_defined, ErrorType::PARAMETER_ERROR,
                      "Both r and i/j/k are defined!", 'r');

    REQUIRE_CONDITION(
        !(std::isnan(r) && std::isnan(i) && std::isnan(j) && std::isnan(k)),
        ErrorType::PARAMETER_ERROR, "Neither r not i/j/k are defined!", 'g');

    REQUIRE_CONDITION(!(!std::isnan(i) && !std::isnan(j) && !std::isnan(k)),
                      ErrorType::PARAMETER_ERROR,
                      "All of i, j and k are defined!", 'i');

    REQUIRE_CONDITION(
        !(std::isnan(delta.x) && std::isnan(delta.y) && std::isnan(delta.z)),
        ErrorType::PARAMETER_ERROR, "No axes mentioned (x/y/z).", 'g');

    REQUIRE_CONDITION(
        emitter.arcOffetsAligned(plane, i, j, k), ErrorType::MACHINE_ERROR,
        std::string("Arc isn't aligned to the current plane, i.e. the ") +
            planeToString(plane) + " plane.",
        'g');

    emitter.applyCurrentPositionDefaults(delta);
    if (std::isnan(i))
      i = 0;
    if (std::isnan(j))
      j = 0;
    if (std::isnan(k))
      k = 0;

    int rotation = (arg == 2) ? 1 : -1;

    gpp::Vec2D currentPos = emitter.getCurrentPlanePosition(plane, position);
    gpp::Vec2D targetPos = emitter.getPlaneCoordinates(plane, delta);
    gpp::Vec2D center;

    if (!std::isnan(r)) {
      gpp::Vec2D delta = targetPos - currentPos;
      f64 len = sqrt(delta.dot(delta));

      REQUIRE_CONDITION(r > 0, ErrorType::PARAMETER_ERROR,
                        "Radius must be positive!", 'r');

      REQUIRE_CONDITION(len <= 2 * r, ErrorType::PARAMETER_ERROR,
                        "Radius too small for arc!", 'r');

      gpp::Vec2D midpoint = (currentPos + targetPos) * 0.5;
      f64 h = sqrt(r * r - (len * len) / 4.0);
      gpp::Vec2D perpendicular = {-delta.y, delta.x};

      f64 perpendicularLen = sqrt(perpendicular.x * perpendicular.x +
                                  perpendicular.y * perpendicular.y);
      REQUIRE_CONDITION(
          perpendicularLen != 0, ErrorType::PARAMETER_ERROR,
          "Invalid arc calculation: zero-length perpendicular vector.", 'r');

      perpendicular = perpendicular * (1.0 / perpendicularLen);
      center = midpoint + perpendicular * h * rotation;
    } else {
      REQUIRE_CONDITION(!(i == 0 && j == 0 && k == 0),
                        ErrorType::PARAMETER_ERROR,
                        "All of i, j and k are zero!", 'g');

      gpp::Vec2D offset = emitter.getArcCenterOffsets(plane, i, j, k);

      center = currentPos + offset;
    }

    activeInstruction = {
        .word = 'g',
        .arg = arg,
        .commentOrMessage = false,
        .instruction = Instruction{
            .command = gpp::arc_feed,
            .arguments = {targetPos.x, targetPos.y, center.x, center.y,
                          static_cast<f64>(rotation), delta.z}}};

    emitter.bytecode.push_back(activeInstruction.instruction);
    break;
  }

  case 4: {
    f64 p = emitter.findParameter(words, 'p');
    emitter.bytecode.push_back(
        Instruction{.command = gpp::dwell, .arguments = {p}});
    break;
  }

  case 10: {
    f64 l = emitter.findParameter(words, 'l');
    f64 p = emitter.findParameter(words, 'p');
    f64 x, y, z;
    emitter.extractCoordinates(words, x, y, z);
    if (std::isnan(x))
      x = 0;
    if (std::isnan(y))
      y = 0;
    if (std::isnan(z))
      z = 0;

    if (l == 1) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::set_tool_length_offset, .arguments = {p, z}});
    } else if (l == 2) {
      int pi = static_cast<int>(p);
      REQUIRE_CONDITION(pi >= 1 && pi <= 6, ErrorType::PARAMETER_ERROR,
                        "Invalid coordinate system number", 'l');

      emitter.bytecode.push_back(Instruction{
          .command = gpp::set_wcs_coordinates, .arguments = {p, x, y, z}});
    }
    break;
  }

  case 17:
    emitter.bytecode.push_back(
        Instruction{.command = gpp::select_plane, .arguments = {plane_xy}});
    break;
  case 18:
    emitter.bytecode.push_back(
        Instruction{.command = gpp::select_plane, .arguments = {plane_xz}});
    break;
  case 19:
    emitter.bytecode.push_back(
        Instruction{.command = gpp::select_plane, .arguments = {plane_yz}});
    break;
  case 20:
    emitter.bytecode.push_back(Instruction{.command = gpp::use_length_units,
                                           .arguments = {Unit::inch}});
    break;
  case 21:
    emitter.bytecode.push_back(
        Instruction{.command = gpp::use_length_units, .arguments = {Unit::mm}});
    break;

  case 43: {
    f64 h = emitter.findParameter(words, 'h');

    if (h == 0 || std::isnan(h))
      h = currentTool;

    REQUIRE_CONDITION(tools.find(h) != tools.end(), ErrorType::MACHINE_ERROR,
                      "Tool ID T" + std::to_string(h) + " not defined.", 'g');

    h = tools.at(h).tlo;

    emitter.bytecode.push_back(
        Instruction{.command = gpp::use_tool_length_offset, .arguments = {h}});
    break;
  }

  case 80: {
    emitter.stickyArgs.g = NAN;
    break;
  }

  case 81:
  case 82: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(arg_i);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');

    if (arg_i == 82)
      REQUIRE_CONDITION(!std::isnan(p) && p >= 0, ErrorType::PARAMETER_ERROR,
                        "Invalid P<> value for G82!", 'g');

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {x, y, current.z}});

        if (current.z != r)
          emitter.bytecode.push_back(
              Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        if (arg_i == 82)
          emitter.bytecode.push_back(
              Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        if (arg_i == 82)
          emitter.bytecode.push_back(
              Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {0, 0, r - z}});
      }
    }

    FINAL_RETRACT_MOVE();
    break;
  }

  case 83: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(83);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 q = emitter.findParameter(words, 'q');

    REQUIRE_CONDITION(!std::isnan(q) && q > 0, ErrorType::PARAMETER_ERROR,
                      "Missing or invalid Q<> for G83!", 'g');

    q *= unitMultiplier(unit);

    f64 clearance = unitMultiplier(unit);

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});

        while (current.z > z) {
          f64 next_depth = std::max(current.z - q, z);
          emitter.bytecode.push_back(Instruction{
              .command = gpp::move_linear, .arguments = {x, y, next_depth}});
          current.z = next_depth;
        }

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});
        current.z = r;
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, 0}});

        while (current.z > z) {
          f64 next_depth = std::max(current.z - q, z);
          f64 increment = next_depth - current.z;
          emitter.bytecode.push_back(Instruction{
              .command = gpp::move_linear, .arguments = {0, 0, increment}});
          current.z = next_depth;
        }

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid, .arguments = {0, 0, r - current.z}});
        current.z = r;
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 84: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(84);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');
    f64 f = emitter.findParameter(words, 'f');

    REQUIRE_CONDITION(!std::isnan(r), ErrorType::PARAMETER_ERROR,
                      "Missing R<> for G84!", 'g');
    REQUIRE_CONDITION(!std::isnan(f), ErrorType::PARAMETER_ERROR,
                      "Missing F<> for G84!", 'g');

    SpindleDirection oldSpindleDirection = spindleDirection;

    for (int i = 0; i < l; ++i) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::start_spindle_clockwise});

      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::start_spindle_counterclockwise});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::start_spindle_counterclockwise});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {0, 0, r - z}});
      }
    }

    emitter.bytecode.push_back(
        Instruction{.command = (oldSpindleDirection == gpp::clockwise
                                    ? gpp::start_spindle_clockwise
                                    : gpp::start_spindle_counterclockwise)});

    FINAL_RETRACT_MOVE();

    break;
  }

  case 85: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(85);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, r - z}});
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 86: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(86);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');
    // f64 $ = emitter.findParameter(words, '$');

    REQUIRE_CONDITION(!std::isnan(p), ErrorType::PARAMETER_ERROR,
                      "Missing P<> for G86!", 'g');

    SpindleDirection sd = spindleDirection;

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::stop_spindle_turning});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = sd == gpp::clockwise
                                       ? gpp::start_spindle_clockwise
                                       : gpp::start_spindle_counterclockwise});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::stop_spindle_turning});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {0, 0, r - z}});

        emitter.bytecode.push_back(
            Instruction{.command = sd == gpp::clockwise
                                       ? gpp::start_spindle_clockwise
                                       : gpp::start_spindle_counterclockwise});
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 87: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(86);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');
    REQUIRE_CONDITION(!std::isnan(p), ErrorType::PARAMETER_ERROR,
                      "Missing P<> for G89!", 'g');

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, r - z}});
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 88: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(88);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');
    // f64 $ = emitter.findParameter(words, '$');

    REQUIRE_CONDITION(!std::isnan(p), ErrorType::PARAMETER_ERROR,
                      "Missing P<> for G86!", 'g');

    SpindleDirection sd = spindleDirection;

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_rapid,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::stop_spindle_turning});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::optional_program_stop});

        emitter.bytecode.push_back(
            Instruction{.command = sd == gpp::clockwise
                                       ? gpp::start_spindle_clockwise
                                       : gpp::start_spindle_counterclockwise});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::stop_spindle_turning});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::optional_program_stop});

        emitter.bytecode.push_back(
            Instruction{.command = sd == gpp::clockwise
                                       ? gpp::start_spindle_clockwise
                                       : gpp::start_spindle_counterclockwise});
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 89: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(89);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');
    REQUIRE_CONDITION(!std::isnan(p), ErrorType::PARAMETER_ERROR,
                      "Missing P<> for G89!", 'g');

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {x, y, current.z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, z - r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                               .arguments = {0, 0, r - z}});
      }
    }

    FINAL_RETRACT_MOVE();

    break;
  }

  case 90:
    emitter.bytecode.push_back(Instruction{.command = gpp::use_distance_mode,
                                           .arguments = {absolute}});
    break;
  case 91:
    emitter.bytecode.push_back(Instruction{.command = gpp::use_distance_mode,
                                           .arguments = {relative}});
    break;

  case 93:
    emitter.bytecode.push_back(Instruction{.command = gpp::set_feed_mode,
                                           .arguments = {inverse_time}});
    break;
  case 94:
    emitter.bytecode.push_back(Instruction{.command = gpp::set_feed_mode,
                                           .arguments = {units_per_minute}});
    break;
  case 95:
    emitter.bytecode.push_back(Instruction{
        .command = gpp::set_feed_mode, .arguments = {units_per_revolution}});
    break;

  case 96: {
    f64 d = emitter.findParameter(words, 'd');
    f64 s = emitter.findParameter(words, 's');

    if (std ::isnan(s)) {
      emitter.bytecode.push_back(gpp::Error(
          ErrorType::PARAMETER_ERROR, "Missing parameter S<> for G96 command!",
          emitter.getLineFromSource(line), line, column));
      break;
    }

    emitter.bytecode.push_back(
        Instruction{.command = gpp::set_spindle_mode,
                    .arguments = {constant_surface_speed}});
    break;
  }

  case 97: {
    f64 s = emitter.findParameter(words, 's');

    if (std ::isnan(s)) {
      emitter.bytecode.push_back(gpp::Error(
          ErrorType::PARAMETER_ERROR, "Missing parameter S<> for G97 command!",
          emitter.getLineFromSource(line), line, column));
      break;
    }

    emitter.bytecode.push_back(Instruction{.command = gpp::set_spindle_mode,
                                           .arguments = {fixed_rpm}});
    break;
  }

  case 98: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::set_retract_mode, .arguments = {old_z}});
    break;
  }

  case 99: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::set_retract_mode, .arguments = {r_plane}});
    break;
  }

  default:
    if (arg >= 54 && arg <= 59) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::use_workspace, .arguments = {arg - 53}});
    } else {
      emitter.bytecode.push_back(
          gpp::Error(ErrorType::PARAMETER_ERROR,
                     "Unsupported G-code: G" + std::to_string(arg_i),
                     emitter.getLineFromSource(line), line, column));
    }
    break;
  }
}

void gpp::Machine::handle_m(std::deque<gpp::VerboseInstruction> &list, f64 arg,
                            const std::vector<Word> &words, int line,
                            int column) {
  int m_code = static_cast<int>(arg);

  switch (m_code) {
  case 0: {
    emitter.bytecode.push_back(Instruction{.command = gpp::program_stop});
    break;
  }
  case 1: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::optional_program_stop});
    break;
  }
  case 2: {
    emitter.bytecode.push_back(Instruction{.command = gpp::set_origin_offsets,
                                           .arguments = {0, 0, 0}});
    emitter.bytecode.push_back(
        Instruction{.command = gpp::stop_spindle_turning});
    emitter.bytecode.push_back(Instruction{.command = gpp::program_end});
    break;
  }
  case 3: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::start_spindle_clockwise});
    break;
  }
  case 4: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::start_spindle_counterclockwise});
    break;
  }
  case 5: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::stop_spindle_turning});
    break;
  }
  case 6: {
    emitter.bytecode.push_back(Instruction{.command = gpp::change_tool});
    break;
  }
  case 98: {
    u64 p = emitter.findParameter(words, 'p');
    ExecutionFrame frame;
    emitter.executionStack.push({
        .block = emitter.subroutines.at(p)->block(),
        .linePointer = 0,
    });
    break;
  }
  case 99: {
    emitter.executionStack.pop();
    break;
  }
  case 100: {
    emitter.bytecode.push_back(
        Instruction{.command = gpp::write_parameters_to_file});
    break;
  }

  default: {
    if (m_code > 100) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::write_parameter_to_file,
                      .arguments = {static_cast<double>(m_code - 100)}});
    }
    break;
  }
  }
}

gpp::Error::Error(gpp::ErrorType t, const std::string &msg,
                  const std::string &source, int line, int column, bool rec)
    : type(t), message(msg), source(source), line(line), column(column),
      recoverable(rec) {}

void gpp::Error::print() const {
  prettyPrintError(message, source, line, column);
}

void gpp::Error::updateSource(std::string &newSource) { source = newSource; }
