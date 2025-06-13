#include "bytecode.hpp"

#include <cmath>

#include "machine.hpp"

gpp::Instruction gpp::BytecodeEmitter::handle_g(f64 arg,
                                                const std::vector<Word> &words,
                                                int line, int column) {
  if (arg == 0 || arg == 1 || arg == 92) {
    f64 x = NAN, y = NAN, z = NAN;
    for (Word operand : words) {
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

    if (std::isnan(x))
      x = machine->position.x - machine->g92offset.x;
    if (std::isnan(y))
      y = machine->position.y - machine->g92offset.y;
    if (std::isnan(z))
      z = machine->position.z - machine->g92offset.z;

    gpp::Command command =
        arg == 0 ? move_rapid : (arg == 1 ? move_linear : set_origin_offsets);

    return {
        .command = command,
        .arguments = {x, y, z},
    };
  } else if (arg == 2 || arg == 3) {
    f64 x = NAN, y = NAN, z = NAN;
    f64 i = NAN, j = NAN, k = NAN;
    f64 r = NAN;
    for (Word operand : words) {
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
      case 'r':
        r = operand.arg;
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
      }
    }

    if (machine->feedRate == 0) {
      prettyPrintError("Feed rate should be non-zero for feed_arc to run!",
                       getLineFromSource(line), line, column);
      exit(0);
    }

    if (!std::isnan(r) &&
        (!std::isnan(i) || !std::isnan(j) || !std::isnan(k))) {
      prettyPrintError("Both r and i/j/k are defined!", getLineFromSource(line),
                       line, column);
      exit(0);
    }

    if (!arcOffetsAligned(machine->plane, i, j, k)) {
      std::ostringstream error;
      error << "Arc isn't aligned to the current plane, i.e. the "
            << machine->planeToString(machine->plane) << " plane.";
      std::string message = error.str();

      prettyPrintError(message, getLineFromSource(line), line, column);
      exit(0);
    }

    if (std::isnan(x))
      x = machine->position.x;
    if (std::isnan(y))
      y = machine->position.y;
    if (std::isnan(z))
      z = machine->position.z;
    if (std::isnan(i))
      i = 0;
    if (std::isnan(j))
      j = 0;
    if (std::isnan(k))
      k = 0;

    f64 x0, y0, x1, y1, xc, yc, z2;
    int rotation = arg == 2 ? 1 : -1;

    x0 = (machine->plane == plane_xy)   ? machine->position.x
         : (machine->plane == plane_yz) ? machine->position.y
                                        : machine->position.z;

    y0 = (machine->plane == plane_xy)   ? machine->position.y
         : (machine->plane == plane_yz) ? machine->position.z
                                        : machine->position.x;

    x1 = (machine->plane == plane_xy)   ? x
         : (machine->plane == plane_yz) ? y
                                        : z;

    y1 = (machine->plane == plane_xy)   ? y
         : (machine->plane == plane_yz) ? z
                                        : x;

    z2 = (machine->plane == plane_xy)   ? z
         : (machine->plane == plane_yz) ? x
                                        : y;

    Vec2D a = {x0, y0};
    Vec2D b = {x1, y1};

    if (!std::isnan(r)) {
      Vec2D delta = b - a;
      f64 len = sqrt(delta.dot(delta));

      if (len > 2 * r) {
        prettyPrintError("Radius too small for arc!", getLineFromSource(line),
                         line, column);
        exit(0);
      }

      Vec2D midpoint = (a + b) * 0.5;
      // perpendicular distance from the center to the line (a, b)
      f64 h = sqrt(r * r - (len * len) / 4.0);
      Vec2D perpendicular = {-delta.y, delta.x};

      f64 perpendicularLen = sqrt(perpendicular.x * perpendicular.x +
                                  perpendicular.y * perpendicular.y);
      if (perpendicularLen == 0) {
        prettyPrintError(
            "Invalid arc calculation: zero-length perpendicular vector.",
            getLineFromSource(line), line, column);
        exit(0);
      }

      perpendicular.x /= perpendicularLen;
      perpendicular.y /= perpendicularLen;

      Vec2D center = midpoint + perpendicular * h * rotation;

      xc = center.x;
      yc = center.y;
    } else {
      xc = x0 + (machine->plane == plane_xy   ? i
                 : machine->plane == plane_yz ? j
                                              : k);
      yc = y0 + (machine->plane == plane_xy   ? j
                 : machine->plane == plane_yz ? k
                                              : i);
    }

    return {.command = arc_feed,
            .arguments = {
                x1,            // x1
                y1,            // y1
                xc,            // xc
                yc,            // yc
                (f64)rotation, // positive -> counterclockwise
                z2,            // z2
            }};
  } else if (arg == 4) {
    f64 p = 0;
    for (Word operand : words) {
      if (operand.word == 'p') {
        p = operand.arg;
        break;
      }
    }

    return {
        .command = dwell,
        .arguments = {p},
    };
  } else if (arg == 17) {
    return {.command = select_plane, .arguments = {plane_xy}};
  } else if (arg == 18) {
    return {.command = select_plane, .arguments = {plane_yz}};
  } else if (arg == 19) {
    return {.command = select_plane, .arguments = {plane_xz}};
  } else if (arg == 20) {
    return {.command = use_length_units, .arguments = {Unit::inch}};
  } else if (arg == 21) {
    return {.command = use_length_units, .arguments = {Unit::mm}};
  } else if (arg == 90) {
    return {
        .command = use_distance_mode,
        .arguments = {DistanceMode::absolute},
    };
  } else if (arg == 91) {
    return {
        .command = use_distance_mode,
        .arguments = {DistanceMode::relative},
    };
  }

  return {.command = no_command};
}

gpp::Instruction gpp::BytecodeEmitter::handle_m(f64 arg,
                                                const std::vector<Word> &words,
                                                int line, int column) {
  if (arg == 0) {
    return {.command = program_stop};
  } else if (arg == 1) {
    return {.command = optional_program_stop};
  } else if (arg == 2) {
    return {.command = program_end};
  } else if (arg == 3) {
    return {.command = start_spindle_clockwise};
  } else if (arg == 4) {
    return {.command = start_spindle_counterclockwise};
  } else if (arg == 5) {
    return {.command = stop_spindle_turning};
  } else if (arg == 6) {
    return {.command = change_tool};
  } else if (arg == 100) {
    return {.command = write_parameters_to_file};
  } else if (arg > 100) {
    return {
        .command = write_parameter_to_file,
        .arguments = {arg - 100},
    };
  }

  return {.command = no_command};
}