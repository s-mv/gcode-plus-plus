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
    REQUIRE_CONDITION(feedRate > 0,                                            \
                      "Feed rate must be set before G" +                       \
                          std::to_string(cycle_num) + " is used!",             \
                      emitter.getLineFromSource(line));                        \
    REQUIRE_CONDITION(!std::isnan(z),                                          \
                      "Missing Z<> for G" + std::to_string(cycle_num) + "!",   \
                      emitter.getLineFromSource(line));                        \
    REQUIRE_CONDITION(!std::isnan(r),                                          \
                      "Missing R<> for G" + std::to_string(cycle_num) + "!",   \
                      emitter.getLineFromSource(line));                        \
  } while (0)

#define SETUP_CANNED_CYCLE_POSITION()                                          \
  Vec3D current = getLogicalPosition();                                        \
  Vec3D target_position = {x, y, z};                                           \
  if (std::isnan(target_position.x))                                           \
    target_position.x = current.x;                                             \
  if (std::isnan(target_position.y))                                           \
    target_position.y = current.y;                                             \
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
    emitter.bytecode.push_back(                                                \
        Instruction{.command = gpp::move_rapid,                                \
                    .arguments = {target_position.x, target_position.y,        \
                                  (retractMode == gpp::old_z) ? old_z : r}});  \
  } else {                                                                     \
    emitter.bytecode.push_back(Instruction{                                    \
        .command = gpp::move_rapid,                                            \
        .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});    \
  }

