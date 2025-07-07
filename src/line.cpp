#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>

#include "bytecode.hpp"

#include "gpp.hpp"
#include "machine.hpp"
#include "parser_antlr4.h"
#include "support/Any.h"
#include "util.hpp"

#define modal_groups_len (16)

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
int getInstructionPriority(gpp::VerboseInstruction instruction);

antlrcpp::Any
gpp::BytecodeEmitter::visitLine(parser_antlr4::LineContext *context) {
  line = context->getStart()->getLine();
  column = context->getStart()->getCharPositionInLine();

  for (parser_antlr4::SegmentContext *segment : context->segment()) {
    visit(segment);
  }

  std::unordered_set<f64> seenModalGroups;

  // error handling
  for (const Word &word : words) {
    if (std::isnan(word.arg)) {
      verboseInstructions.push_back(
          {.word = 'e',
           .instruction =
               gpp::Error(ErrorType::PARAMETER_ERROR, "Argument is unspecified",
                          getLineFromSource(line), column)});
    }
  }

  for (const Word &word : words) {
    if (word.word == 'g') {
      f64 group = findModalGroup(word.arg);

      if (group == -1)
        continue;

      if (seenModalGroups.find(group) != seenModalGroups.end()) {
        std::ostringstream error;
        error << "Multiple G-codes from modal group '" << group << "' found!";
        std::string message = error.str();

        verboseInstructions.push_back(
            {.word = 'e',
             .instruction = gpp::Error(ErrorType::PARAMETER_ERROR, message,
                                       getLineFromSource(line), line, column)});

        return nullptr;
      }
      seenModalGroups.insert(group);
    }
  }

  bool noCode = true;

  for (const Word &word : words) {
    VerboseInstruction verboseInstruction = {
        .word = word.word,
        .arg = word.arg,
        .commentOrMessage = false,
    };

    if (word.word == 'g') {
      noCode = false;
      handle_g(verboseInstructions, word.arg, words, line, column);
      continue;
    } else if (word.word == 'm') {
      handle_m(verboseInstructions, word.arg, words, line, column);
      continue;
    } else if (word.word == 'f' || word.word == 's' || word.word == 't') {
      if (word.word == 'f' && word.arg < 0)
        verboseInstruction.instruction = gpp::Error(
            ErrorType::PARAMETER_ERROR, "Feedrate cannot be less than zero!",
            getLineFromSource(line), line);
      if (word.word == 's' && word.arg < 0) {
        verboseInstruction.instruction =
            gpp::Error(ErrorType::PARAMETER_ERROR,
                       "Spindle speed cannot be less than zero!",
                       getLineFromSource(line), line);
      }
      if (word.word == 't') {
        if (word.arg < 0)
          verboseInstruction.instruction =
              gpp::Error(ErrorType::PARAMETER_ERROR,
                         "Tool number cannot be less than zero!",
                         getLineFromSource(line), line);
      }

      verboseInstructions.push_back(verboseInstruction);
    }
  }

  if (machine->activeInstruction.word != '0' && noCode &&
      machine->activeInstruction.arg >= 0 &&
      machine->activeInstruction.arg <= 3) {
    bool hasCoordinates = false;
    bool hasArcParams = false;

    for (const Word &w : words) {
      if (w.word == 'x' || w.word == 'y' || w.word == 'z') {
        hasCoordinates = true;
      }
      if (w.word == 'i' || w.word == 'j' || w.word == 'k' || w.word == 'r') {
        hasArcParams = true;
      }
    }

    if ((machine->activeInstruction.arg == 0 ||
         machine->activeInstruction.arg == 1) &&
        hasCoordinates) {
      handle_g(verboseInstructions, machine->activeInstruction.arg, words, line,
               column);
    } else if ((machine->activeInstruction.arg == 2 ||
                machine->activeInstruction.arg == 3) &&
               (hasCoordinates || hasArcParams)) {
      handle_g(verboseInstructions, machine->activeInstruction.arg, words, line,
               column);
    }
  }

  std::sort(verboseInstructions.begin(), verboseInstructions.end(),
            compareVerboseInstructions);

  verboseInstructions.push_back({.word = 'c'});

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
int getInstructionPriority(gpp::VerboseInstruction instruction) {
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

bool compareVerboseInstructions(const gpp::VerboseInstruction &a,
                                const gpp::VerboseInstruction &b) {
  int pa = getInstructionPriority(a);
  int pb = getInstructionPriority(b);
  return pa < pb;
}
