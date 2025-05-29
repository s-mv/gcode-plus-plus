#include <any>
#include <cmath>
#include <vector>

#include "bytecode.hpp"

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

f64 find_modal_group(f64 code);

antlrcpp::Any
gpp::BytecodeEmitter::visitLine(parser_antlr4::LineContext *context) {
  for (parser_antlr4::SegmentContext *segment : context->segment()) {
    visit(segment);
  }

  for (Word word : words) {
    if (word.word == 'g') {
      if (word.arg == 0) {
        f64 x, y, z;
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

        std::vector<f64> arguments = {x, y, z};

        bytecode.push({
            .command = move_rapid,
            .arguments = arguments,
        });

      } else if (word.arg == 1) {
        f64 x, y, z, f;
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
          case 'f':
            f = operand.arg;
            break;
          }
        }

        std::vector<f64> arguments_feed_rate = {f};
        std::vector<f64> arguments_linear_move = {x, y, z};

        bytecode.push({
            .command = set_feed_rate,
            .arguments = arguments_feed_rate,
        });

        bytecode.push({
            .command = move_linear,
            .arguments = arguments_linear_move,
        });

      } else if (word.arg == 20) {
        gpp::Instruction instruction = {
            .command = set_unit_in,
        };

        bytecode.push(instruction);
      } else if (word.arg == 20) {
        gpp::Instruction instruction = {
            .command = set_unit_mm,
        };

        bytecode.push(instruction);
      }
    }
  }

  words.clear();

  return nullptr;
}

f64 find_modal_group(f64 code) {
  for (int i = 0; i < modal_groups_len; i++) {
    for (int j = 0; modal_groups[i][j] != -1; j++) {
      if (modal_groups[i][j] == code)
        return i;
    }
  }

  return -1;
}

antlrcpp::Any gpp::BytecodeEmitter::visitParameter_value(
    parser_antlr4::Parameter_valueContext *context) {
  f64 index = std::any_cast<f64>(visit(context->parameter_index()));
  i64 address = static_cast<i64>(index);
  f64 value = get_memory(address);

  return value;
}

antlrcpp::Any gpp::BytecodeEmitter::visitParameter_setting(
    parser_antlr4::Parameter_settingContext *context) {
  f64 index = std::any_cast<f64>(visit(context->parameter_index()));
  i64 address = static_cast<i64>(index);
  f64 value = std::any_cast<f64>(visit(context->real_value()));

  set_memory(address, value);

  return nullptr;
}
