#include <any>
#include <cmath>
#include <cstddef>
#include <string>

#include "bytecode.hpp"
#include "machine.hpp"

#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include "support/Any.h"
#include "util.hpp"

gpp::BytecodeEmitter::BytecodeEmitter(std::string input)
    : inputStream(input), lexer(&inputStream), tokens(&lexer), parser(&tokens),
      looping(false), breakEncountered(false), continueEncountered(false) {
  executionStack.push({parser.block(), 0});
}

gpp::Instruction gpp::BytecodeEmitter::next() {
  while (bytecode.empty()) {
    if (executionStack.empty())
      return {no_command};

    ExecutionFrame &frame = executionStack.top();
    std::vector<parser_antlr4::StatementContext *> statements =
        frame.block->statement();

    if (frame.linePointer >= statements.size()) {
      if (frame.looping == nullptr) {
        executionStack.pop();
        continue;
      }

      f64 condition = std::any_cast<f64>(visit(frame.looping));

      if (condition != 0.0) {
        frame.linePointer = 0;
        continue;
      } else {
        executionStack.pop();
        continue;
      }
    }

    continueEncountered = false;
    breakEncountered = false;

    visit(statements.at(frame.linePointer++));

    if (breakEncountered) {
      executionStack.pop();
    }

    if (continueEncountered && frame.looping) {
      frame.linePointer = statements.size();
    }
  }

  Instruction front = bytecode.front();
  bytecode.pop();
  return front;
}

antlrcpp::Any
gpp::BytecodeEmitter::visitSegment(parser_antlr4::SegmentContext *context) {
  if (context->mid_line_word()) {
    visit(context->mid_line_word());
  } else if (context->parameter_setting()) {
    visit(context->parameter_setting());
  } else if (context->comment()) {
    visit(context->comment());
  }
  return nullptr;
}

antlrcpp::Any
gpp::BytecodeEmitter::visitBlock(parser_antlr4::BlockContext *context) {
  executionStack.push({context, 0});

  for (parser_antlr4::StatementContext *statement : context->statement()) {
    visit(statement);
  }

  executionStack.pop();

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitIf_statement(
    parser_antlr4::If_statementContext *context) {
  if (std::any_cast<f64>(visit(context->expression(0))) != 0) {
    visit(context->block(0));
    return nullptr;
  }

  size_t numElifs = context->IF().size() - 1;
  for (size_t i = 0; i < numElifs; i++) {
    auto expr = context->expression(i + 1);
    if (std::any_cast<f64>(visit(expr)) != 0) {
      visit(context->block(i + 1));
      return nullptr;
    }
  }

  if (context->ELSE().size() == numElifs + 1) {
    visit(context->block().back());
  }

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitWhile_statement(
    parser_antlr4::While_statementContext *context) {
  executionStack.push({
      context->block(),
      0,
      context->expression(),
  });

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitDo_while_statement(
    parser_antlr4::Do_while_statementContext *context) {
  executionStack.push({
      context->block(),
      0,
      context->expression(),
  });

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitBreak_statement(
    parser_antlr4::Break_statementContext *context) {
  breakEncountered = true;
  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitContinue_statement(
    parser_antlr4::Continue_statementContext *context) {
  continueEncountered = true;
  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitMid_line_word(
    parser_antlr4::Mid_line_wordContext *context) {
  char letter = std::tolower(context->mid_line_letter()->getText().at(0));
  f64 value = std::any_cast<f64>(visit(context->real_value()));
  i64 value_asint = static_cast<i64>(value);
  int current_mode;

  words.push_back({letter, value});

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_value(
    parser_antlr4::Real_valueContext *context) {
  if (context->real_number()) {
    return visit(context->real_number());
  } else if (context->expression()) {
    return visit(context->expression());
  } else if (context->parameter_value()) {
    // return ;
  } else if (context->unary_combo()) {
    // TODO
  }

  return 0.0;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_number(
    parser_antlr4::Real_numberContext *context) {
  return std::stod(context->getText());
}

void gpp::BytecodeEmitter::set_memory(i64 address, f64 value) {
  machine->set_memory(address, value);
}

f64 gpp::BytecodeEmitter::get_memory(i64 address) {
  return machine->get_memory(address);
}
