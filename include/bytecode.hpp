#ifndef smv_gpp_bytecode_hpp
#define smv_gpp_bytecode_hpp

#include <queue>
#include <stack>
#include <vector>

#include "gpp.hpp"
#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include "parser_antlr4BaseVisitor.h"
#include "util.hpp"

struct gpp::Word {
  char word;
  f64 arg;
};

struct gpp::Instruction {
  Command command;
  std::vector<f64> arguments;
};

struct gpp::ExecutionFrame {
  parser_antlr4::BlockContext *block;
  i64 linePointer;
  // TODO maybe turn this into a union
  // union {
  parser_antlr4::ExpressionContext *whileLoopCondition = nullptr;
  int loopCounterAddress = -1;
  // };
  f64 start;
  f64 step = 1;
  f64 end;
};

class gpp::BytecodeEmitter : public parser_antlr4BaseVisitor {
private:
  char word;
  std::vector<u8> modes; // TODO
  std::vector<Word> words;

  std::queue<Instruction> bytecode;
  bool looping;
  bool breakEncountered;
  bool continueEncountered;

  antlr4::ANTLRInputStream inputStream;
  lexer_antlr4 lexer;
  antlr4::CommonTokenStream tokens;
  parser_antlr4 parser;

  std::stack<gpp::ExecutionFrame> executionStack;

public:
  Machine *machine = nullptr;

  BytecodeEmitter(std::string input);
  Instruction next();

private:
  void set_memory(i64 address, f64 value);
  f64 get_memory(i64 address);

  antlrcpp::Any visitBlock(parser_antlr4::BlockContext *context) override;
  antlrcpp::Any
  visitIf_statement(parser_antlr4::If_statementContext *context) override;
  antlrcpp::Any
  visitWhile_statement(parser_antlr4::While_statementContext *context) override;
  antlrcpp::Any visitDo_while_statement(
      parser_antlr4::Do_while_statementContext *context) override;

  antlrcpp::Any
  visitBreak_statement(parser_antlr4::Break_statementContext *context) override;
  antlrcpp::Any visitContinue_statement(
      parser_antlr4::Continue_statementContext *context) override;
  antlrcpp::Any
  visitFor_statement(parser_antlr4::For_statementContext *context) override;

  antlrcpp::Any visitLine(parser_antlr4::LineContext *context) override;
  antlrcpp::Any visitSegment(parser_antlr4::SegmentContext *context) override;
  antlrcpp::Any
  visitMid_line_word(parser_antlr4::Mid_line_wordContext *context) override;
  antlrcpp::Any visitParameter_setting(
      parser_antlr4::Parameter_settingContext *context) override;
  antlrcpp::Any
  visitParameter_value(parser_antlr4::Parameter_valueContext *context) override;
  antlrcpp::Any
  visitReal_value(parser_antlr4::Real_valueContext *context) override;
  antlrcpp::Any
  visitReal_number(parser_antlr4::Real_numberContext *context) override;
  antlrcpp::Any
  visitUnary_combo(parser_antlr4::Unary_comboContext *context) override;
  antlrcpp::Any visitOrdinary_unary_combo(
      parser_antlr4::Ordinary_unary_comboContext *context) override;
  antlrcpp::Any visitArc_tangent_combo(
      parser_antlr4::Arc_tangent_comboContext *context) override;

  antlrcpp::Any
  visitExpression(parser_antlr4::ExpressionContext *context) override;
  antlrcpp::Any visitLogical_or_expression(
      parser_antlr4::Logical_or_expressionContext *context) override;
  antlrcpp::Any visitLogical_xor_expression(
      parser_antlr4::Logical_xor_expressionContext *context) override;
  antlrcpp::Any visitLogical_and_expression(
      parser_antlr4::Logical_and_expressionContext *context) override;
  antlrcpp::Any visitEquality_expression(
      parser_antlr4::Equality_expressionContext *context) override;
  antlrcpp::Any visitRelational_expression(
      parser_antlr4::Relational_expressionContext *context) override;
  antlrcpp::Any visitAdditive_expression(
      parser_antlr4::Additive_expressionContext *context) override;
  antlrcpp::Any visitMultiplicative_expression(
      parser_antlr4::Multiplicative_expressionContext *context) override;
  antlrcpp::Any visitPower_expression(
      parser_antlr4::Power_expressionContext *context) override;
  antlrcpp::Any visitUnary_expression(
      parser_antlr4::Unary_expressionContext *context) override;
  antlrcpp::Any visitPrimary(parser_antlr4::PrimaryContext *context) override;
};

#endif
