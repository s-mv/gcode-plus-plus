#ifndef smv_gcodepp_bytecode_hpp
#define smv_gcodepp_bytecode_hpp

#include "parser_antlr4.h"
#include "parser_antlr4BaseVisitor.h"
#include "util.hpp"

enum g_opcode : i64 {
  move_linear,
  set_parameter,
  rapid_move,
  set_x,
  set_y,
  set_z,
  set_feedrate,
};

union g_inst {
  g_opcode code;
  f64 attr;
};

class g_bytecode_emitter : public parser_antlr4BaseVisitor {
public:
  void run(parser_antlr4::ProgramContext *context);
  void print();

  std::vector<g_inst> bytecode;

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
};

#endif
