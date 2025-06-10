#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "bytecode.hpp"

#include "machine.hpp"
#include "parser_antlr4.h"
#include "support/Any.h"
#include "util.hpp"

#define modal_groups_len (16)

struct VerboseInstruction {
  char word;
  f64 arg;
  bool commentOrMessage;
  gpp::Instruction command;
};

const f64 *modal_groups[modal_groups_len] = {
    (const f64[]){4, 10, 28, 30, 52, 53, 92, 92.1, 92.2, 92.3, -1},
    (const f64[]){0, 1, 2, 3, 33, 38, 73, 76, 80, 81, 82, 83, 84, 85, 86, 87,
                  88, 89, -1},
    (const f64[]){17, 18, 19, 17.1, 18.1, 19.1, -1},
    (const f64[]){90, 91, -1},
    (const f64[]){90.1, 91.1, -1},
    (const f64[]){93, 94, 95, -1},
    (const f64[]){20, 21, -1},
    (const f64[]){40, 41, 42, 41.1, 42.1, -1},
    (const f64[]){43, 43.1, 49, -1},

    (const f64[]){-1},

    (const f64[]){98, 99, -1},

    (const f64[]){-1},

    (const f64[]){54, 55, 56, 57, 58, 59, 59.1, 59.2, 59.3, -1},
    (const f64[]){61, 61.1, 64, -1},
    (const f64[]){96, 97, -1},
    (const f64[]){7, 8, -1},
};

// helpers
f64 findModalGroup(f64 code);
bool compareVerboseInstructions(const VerboseInstruction &a,
                                const VerboseInstruction &b);
int getInstructionPriority(VerboseInstruction instruction);

antlrcpp::Any
gpp::BytecodeEmitter::visitLine(parser_antlr4::LineContext *context) {
  int line = context->getStart()->getLine();
  int column = context->getStart()->getCharPositionInLine();

  for (parser_antlr4::SegmentContext *segment : context->segment()) {
    visit(segment);
  }

  std::unordered_set<f64> seenModalGroups;

  for (const Word &word : words) {
    if (word.word == 'g') {
      f64 group = findModalGroup(word.arg);

      if (group == -1)
        continue;

      if (seenModalGroups.find(group) != seenModalGroups.end()) {
        std::ostringstream error;
        error << "Multiple G-codes from modal group '" << group << "' found!";
        std::string message = error.str();

        prettyPrintError(message, getLineFromSource(line), line, column);
        exit(0);
      }
      seenModalGroups.insert(group);
    }
  }

  std::vector<VerboseInstruction> verboseInstructions;

  for (const Word &word : words) {
    VerboseInstruction vi = {
        .word = word.word,
        .arg = word.arg,
        .commentOrMessage = false,
    };

    if (word.word == 'g') {
      if (word.arg == 0 || word.arg == 1 || word.arg == 92) {
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
          x = machine->position.x;
        if (std::isnan(y))
          y = machine->position.y;
        if (std::isnan(z))
          z = machine->position.z;

        gpp::Command command =
            word.arg == 0 ? move_rapid
                          : (word.arg == 1 ? move_linear : set_origin_offsets);

        vi.command = {
            .command = (word.arg == 0) ? move_rapid : move_linear,
            .arguments = {x, y, z},
        };
      } else if (word.arg == 2 || word.arg == 3) {
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
          prettyPrintError("Both r and i/j/k are defined!",
                           getLineFromSource(line), line, column);
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
        int rotation = word.arg == 2 ? 1 : -1;

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
            prettyPrintError("Radius too small for arc!",
                             getLineFromSource(line), line, column);
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

        vi.command = {.command = arc_feed,
                      .arguments = {
                          x1,            // x1
                          y1,            // y1
                          xc,            // xc
                          yc,            // yc
                          (f64)rotation, // positive -> counterclockwise
                          z2,            // z2
                      }};
      } else if (word.arg == 4) {
        f64 p = 0;
        for (Word operand : words) {
          if (operand.word == 'p') {
            p = operand.arg;
            break;
          }
        }

        vi.command = {
            .command = dwell,
            .arguments = {p},
        };
      } else if (word.arg == 17) {
        vi.command = {.command = select_plane, .arguments = {plane_xy}};
      } else if (word.arg == 18) {
        vi.command = {.command = select_plane, .arguments = {plane_yz}};
      } else if (word.arg == 19) {
        vi.command = {.command = select_plane, .arguments = {plane_xz}};
      } else if (word.arg == 20) {
        vi.command = {.command = use_length_units, .arguments = {Unit::mm}};
      } else if (word.arg == 21) {
        vi.command = {.command = use_length_units, .arguments = {Unit::inch}};
      } else if (word.arg == 90) {
        vi.command = {
            .command = use_distance_mode,
            .arguments = {DistanceMode::absolute},
        };
      } else if (word.arg == 91) {
        vi.command = {
            .command = use_distance_mode,
            .arguments = {DistanceMode::relative},
        };
      } else
        continue;
    } else if (word.word == 'f') {
      vi.command = {.command = set_feed_rate, .arguments = {word.arg}};
    } else if (word.word == 'm') {
      if (word.arg == 3) {
        vi.command = {.command = start_spindle_clockwise};
      } else if (word.arg == 4) {
        vi.command = {.command = start_spindle_counterclockwise};
      } else if (word.arg == 5) {
        vi.command = {.command = stop_spindle_turning};
      } else if (word.arg == 100) {
        vi.command = {.command = write_parameters_to_file};
      } else if (word.arg > 100) {
        vi.command = {
            .command = write_parameter_to_file,
            .arguments = {word.arg - 100},
        };
      } else
        continue;
    } else
      continue;

    verboseInstructions.push_back(vi);
  }

  std::sort(verboseInstructions.begin(), verboseInstructions.end(),
            compareVerboseInstructions);

  for (const VerboseInstruction &vi : verboseInstructions) {
    bytecode.push(vi.command);
  }

  words.clear();

  return nullptr;
}

