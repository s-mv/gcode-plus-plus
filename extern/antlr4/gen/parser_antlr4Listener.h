
// Generated from /home/smv/temp/linuxcnc-2.9.4/src/emc/sterp/antlr4/parser_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "parser_antlr4.h"


/**
 * This interface defines an abstract listener for a parse tree produced by parser_antlr4.
 */
class  parser_antlr4Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterBlock(parser_antlr4::BlockContext *ctx) = 0;
  virtual void exitBlock(parser_antlr4::BlockContext *ctx) = 0;

  virtual void enterStatement(parser_antlr4::StatementContext *ctx) = 0;
  virtual void exitStatement(parser_antlr4::StatementContext *ctx) = 0;

  virtual void enterSubroutine(parser_antlr4::SubroutineContext *ctx) = 0;
  virtual void exitSubroutine(parser_antlr4::SubroutineContext *ctx) = 0;

  virtual void enterM99(parser_antlr4::M99Context *ctx) = 0;
  virtual void exitM99(parser_antlr4::M99Context *ctx) = 0;

  virtual void enterLine(parser_antlr4::LineContext *ctx) = 0;
  virtual void exitLine(parser_antlr4::LineContext *ctx) = 0;

  virtual void enterIf_statement(parser_antlr4::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(parser_antlr4::If_statementContext *ctx) = 0;

  virtual void enterWhile_statement(parser_antlr4::While_statementContext *ctx) = 0;
  virtual void exitWhile_statement(parser_antlr4::While_statementContext *ctx) = 0;

  virtual void enterDo_while_statement(parser_antlr4::Do_while_statementContext *ctx) = 0;
  virtual void exitDo_while_statement(parser_antlr4::Do_while_statementContext *ctx) = 0;

  virtual void enterFor_statement(parser_antlr4::For_statementContext *ctx) = 0;
  virtual void exitFor_statement(parser_antlr4::For_statementContext *ctx) = 0;

  virtual void enterBreak_statement(parser_antlr4::Break_statementContext *ctx) = 0;
  virtual void exitBreak_statement(parser_antlr4::Break_statementContext *ctx) = 0;

  virtual void enterContinue_statement(parser_antlr4::Continue_statementContext *ctx) = 0;
  virtual void exitContinue_statement(parser_antlr4::Continue_statementContext *ctx) = 0;

  virtual void enterBlock_delete(parser_antlr4::Block_deleteContext *ctx) = 0;
  virtual void exitBlock_delete(parser_antlr4::Block_deleteContext *ctx) = 0;

  virtual void enterLine_number(parser_antlr4::Line_numberContext *ctx) = 0;
  virtual void exitLine_number(parser_antlr4::Line_numberContext *ctx) = 0;

  virtual void enterSegment(parser_antlr4::SegmentContext *ctx) = 0;
  virtual void exitSegment(parser_antlr4::SegmentContext *ctx) = 0;

  virtual void enterMid_line_word(parser_antlr4::Mid_line_wordContext *ctx) = 0;
  virtual void exitMid_line_word(parser_antlr4::Mid_line_wordContext *ctx) = 0;

  virtual void enterMid_line_letter(parser_antlr4::Mid_line_letterContext *ctx) = 0;
  virtual void exitMid_line_letter(parser_antlr4::Mid_line_letterContext *ctx) = 0;

  virtual void enterReal_value(parser_antlr4::Real_valueContext *ctx) = 0;
  virtual void exitReal_value(parser_antlr4::Real_valueContext *ctx) = 0;

  virtual void enterReal_number(parser_antlr4::Real_numberContext *ctx) = 0;
  virtual void exitReal_number(parser_antlr4::Real_numberContext *ctx) = 0;

  virtual void enterExpression(parser_antlr4::ExpressionContext *ctx) = 0;
  virtual void exitExpression(parser_antlr4::ExpressionContext *ctx) = 0;

  virtual void enterLogical_or_expression(parser_antlr4::Logical_or_expressionContext *ctx) = 0;
  virtual void exitLogical_or_expression(parser_antlr4::Logical_or_expressionContext *ctx) = 0;

  virtual void enterLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext *ctx) = 0;
  virtual void exitLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext *ctx) = 0;

  virtual void enterLogical_and_expression(parser_antlr4::Logical_and_expressionContext *ctx) = 0;
  virtual void exitLogical_and_expression(parser_antlr4::Logical_and_expressionContext *ctx) = 0;

  virtual void enterEquality_expression(parser_antlr4::Equality_expressionContext *ctx) = 0;
  virtual void exitEquality_expression(parser_antlr4::Equality_expressionContext *ctx) = 0;

  virtual void enterRelational_expression(parser_antlr4::Relational_expressionContext *ctx) = 0;
  virtual void exitRelational_expression(parser_antlr4::Relational_expressionContext *ctx) = 0;

  virtual void enterAdditive_expression(parser_antlr4::Additive_expressionContext *ctx) = 0;
  virtual void exitAdditive_expression(parser_antlr4::Additive_expressionContext *ctx) = 0;

  virtual void enterMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext *ctx) = 0;
  virtual void exitMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext *ctx) = 0;

  virtual void enterPower_expression(parser_antlr4::Power_expressionContext *ctx) = 0;
  virtual void exitPower_expression(parser_antlr4::Power_expressionContext *ctx) = 0;

  virtual void enterUnary_expression(parser_antlr4::Unary_expressionContext *ctx) = 0;
  virtual void exitUnary_expression(parser_antlr4::Unary_expressionContext *ctx) = 0;

  virtual void enterPrimary(parser_antlr4::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(parser_antlr4::PrimaryContext *ctx) = 0;

  virtual void enterUnary_combo(parser_antlr4::Unary_comboContext *ctx) = 0;
  virtual void exitUnary_combo(parser_antlr4::Unary_comboContext *ctx) = 0;

  virtual void enterOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext *ctx) = 0;
  virtual void exitOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext *ctx) = 0;

  virtual void enterOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext *ctx) = 0;
  virtual void exitOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext *ctx) = 0;

  virtual void enterArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext *ctx) = 0;
  virtual void exitArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext *ctx) = 0;

  virtual void enterParameter_setting(parser_antlr4::Parameter_settingContext *ctx) = 0;
  virtual void exitParameter_setting(parser_antlr4::Parameter_settingContext *ctx) = 0;

  virtual void enterParameter_value(parser_antlr4::Parameter_valueContext *ctx) = 0;
  virtual void exitParameter_value(parser_antlr4::Parameter_valueContext *ctx) = 0;

  virtual void enterComment(parser_antlr4::CommentContext *ctx) = 0;
  virtual void exitComment(parser_antlr4::CommentContext *ctx) = 0;


};

