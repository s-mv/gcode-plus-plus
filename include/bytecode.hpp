#ifndef smv_gpp_bytecode_hpp
#define smv_gpp_bytecode_hpp

#include <cmath>
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "gpp.hpp"
#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include "parser_antlr4BaseVisitor.h"
#include "util.hpp"

#ifdef smv_gpp_testing
#define private public
#endif

struct gpp::Word {
  char word;
  f64 arg;
};

struct gpp::Instruction {
  Command command;
  std::vector<f64> arguments;
};

struct gpp::Error {
private:
  ErrorType type;
  std::string message;
  std::string source;
  int line = -1;
  int column = -1;
  bool recoverable = true;

public:
  Error(ErrorType t, const std::string &msg, const std::string &source,
        int line = -1, int column = -1, bool rec = true);
  void print() const;
  void updateSource(std::string &newSource);
};

using SafeInstruction = std::variant<gpp::Instruction, gpp::Error>;

struct gpp::VerboseInstruction {
  char word;
  f64 arg;
  int line = -1;
  int column = -1;
  bool commentOrMessage;
  SafeInstruction instruction;
};

bool compareVerboseInstructions(const gpp::VerboseInstruction &a,
                                const gpp::VerboseInstruction &b);

struct gpp::ExecutionFrame {
  parser_antlr4::BlockContext *block;
  i64 linePointer;
  i64 subroutineAddress = -1;
  parser_antlr4::ExpressionContext *whileLoopCondition = nullptr;
  std::string loopCounterAddress = "";
  f64 start;
  f64 step = 1;
  f64 end;
  bool breakEncountered = false;
  bool continueEncountered = false;
};

struct StickyArgs {
  f64 r = NAN, l = NAN, f = NAN, p = NAN, g = NAN;
};

class gpp::BytecodeEmitter : public parser_antlr4BaseVisitor {
  friend class Machine;

public:
  Machine *machine = nullptr;

  BytecodeEmitter(Machine &machine, std::string input);
  BytecodeEmitter(Machine &machine);
  void preprocess(parser_antlr4::BlockContext *block);
  bool fetchInstructions();

private:
  char word;
  std::vector<Word> words;
  std::deque<SafeInstruction> bytecode;
  std::deque<VerboseInstruction> verboseInstructions;
  StickyArgs stickyArgs;

  antlr4::ANTLRInputStream inputStream;
  lexer_antlr4 lexer;
  antlr4::CommonTokenStream tokens;
  parser_antlr4 parser;

  std::stack<gpp::ExecutionFrame> executionStack;
  std::unordered_map<u64, parser_antlr4::SubroutineContext *> subroutines;

  std::unordered_map<std::string, f64> parameterAddresses;
  bool breakEncountered = false;
  bool continueEncountered = false;
  bool subroutineEncountered = false;

  i64 currentSubroutine = -1;

  int line = 0;
  int column = 0;

private:
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
  visitSubroutine(parser_antlr4::SubroutineContext *context) override;

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

  //   helpers
  std::string getLineFromSource(int target);
  bool arcOffetsAligned(const Plane currentPlane, f64 i, f64 j, f64 k);
  void handle_g(std::deque<VerboseInstruction> &list, f64 arg,
                const std::vector<Word> &words, int line, int column);

  void handle_m(std::deque<VerboseInstruction> &list, f64 arg,
                const std::vector<Word> &words, int line, int column);

  bool lineHasM99(parser_antlr4::StatementContext *stmt);
  bool ifStatementAlwaysReturns(parser_antlr4::If_statementContext *context);
  bool containsUnconditionalM99(parser_antlr4::BlockContext *context);

  // helpers for instructions.cpp
  inline void applyCurrentPositionDefaults(Vec3D &delta);
  inline void extractCoordinates(const std::vector<Word> &words, f64 &x, f64 &y,
                                 f64 &z);
  inline void extractArcParams(const std::vector<Word> &words, f64 &x, f64 &y,
                               f64 &z, f64 &i, f64 &j, f64 &k, f64 &r);

  f64 findParameter(const std::vector<Word> &words, char letter);
  inline Vec2D getPlaneCoordinates(const Plane plane, const Vec3D &pos);
  inline Vec2D getCurrentPlanePosition(const Plane plane,
                                       const Vec3D &position);
  inline Vec2D getArcCenterOffsets(const gpp::Plane plane, f64 i, f64 j, f64 k);
};

#ifdef smv_gpp_testing
#undef private
#endif

#endif