bool gpp::BytecodeEmitter::arcOffetsAligned(const Plane currentPlane, f64 i,
                                            f64 j, f64 k) {
  return (currentPlane == Plane::plane_xy && std::isnan(k)) ||
         (currentPlane == Plane::plane_yz && std::isnan(i)) ||
         (currentPlane == Plane::plane_xz && std::isnan(j));
}

gpp::Vec3D getCenter(f64 x1, f64 y1, f64 x2, f64 y2, f64 r) { return {}; }

f64 findModalGroup(f64 code) {
  for (int i = 0; i < modal_groups_len; i++) {
    for (int j = 0; modal_groups[i][j] != -1; j++) {
      if (modal_groups[i][j] == code)
        return i;
    }
  }

  return -1;
}

// the comments are referenced from here:
// https://linuxcnc.org/docs/stable/html/gcode/overview.html#gcode:order-of-execution
int getInstructionPriority(VerboseInstruction instruction) {
  //  0: O-word commands (optionally followed by a comment but no other
  //  words allowed on the same line)
  if (instruction.word == 'o')
    return 0;

  //  1: Comment (including message)
  if (instruction.commentOrMessage)
    return 1; // assuming 'c' marks a comment

  //  2: Set feed rate mode (G93, G94).
  if (instruction.word == 'g' &&
      (instruction.arg == 93 || instruction.arg == 94))
    return 2;

  //  3: Set feed rate (F).
  if (instruction.word == 'f')
    return 3;

  //  4: Set spindle speed (S).
  if (instruction.word == 's')
    return 4;

  //  5: Select tool (T).
  if (instruction.word == 't')
    return 5;

  //  6: HAL pin I/O (M62-M68).
  if (instruction.word == 'm' && instruction.arg >= 62 && instruction.arg <= 68)
    return 6;

  //  7: Change tool (M6) and Set Tool Number (M61).
  if (instruction.word == 'm' &&
      (instruction.arg == 6 || instruction.arg == 61))
    return 7;

  //  8: Spindle on or off (M3, M4, M5).
  if (instruction.word == 'm' &&
      (instruction.arg == 3 || instruction.arg == 4 || instruction.arg == 5))
    return 8;

  //  9: Save State (M70, M73), Restore State (M72), Invalidate State (M71).
  if (instruction.word == 'm' &&
      (instruction.arg == 70 || instruction.arg == 73 ||
       instruction.arg == 72 || instruction.arg == 71))
    return 9;

  // 10: Coolant on or off (M7, M8, M9).
  if (instruction.word == 'm' &&
      (instruction.arg == 7 || instruction.arg == 8 || instruction.arg == 9))
    return 10;

  // 11: Enable or disable overrides (M48, M49, M50, M51, M52, M53).
  if (instruction.word == 'm' && instruction.arg >= 48 && instruction.arg <= 53)
    return 11;

  // 12: User-defined Commands (M100-M199).
  if (instruction.word == 'm' && instruction.arg >= 100 &&
      instruction.arg <= 199)
    return 12;

  // 13: Dwell (G4).
  if (instruction.word == 'g' && instruction.arg == 4)
    return 13;

  // 14: Set active plane (G17, G18, G19).
  if (instruction.word == 'g' &&
      (instruction.arg == 17 || instruction.arg == 18 || instruction.arg == 19))
    return 14;

  // 15: Set length units (G20, G21).
  if (instruction.word == 'g' &&
      (instruction.arg == 20 || instruction.arg == 21))
    return 15;

  // 16: Cutter radius compensation on or off (G40, G41, G42).
  if (instruction.word == 'g' &&
      (instruction.arg == 40 || instruction.arg == 41 || instruction.arg == 42))
    return 16;

  // 17: Cutter length compensation on or off (G43, G49).
  if (instruction.word == 'g' &&
      (instruction.arg == 43 || instruction.arg == 49))
    return 17;

  // 18: Coordinate system selection (G54, G55, G56, G57, G58, G59, G59.1,
  // G59.2, G59.3).
  if (instruction.word == 'g' &&
      (instruction.arg == 54 || instruction.arg == 55 ||
       instruction.arg == 56 || instruction.arg == 57 ||
       instruction.arg == 58 || instruction.arg == 59 ||
       instruction.arg == 59.1 || instruction.arg == 59.2 ||
       instruction.arg == 59.3))
    return 18;

  // 19: Set path control mode (G61, G61.1, G64).
  if (instruction.word == 'g' &&
      (instruction.arg == 61 || instruction.arg == 61.1 ||
       instruction.arg == 64))
    return 19;

  // 20: Set distance mode (G90, G91).
  if (instruction.word == 'g' &&
      (instruction.arg == 90 || instruction.arg == 91))
    return 20;

  // 21: Set retract mode (G98, G99).
  if (instruction.word == 'g' &&
      (instruction.arg == 98 || instruction.arg == 99))
    return 21;

  // 22: Go to reference location (G28, G30) or change coordinate system
  // data (G10) or set axis offsets (G52, G92, G92.1, G92.2, G94).
  if (instruction.word == 'g' &&
      (instruction.arg == 28 || instruction.arg == 30 ||
       instruction.arg == 10 || instruction.arg == 52 ||
       instruction.arg == 92 || instruction.arg == 92.1 ||
       instruction.arg == 92.2 || instruction.arg == 94))
    return 22;

  // 23: Perform motion (G0 to G3, G33, G38.n, G73, G76, G80 to G89), as
  // modified (possibly) by G53. For motions: G0=0, G1=1, G2=2, G3=3, etc.
  if (instruction.word == 'g' &&
      (instruction.arg == 0 || instruction.arg == 1 || instruction.arg == 2 ||
       instruction.arg == 3 || instruction.arg == 33 ||
       (instruction.arg >= 38 && instruction.arg < 39) ||
       instruction.arg == 73 || instruction.arg == 76 ||
       (instruction.arg >= 80 && instruction.arg <= 89) ||
       instruction.arg == 53))
    return 23;

  // 24: Stop (M0, M1, M2, M30, M60).
  if (instruction.word == 'm' &&
      (instruction.arg == 0 || instruction.arg == 1 || instruction.arg == 2 ||
       instruction.arg == 30 || instruction.arg == 60))
    return 24;

  // Default lowest priority (unknown or uncategorized commands)
  return 100;
}

bool compareVerboseInstructions(const VerboseInstruction &a,
                                const VerboseInstruction &b) {
  int pa = getInstructionPriority(a);
  int pb = getInstructionPriority(b);
  return pa < pb;
}
