#ifndef smv_gcodepp_bytecode_hpp
#define smv_gcodepp_bytecode_hpp

#include <queue>
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

  parser_antlr4::ProgramContext *program;

  int line_pointer;

public:
  g_bytecode_emitter(std::string input);
  g_instruction next();
  void run(parser_antlr4::ProgramContext *context);
  void print();

private:
  antlrcpp::Any visitProgram(parser_antlr4::ProgramContext *context) override;
  antlrcpp::Any visitLine(parser_antlr4::LineContext *context) override;
  antlrcpp::Any visitSegment(parser_antlr4::SegmentContext *context) override;
  antlrcpp::Any
  visitMid_line_word(parser_antlr4::Mid_line_wordContext *context) override;
  antlrcpp::Any
  visitReal_value(parser_antlr4::Real_valueContext *context) override;
  antlrcpp::Any
  visitReal_number(parser_antlr4::Real_numberContext *context) override;
  antlrcpp::Any visitComment(parser_antlr4::CommentContext *context) override;
  antlrcpp::Any
  visitExpression(parser_antlr4::ExpressionContext *context) override;

  f64 evalBinary(f64 lhs, f64 rhs, const std::string &op);
};

#endif