#define REQUIRE_CONDITION(condition, message, source)                          \
  do {                                                                         \
    if (!(condition)) {                                                        \
      emitter.bytecode.push_back(gpp::Error(ErrorType::PARAMETER_ERROR,        \
                                            message, source, line, column));   \
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
      .commentOrMessage = false,
      .instruction = Instruction{.command = no_command}};

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

    REQUIRE_CONDITION(feedRate != 0,
                      "Feed rate should be non-zero for feed_arc to run!",
                      emitter.getLineFromSource(line));

    REQUIRE_CONDITION(
        std::isnan(r) || (std::isnan(i) && std::isnan(j) && std::isnan(k)),
        "Both r and i/j/k are defined!", emitter.getLineFromSource(line));

    REQUIRE_CONDITION(
        emitter.arcOffetsAligned(plane, i, j, k),
        std::string("Arc isn't aligned to the current plane, i.e. the ") +
            planeToString(plane) + " plane.",
        emitter.getLineFromSource(line));

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

      REQUIRE_CONDITION(len <= 2 * r, "Radius too small for arc!",
                        emitter.getLineFromSource(line));

      gpp::Vec2D midpoint = (currentPos + targetPos) * 0.5;
      f64 h = sqrt(r * r - (len * len) / 4.0);
      gpp::Vec2D perpendicular = {-delta.y, delta.x};

      f64 perpendicularLen = sqrt(perpendicular.x * perpendicular.x +
                                  perpendicular.y * perpendicular.y);
      REQUIRE_CONDITION(
          perpendicularLen != 0,
          "Invalid arc calculation: zero-length perpendicular vector.",
          emitter.getLineFromSource(line));

      perpendicular = perpendicular * (1.0 / perpendicularLen);
      center = midpoint + perpendicular * h * rotation;
    } else {
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
      REQUIRE_CONDITION(pi >= 1 && pi <= 6, "Invalid coordinate system number",
                        emitter.getLineFromSource(line));

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

    h = tools.at(h).tlo;

    emitter.bytecode.push_back(
        Instruction{.command = gpp::use_tool_length_offset, .arguments = {h}});
    break;
  }

  case 80: {
    break;
  }

  case 81:
  case 82: {
    EXTRACT_CANNED_CYCLE_PARAMS();
    VALIDATE_CANNED_CYCLE_PARAMS(81);
    SETUP_CANNED_CYCLE_POSITION();
    MOVE_TO_RETRACT_PLANE();

    f64 p = emitter.findParameter(words, 'p');

    if (arg_i == 82)
      REQUIRE_CONDITION(!std::isnan(p) && p >= 0, "Invalid P<> value for G82!",
                        emitter.getLineFromSource(line));

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
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, 0}});

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_linear, .arguments = {0, 0, -std::abs(z)}});

        if (arg_i == 82)
          emitter.bytecode.push_back(
              Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid, .arguments = {0, 0, std::abs(z)}});
      }
    }

    FINAL_RETRACT_MOVE();
    break;
  }

  case 83: {
    REQUIRE_CONDITION(feedRate > 0, "Feed rate must be set before G83 is used!",
                      emitter.getLineFromSource(line));

    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    f64 q = emitter.findParameter(words, 'q');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G83!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G83!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(q) && q > 0,
                      "Missing or invalid Q<> for G83!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);
    q *= unitMultiplier(unit);

    if (std::isnan(l_real))
      l_real = 1;
    int l = static_cast<int>(l_real);

    Vec3D current = getLogicalPosition();
    Vec3D target_position = {x, y, z};

    if (std::isnan(target_position.x))
      target_position.x = current.x;
    if (std::isnan(target_position.y))
      target_position.y = current.y;

    f64 old_z = current.z;
    f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

    if (distanceMode == absolute) {
      if (old_z < r) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {current.x, current.y, r}});
        current.z = r;
      }
    } else {
      if (r > 0) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
        current.z = r;
      }
    }

    f64 clearance = unitMultiplier(unit);

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});

        while (current.z > z) {
          f64 next_depth = std::max(current.z - q, z);
          emitter.bytecode.push_back(Instruction{
              .command = gpp::move_linear,
              .arguments = {target_position.x, target_position.y, next_depth}});
          current.z = next_depth;
        }

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {target_position.x, target_position.y, r}});
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

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});
    } else {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});
    }

    break;
  }

  // TODO rigourous testing
  case 84: {
    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    f64 p = emitter.findParameter(words, 'p');
    f64 f = emitter.findParameter(words, 'f');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G84!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G84!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(f), "Missing F<> for G84!",
                      emitter.getLineFromSource(line));

    int l = std::isnan(l_real) ? 1 : (int)l_real;

    Vec3D current = getLogicalPosition();
    f64 old_z = current.z;

    r *= unitMultiplier(unit);

    f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

    // REQUIRE_CONDITION(retract_z >= current.z || distanceMode == relative,
    // "Retract plane R is below current Z!", emitter.getLineFromSource(line));

    if (distanceMode == absolute) {
      if (old_z < r) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {current.x, current.y, r}});
        current.z = r;
      }
    } else {
      if (r > 0) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
        current.z = r;
      }
    }

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

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});
    } else {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {0, 0,
                        (retractMode == gpp::old_z) ? old_z - r - 0 : 0}});
    }

    break;
  }

  case 85: {
    REQUIRE_CONDITION(feedRate > 0, "Feed rate must be set before G85 is used!",
                      emitter.getLineFromSource(line));

    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    // f64 q = emitter.findParameter(words, 'q');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G85!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G85!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);

    if (std::isnan(l_real))
      l_real = 1;
    int l = static_cast<int>(l_real);

    Vec3D current = getLogicalPosition();
    Vec3D target_position = {x, y, z};

    if (std::isnan(target_position.x))
      target_position.x = current.x;
    if (std::isnan(target_position.y))
      target_position.y = current.y;

    f64 old_z = current.z;
    f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

    if (distanceMode == absolute) {
      if (old_z < r) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {current.x, current.y, r}});
        current.z = r;
      }
    } else {
      if (r > 0) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
        current.z = r;
      }
    }

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});
        if (z < old_z) {
          emitter.bytecode.push_back(
              Instruction{.command = gpp::move_linear, .arguments = {x, y, r}});
        }
        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_linear, .arguments = {x, y, final_retract_z}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {0, 0, z}});
        if (z < old_z) {
          emitter.bytecode.push_back(Instruction{.command = gpp::move_linear,
                                                 .arguments = {0, 0, r - z}});
        }
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear,
                        .arguments = {0, 0, final_retract_z - r}});
      }
    }

    break;
  }

  case 86: {
    REQUIRE_CONDITION(feedRate > 0, "Feed rate must be set before G86 is used!",
                      emitter.getLineFromSource(line));

    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    f64 p = emitter.findParameter(words, 'p');
    // f64 $ = emitter.findParameter(words, '$');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G86!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G86!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);

    if (std::isnan(l_real))
      l_real = 1;
    int l = static_cast<int>(l_real);

    Vec3D current = getLogicalPosition();
    Vec3D target_position = {x, y, z};

    if (std::isnan(target_position.x))
      target_position.x = current.x;
    if (std::isnan(target_position.y))
      target_position.y = current.y;

    f64 old_z = current.z;
    f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

    if (distanceMode == absolute) {
      if (old_z < r) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {current.x, current.y, r}});
        current.z = r;
      }
    } else {
      if (r > 0) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
        current.z = r;
      }
    }

    SpindleDirection sd = spindleDirection;

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {target_position.x, target_position.y, r}});

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_linear,
            .arguments = {target_position.x, target_position.y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::stop_spindle_turning});

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {target_position.x, target_position.y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = sd == gpp::clockwise
                                       ? gpp::start_spindle_clockwise
                                       : gpp::start_spindle_counterclockwise});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});

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

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});
    } else {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});
    }

    break;
  }

  // TODO rigourous testing
  case 87: {
    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 p = emitter.findParameter(words, 'p');
    f64 f = emitter.findParameter(words, 'f');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G87!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G87!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(spindleDirection != gpp::off,
                      "Spindle must be ON for G87!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);

    f64 initPositionZ = position.z;

    if (!std::isnan(x) || !std::isnan(y)) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {std::isnan(x) ? position.x : x,
                          std::isnan(y) ? position.y : y, position.z}});
      } else {
        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {std::isnan(x) ? 0 : x, std::isnan(y) ? 0 : y, 0}});
      }
    }

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::move_rapid,
                      .arguments = {position.x, position.y, r}});
    } else {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
    }

    if (!std::isnan(f)) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::set_feed_rate, .arguments = {f}});
    }

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::move_linear,
                      .arguments = {position.x, position.y, z}});
    } else {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::move_linear, .arguments = {0, 0, z}});
    }

    if (!std::isnan(p)) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::dwell, .arguments = {p}});
    }

    emitter.bytecode.push_back(
        Instruction{.command = gpp::stop_spindle_turning});
    emitter.bytecode.push_back(
        Instruction{.command = gpp::start_spindle_counterclockwise});

    if (retractMode == gpp::old_z) {
      emitter.bytecode.push_back(
          Instruction{.command = gpp::move_rapid,
                      .arguments = {position.x, position.y, initPositionZ}});
    } else {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {position.x, position.y, r}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, -z}});
      }
    }

    emitter.bytecode.push_back(
        Instruction{.command = gpp::stop_spindle_turning});
    emitter.bytecode.push_back(
        Instruction{.command = gpp::start_spindle_clockwise});

    break;
  }

  // TODO rigourous testing
  case 88: {
    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    f64 p = emitter.findParameter(words, 'p');
    int repeats = std::isnan(l_real) ? 1 : (int)l_real;

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G88!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G88!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);

    f64 old_z = position.z;

    for (int i = 0; i < repeats; ++i) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {x, y, z}});
      } else {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {x, y, r}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_linear, .arguments = {0, 0, z}});
      }

      if (!std::isnan(p)) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});
      }

      emitter.bytecode.push_back(
          Instruction{.command = gpp::stop_spindle_turning});

      emitter.bytecode.push_back(
          Instruction{.command = gpp::optional_program_stop});

      if (spindleDirection == gpp::clockwise) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::start_spindle_clockwise});
      } else if (spindleDirection == gpp::counterclockwise) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::start_spindle_counterclockwise});
      }
    }

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});
    } else {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});
    }

    break;
  }

  case 89: {
    REQUIRE_CONDITION(feedRate > 0, "Feed rate must be set before G86 is used!",
                      emitter.getLineFromSource(line));

    f64 x, y, z;
    f64 r = emitter.findParameter(words, 'r');
    f64 l_real = emitter.findParameter(words, 'l');
    f64 p = emitter.findParameter(words, 'p');

    emitter.extractCoordinates(words, x, y, z);

    REQUIRE_CONDITION(!std::isnan(z), "Missing Z<> for G86!",
                      emitter.getLineFromSource(line));
    REQUIRE_CONDITION(!std::isnan(r), "Missing R<> for G86!",
                      emitter.getLineFromSource(line));

    r *= unitMultiplier(unit);

    if (std::isnan(l_real))
      l_real = 1;
    int l = static_cast<int>(l_real);

    Vec3D current = getLogicalPosition();
    Vec3D target_position = {x, y, z};

    if (std::isnan(target_position.x))
      target_position.x = current.x;
    if (std::isnan(target_position.y))
      target_position.y = current.y;

    f64 old_z = current.z;
    f64 final_retract_z = (retractMode == gpp::old_z) ? old_z : r;

    if (distanceMode == absolute) {
      if (old_z < r) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid,
                        .arguments = {current.x, current.y, r}});
        current.z = r;
      }
    } else {
      if (r > 0) {
        emitter.bytecode.push_back(
            Instruction{.command = gpp::move_rapid, .arguments = {0, 0, r}});
        current.z = r;
      }
    }

    for (int i = 0; i < l; i++) {
      if (distanceMode == absolute) {
        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_linear,
            .arguments = {target_position.x, target_position.y, z}});

        emitter.bytecode.push_back(
            Instruction{.command = gpp::dwell, .arguments = {p}});

        emitter.bytecode.push_back(Instruction{
            .command = gpp::move_rapid,
            .arguments = {target_position.x, target_position.y, r}});
      }
    }

    if (distanceMode == absolute) {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {x, y, (retractMode == gpp::old_z) ? old_z : r}});
    } else {
      emitter.bytecode.push_back(Instruction{
          .command = gpp::move_rapid,
          .arguments = {0, 0, (retractMode == gpp::old_z) ? old_z - r : 0}});
    }

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
