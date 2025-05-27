#include <cmath>
#include <vector>

#include "bytecode.hpp"

#include "lexer_antlr4.h"
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

// helper functions
f64 find_modal_group(f64 code);

g_bytecode_emitter::g_bytecode_emitter(std::string input)
    : inputStream(input), lexer(&inputStream), tokens(&lexer), parser(&tokens) {
  program = parser.program();
  line_pointer = 0;
}

g_instruction g_bytecode_emitter::next() {
  while (bytecode.empty()) {
    // fetch instructions first
    if (line_pointer < program->line().size())
      visit(program->line().at(line_pointer++));
    else
      return g_instruction{.command = no_command};
    // TODO, if/while
  }

  g_instruction front = bytecode.front();
  bytecode.pop();
  return front;
}

void g_bytecode_emitter::run(parser_antlr4::ProgramContext *context) {
  this->visitProgram(context);
}

antlrcpp::Any
g_bytecode_emitter::visitProgram(parser_antlr4::ProgramContext *context) {
  for (parser_antlr4::LineContext *line : context->line()) {
    visit(line);
  }
  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitLine(parser_antlr4::LineContext *context) {
  words.clear();

  for (parser_antlr4::SegmentContext *segment : context->segment()) {
    visit(segment);
  }

  for (g_word word : words) {
    if (word.word == 'g') {
      if (word.arg == 0) {
        f64 x, y, z;
        for (g_word operand : words) {
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
            .parameterized_args = 0, // for now
        });

      } else if (word.arg == 1) {
        f64 x, y, z, f;
        for (g_word operand : words) {
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
            .parameterized_args = 0,
        });

        bytecode.push({
            .command = move_linear,
            .arguments = arguments_linear_move,
            .parameterized_args = 0,
        });

      } else if (word.arg == 20) {
        g_instruction instruction = {
            .command = set_unit_in,
        };

        bytecode.push(instruction);
      } else if (word.arg == 20) {
        g_instruction instruction = {
            .command = set_unit_mm,
        };

        bytecode.push(instruction);
      }
    }
  }

  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitSegment(parser_antlr4::SegmentContext *context) {
  if (context->mid_line_word()) {
    visit(context->mid_line_word());
  } else if (context->parameter_setting()) {
    visit(context->parameter_setting());
  } else if (context->comment()) {
    visit(context->comment());
  }
  return nullptr;
}

antlrcpp::Any g_bytecode_emitter::visitMid_line_word(
    parser_antlr4::Mid_line_wordContext *context) {
  char letter = std::tolower(context->mid_line_letter()->getText().at(0));
  f64 value = std::any_cast<f64>(visit(context->real_value()));
  i64 value_asint = static_cast<i64>(value);
  int current_mode;

  words.push_back({letter, value});

  switch (letter) {
  case 'g':
    // check if g's modal group has any issues
    current_mode = find_modal_group(value);

    // TODO, check modes
    // if (mode == current_mode) {
    //   std::cerr << "WARNING: Using two modal groups beloning to mode " <<
    //   mode << " in the same line!\n" /* TODO throw an error */;
    //   return nullptr;
    // }
  }

  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitReal_value(parser_antlr4::Real_valueContext *context) {
  if (context->real_number()) {
    return visit(context->real_number());
  } else if (context->expression()) {
    return visit(context->expression());
  } else if (context->parameter_value()) {
    // TODO: Handle parameter_value
  } else if (context->unary_combo()) {
    // TODO: Handle unary_combo
  }
  return 0.0;
}

antlrcpp::Any g_bytecode_emitter::visitReal_number(
    parser_antlr4::Real_numberContext *context) {
  return std::stod(context->getText());
}

antlrcpp::Any
g_bytecode_emitter::visitComment(parser_antlr4::CommentContext *context) {
  std::string text = context->getText();
  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitExpression(parser_antlr4::ExpressionContext *context) {
  f64 value = std::any_cast<f64>(visit(context->real_value(0)));
  /* MAJOR TODO */
  return nullptr;
}

void g_bytecode_emitter::print() {}

f64 find_modal_group(f64 code) {
  for (int i = 0; i < modal_groups_len; i++) {
    for (int j = 0; modal_groups[i][j] != -1; j++) {
      if (modal_groups[i][j] == code)
        return i;
    }
  }

  return -1;
}
