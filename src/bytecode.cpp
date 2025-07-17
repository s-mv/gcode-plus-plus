#include <any>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <string>

#include "bytecode.hpp"
#include "machine.hpp"

#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include "support/Any.h"
#include "util.hpp"

#ifndef GPP_LOCAL
extern int fetchHALParameter(const char *nameBuf, double *value);
extern int setHALParameter(const char *nameBuf, double *value);
#else
static int fetchHALParameter(const char *, double *value) { return value = -1; }
static int setHALParameter(const char *, double *value) { return value = -1;};
#endif

gpp::BytecodeEmitter::BytecodeEmitter(gpp::Machine &machine, std::string input)
    : inputStream(input), machine(&machine), lexer(&inputStream),
      tokens(&lexer), parser(&tokens) {
  executionStack.push({.block = parser.block(), .linePointer = 0});
  preprocess(executionStack.top().block);
}

gpp::BytecodeEmitter::BytecodeEmitter(gpp::Machine &machine)
    : inputStream(machine.input), machine(&machine), lexer(&inputStream),
      tokens(&lexer), parser(&tokens) {
  executionStack.push({.block = parser.block(), .linePointer = 0});
  preprocess(executionStack.top().block);
}

void gpp::BytecodeEmitter::preprocess(parser_antlr4::BlockContext *block) {
  for (parser_antlr4::StatementContext *statement : block->statement()) {
    if (statement->subroutine()) {
      parser_antlr4::SubroutineContext *subroutine = statement->subroutine();
      f64 address = std::any_cast<f64>(visit(subroutine->real_value()));
      subroutines.insert({address, subroutine});
      preprocess(subroutine->block());
    } else if (statement->if_statement()) {
      for (auto block : statement->if_statement()->block()) {
        preprocess(block);
      }
    } else if (statement->while_statement()) {
      preprocess(statement->while_statement()->block());
    } else if (statement->do_while_statement()) {
      preprocess(statement->do_while_statement()->block());
    } else if (statement->for_statement()) {
      preprocess(statement->for_statement()->block());
    }
  }
}

bool gpp::BytecodeEmitter::fetchInstructions() {
  while (verboseInstructions.empty()) {
    if (executionStack.empty())
      return false;

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
            f64 value = machine->getMemory(currentFrame.loopCounterAddress) +
                        currentFrame.step;
            machine->setMemory(currentFrame.loopCounterAddress, value);

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
        f64 value = machine->getMemory(frame.loopCounterAddress) + frame.step;
        machine->setMemory(frame.loopCounterAddress, value);

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

  return true;
}

antlrcpp::Any gpp::BytecodeEmitter::visitSubroutine(
    parser_antlr4::SubroutineContext *context) {
  if (subroutineEncountered) {
    int line = context->getStart()->getLine();
    int column = context->getStart()->getCharPositionInLine();

    bytecode.push_back(gpp::Error(ErrorType::PARSE_ERROR,
                                  "Nested subroutines aren't allowed!",
                                  getLineFromSource(line), line, column));
    return nullptr;
  }

  // TODO, check if the subroutine has an unconditional M99 at the end
  // if (!containsUnconditionalM99(context->block())) {
  //   int line = context->getStart()->getLine();
  //   int column = context->getStart()->getCharPositionInLine();
  // // TODO 2.0 replace with gpp::Error when uncommented
  // prettyPrintError("Subroutine may not return (missing unconditional
  //   M99).",
  //                    getLineFromSource(line), line, column);
  //   exit(1);
  // }

  subroutineEncountered = true;

  f64 address = std::any_cast<f64>(visit(context->real_value()));
  subroutines.insert({address, context});

  subroutineEncountered = false;

  return nullptr;
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

  machine->setMemory(address, start);

  executionStack.push({
      .block = context->block(),
      .linePointer = 0,
      .loopCounterAddress = address,
      .start = start,
      .end = end,
  });

  machine->setMemory(address, start);

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

  std::any result = visit(context->real_value());
  if (auto ptr = std::any_cast<f64>(&result)) {
    f64 value = std::any_cast<f64>(visit(context->real_value()));

    words.push_back({letter, value});
  } else {
    words.push_back({letter, NAN});
  }

  return nullptr;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_value(
    parser_antlr4::Real_valueContext *context) {
  if (context->real_number()) {
    return visit(context->real_number());
  } else if (context->expression()) {
    return visit(context->expression());
  }

  return NAN;
}

antlrcpp::Any gpp::BytecodeEmitter::visitReal_number(
    parser_antlr4::Real_numberContext *context) {
  return std::stod(context->getText());
}

antlrcpp::Any gpp::BytecodeEmitter::visitParameter_value(
    parser_antlr4::Parameter_valueContext *context) {
  std::string address;
  if (context->NAMED_PARAMETER()) {
    address = context->NAMED_PARAMETER()->getText().substr(1);
  } else {
    f64 address_value = std::any_cast<f64>(visit(context->primary()));
    address = std::to_string((int)address_value);
  }

  f64 value = NAN;

  if (address.compare(0, 6, "<_hal[") == 0 && address.back() == '>') {
    address = address.substr(1, address.length() - 2);
    int status = fetchHALParameter(address.c_str(), &value);
    return value;
  }

  value = machine->getMemory(address);

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

  if (address.compare(0, 6, "<_hal[") == 0 && address.back() == '>') {
    address = address.substr(1, address.length() - 2);
    int status = setHALParameter(address.c_str(), &value);
    return nullptr;
  }

  machine->setMemory(address, value);

  return nullptr;
}

std::string gpp::BytecodeEmitter::getLineFromSource(int target) {
  std::istringstream stream(machine->input);
  std::string line;
  int currentLine = 1;
  while (std::getline(stream, line)) {
    if (currentLine == target)
      return line;
    currentLine++;
  }
  return "(source line not available)";
}

bool gpp::BytecodeEmitter::lineHasM99(parser_antlr4::StatementContext *stmt) {
  auto line = dynamic_cast<parser_antlr4::LineContext *>(stmt);
  if (!line)
    return false;

  for (auto seg : line->segment()) {
    if (seg->getText() == "M99") {
      return true;
    }
  }
  return false;
}

bool gpp::BytecodeEmitter::ifStatementAlwaysReturns(
    parser_antlr4::If_statementContext *context) {
  bool allReturn = containsUnconditionalM99(context->block(0));

  size_t elifs = context->IF().size() - 1;
  for (size_t i = 0; i < elifs; ++i) {
    allReturn = allReturn && containsUnconditionalM99(context->block(i + 1));
  }

  if (context->ELSE().size() == elifs + 1) {
    allReturn = allReturn && containsUnconditionalM99(context->block().back());
  } else {
    return false;
  }

  return allReturn;
}

bool gpp::BytecodeEmitter::containsUnconditionalM99(
    parser_antlr4::BlockContext *context) {
  for (auto stmt : context->statement()) {
    if (lineHasM99(stmt))
      return true;

    if (auto ifstmt =
            dynamic_cast<parser_antlr4::If_statementContext *>(stmt)) {
      if (ifStatementAlwaysReturns(ifstmt))
        return true;
    }
  }
  return false;
}
