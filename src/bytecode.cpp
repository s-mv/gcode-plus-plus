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
    : source(input), inputStream(input), lexer(&inputStream), tokens(&lexer),
      parser(&tokens) {
  executionStack.push({.block = parser.block(), .linePointer = 0});
}

gpp::Instruction gpp::BytecodeEmitter::next() {
  while (bytecode.empty()) {
    if (executionStack.empty())
      return {no_command};

    ExecutionFrame &frame = executionStack.top();
    std::vector<parser_antlr4::StatementContext *> statements =
        frame.block->statement();

    if (breakEncountered) {
      breakEncountered = false;

      while (!executionStack.empty()) {
        ExecutionFrame &currentFrame = executionStack.top();

        executionStack.pop();

        if (!currentFrame.loopCounterAddress.empty() ||
            currentFrame.whileLoopCondition != nullptr) {
          break;
        }
      }
      continue;
    }

    if (continueEncountered) {
      continueEncountered = false;

      // this is wonky but it works
      std::stack<ExecutionFrame> tempStack;
      bool foundLoop = false;

      while (!executionStack.empty()) {
        ExecutionFrame currentFrame = executionStack.top();
        executionStack.pop();

        bool isLoop = !currentFrame.loopCounterAddress.empty() ||
                      currentFrame.whileLoopCondition != nullptr;

        if (isLoop && !foundLoop) {
          foundLoop = true;

          if (!currentFrame.loopCounterAddress.empty()) {
            f64 value =
                getMemory(currentFrame.loopCounterAddress) + currentFrame.step;
            setMemory(currentFrame.loopCounterAddress, value);

            if (value < currentFrame.end) {
              currentFrame.linePointer = 0;
              executionStack.push(currentFrame);
            }
          } else if (currentFrame.whileLoopCondition != nullptr) {
            currentFrame.linePointer = 0;
            executionStack.push(currentFrame);
          }
          break;
        } else {
          tempStack.push(currentFrame);
        }
      }

      while (!tempStack.empty()) {
        executionStack.push(tempStack.top());
        tempStack.pop();
      }

      continue;
    }

    if (frame.linePointer >= statements.size()) {
      if (!frame.loopCounterAddress.empty()) {
        f64 value = getMemory(frame.loopCounterAddress) + frame.step;
        // TODO make an increment/stepBy function for this
        setMemory(frame.loopCounterAddress, value);

        if (value < frame.end) {
          frame.linePointer = 0;
          continue;
        } else {
          executionStack.pop();
          continue;
        }
      } else if (frame.whileLoopCondition == nullptr) {
        executionStack.pop();
        continue;
      }

      f64 condition = std::any_cast<f64>(visit(frame.whileLoopCondition));

      if (condition != 0.0) {
        frame.linePointer = 0;
        continue;
      } else {
        executionStack.pop();
        continue;
      }
    }

    visit(statements.at(frame.linePointer++));
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
  if (std::any_cast<f64>(visit(context->expression())) == 0)
    return nullptr;

  executionStack.push({
      .block = context->block(),
      .linePointer = 0,
      .whileLoopCondition = context->expression(),
  });

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitDo_while_statement(
    parser_antlr4::Do_while_statementContext *context) {
  executionStack.push({
      .block = context->block(),
      .linePointer = 0,
      .whileLoopCondition = context->expression(),
  });

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitFor_statement(
    parser_antlr4::For_statementContext *context) {
  std::string address;
  if (context->parameter_value()->NAMED_PARAMETER()) {
    address =
        context->parameter_value()->NAMED_PARAMETER()->getText().substr(1);
  } else {
    f64 address_value =
        std::any_cast<f64>(visit(context->parameter_value()->primary()));
    address = std::to_string((int)address_value);
  }

  f64 start = std::any_cast<f64>(visit(context->expression().at(0)));
  f64 end = std::any_cast<f64>(visit(context->expression().at(1)));

  setMemory(address, start);

  executionStack.push({
      .block = context->block(),
      .linePointer = 0,
      .loopCounterAddress = address,
      .start = start,
      .end = end,
  });

  setMemory(address, start);

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

  words.push_back({letter, value});

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_value(
    parser_antlr4::Real_valueContext *context) {
  if (context->real_number()) {
    return visit(context->real_number());
  } else if (context->expression()) {
    return visit(context->expression());
  }

  return 0.0;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_number(
    parser_antlr4::Real_numberContext *context) {
  return std::stod(context->getText());
}

void gpp::BytecodeEmitter::setMemory(std::string address, f64 value) {
  if (address.empty()) {
    return; // TODO, add an error
  }

  if (parameterAddresses.find(address) == parameterAddresses.end()) {
    parameterAddresses[address] = parameterAddresses.size();
  }

  int index = parameterAddresses.at(address);

  machine->setMemory(index, value);
}

f64 gpp::BytecodeEmitter::getMemory(std::string address) {
  if (address.empty()) {
    return NAN; // TODO, add an error
  }

  int index = parameterAddresses.at(address);

  return machine->getMemory(index);
}

antlrcpp::Any gpp::BytecodeEmitter::visitParameter_value(
    parser_antlr4::Parameter_valueContext *context) {
  std::string address;
  if (context->NAMED_PARAMETER()) {
    address = context->NAMED_PARAMETER()->getText().substr(1);
  } else {
    f64 address_value = std::any_cast<f64>(visit(context->primary()));
    address = std::to_string(address_value);
  }

  f64 value = getMemory(address);

  return value;
}

antlrcpp::Any gpp::BytecodeEmitter::visitParameter_setting(
    parser_antlr4::Parameter_settingContext *context) {
  std::string address;
  if (context->NAMED_PARAMETER()) {
    address = context->NAMED_PARAMETER()->getText().substr(1);
  } else {
    f64 address_value = std::any_cast<f64>(visit(context->primary()));
    address = std::to_string((int)address_value);
  }

  f64 value = std::any_cast<f64>(visit(context->real_value()));

  setMemory(address, value);

  return nullptr;
}

std::string gpp::BytecodeEmitter::getLineFromSource(int target) {
  std::istringstream stream(source);
  std::string line;
  int currentLine = 1;
  while (std::getline(stream, line)) {
    if (currentLine == target)
      return line;
    currentLine++;
  }
  return "(source line not available)";
}
