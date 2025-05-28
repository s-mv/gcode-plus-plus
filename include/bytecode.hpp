#ifndef smv_gcodepp_bytecode_hpp
#define smv_gcodepp_bytecode_hpp

#include <queue>
#include <stack>
#include <vector>

#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include "parser_antlr4BaseVisitor.h"
#include "util.hpp"

struct g_word {
  char word;
  f64 arg;
};

#define g_command_len (5)
enum g_command : u8 {
  move_linear = 0,
  move_rapid = 1,

  set_feed_rate = 2,

  set_unit_in = 3,
  set_unit_mm = 4,

  no_command = 255, // invalid
};

struct g_instruction {
  g_command command;
  std::vector<f64> arguments;
  u16 parameterized_args;
};

struct g_execution_frame {
  parser_antlr4::BlockContext *block;
  i64 line_pointer;
};

class g_bytecode_emitter : public parser_antlr4BaseVisitor {
private:
  char word;
  std::vector<u8> modes; // TODO
  std::vector<g_word> words;

  std::queue<g_instruction> bytecode;

  antlr4::ANTLRInputStream inputStream;
  lexer_antlr4 lexer;
  antlr4::CommonTokenStream tokens;
  parser_antlr4 parser;

  std::stack<g_execution_frame> execution_stack;

public:
  g_bytecode_emitter(std::string input);
  g_instruction next();
  void print();

private:
  antlrcpp::Any visitBlock(parser_antlr4::BlockContext *context) override;
  antlrcpp::Any visitIf_block(parser_antlr4::If_blockContext *context) override;
  antlrcpp::Any
  visitWhile_block(parser_antlr4::While_blockContext *context) override;

  antlrcpp::Any visitLine(parser_antlr4::LineContext *context) override;
  antlrcpp::Any visitSegment(parser_antlr4::SegmentContext *context) override;
  antlrcpp::Any
  visitMid_line_word(parser_antlr4::Mid_line_wordContext *context) override;
  antlrcpp::Any
  visitReal_value(parser_antlr4::Real_valueContext *context) override;
  antlrcpp::Any
  visitReal_number(parser_antlr4::Real_numberContext *context) override;

  antlrcpp::Any visitExpression(parser_antlr4::ExpressionContext *ctx) override;
  antlrcpp::Any visitLogical_or_expression(
      parser_antlr4::Logical_or_expressionContext *ctx) override;
  antlrcpp::Any visitLogical_xor_expression(
      parser_antlr4::Logical_xor_expressionContext *ctx) override;
  antlrcpp::Any visitLogical_and_expression(
      parser_antlr4::Logical_and_expressionContext *ctx) override;
  antlrcpp::Any visitEquality_expression(
      parser_antlr4::Equality_expressionContext *ctx) override;
  antlrcpp::Any visitRelational_expression(
      parser_antlr4::Relational_expressionContext *ctx) override;
  antlrcpp::Any visitAdditive_expression(
      parser_antlr4::Additive_expressionContext *ctx) override;
  antlrcpp::Any visitMultiplicative_expression(
      parser_antlr4::Multiplicative_expressionContext *ctx) override;
  antlrcpp::Any
  visitPower_expression(parser_antlr4::Power_expressionContext *ctx) override;
  antlrcpp::Any
  visitUnary_expression(parser_antlr4::Unary_expressionContext *ctx) override;
  antlrcpp::Any visitPrimary(parser_antlr4::PrimaryContext *ctx) override;
};

#endif
