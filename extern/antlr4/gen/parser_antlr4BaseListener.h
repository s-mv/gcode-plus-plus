
// Generated from parser_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "parser_antlr4Listener.h"


/**
 * This class provides an empty implementation of parser_antlr4Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  parser_antlr4BaseListener : public parser_antlr4Listener {
public:

  virtual void enterBlock(parser_antlr4::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(parser_antlr4::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(parser_antlr4::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(parser_antlr4::StatementContext * /*ctx*/) override { }

  virtual void enterSubroutine(parser_antlr4::SubroutineContext * /*ctx*/) override { }
  virtual void exitSubroutine(parser_antlr4::SubroutineContext * /*ctx*/) override { }

  virtual void enterM99(parser_antlr4::M99Context * /*ctx*/) override { }
  virtual void exitM99(parser_antlr4::M99Context * /*ctx*/) override { }

  virtual void enterLine(parser_antlr4::LineContext * /*ctx*/) override { }
  virtual void exitLine(parser_antlr4::LineContext * /*ctx*/) override { }

  virtual void enterIf_statement(parser_antlr4::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(parser_antlr4::If_statementContext * /*ctx*/) override { }

  virtual void enterWhile_statement(parser_antlr4::While_statementContext * /*ctx*/) override { }
  virtual void exitWhile_statement(parser_antlr4::While_statementContext * /*ctx*/) override { }

  virtual void enterDo_while_statement(parser_antlr4::Do_while_statementContext * /*ctx*/) override { }
  virtual void exitDo_while_statement(parser_antlr4::Do_while_statementContext * /*ctx*/) override { }

  virtual void enterFor_statement(parser_antlr4::For_statementContext * /*ctx*/) override { }
  virtual void exitFor_statement(parser_antlr4::For_statementContext * /*ctx*/) override { }

  virtual void enterBreak_statement(parser_antlr4::Break_statementContext * /*ctx*/) override { }
  virtual void exitBreak_statement(parser_antlr4::Break_statementContext * /*ctx*/) override { }

  virtual void enterContinue_statement(parser_antlr4::Continue_statementContext * /*ctx*/) override { }
  virtual void exitContinue_statement(parser_antlr4::Continue_statementContext * /*ctx*/) override { }

  virtual void enterBlock_delete(parser_antlr4::Block_deleteContext * /*ctx*/) override { }
  virtual void exitBlock_delete(parser_antlr4::Block_deleteContext * /*ctx*/) override { }

  virtual void enterLine_number(parser_antlr4::Line_numberContext * /*ctx*/) override { }
  virtual void exitLine_number(parser_antlr4::Line_numberContext * /*ctx*/) override { }

  virtual void enterSegment(parser_antlr4::SegmentContext * /*ctx*/) override { }
  virtual void exitSegment(parser_antlr4::SegmentContext * /*ctx*/) override { }

  virtual void enterMid_line_word(parser_antlr4::Mid_line_wordContext * /*ctx*/) override { }
  virtual void exitMid_line_word(parser_antlr4::Mid_line_wordContext * /*ctx*/) override { }

  virtual void enterMid_line_letter(parser_antlr4::Mid_line_letterContext * /*ctx*/) override { }
  virtual void exitMid_line_letter(parser_antlr4::Mid_line_letterContext * /*ctx*/) override { }

  virtual void enterReal_value(parser_antlr4::Real_valueContext * /*ctx*/) override { }
  virtual void exitReal_value(parser_antlr4::Real_valueContext * /*ctx*/) override { }

  virtual void enterReal_number(parser_antlr4::Real_numberContext * /*ctx*/) override { }
  virtual void exitReal_number(parser_antlr4::Real_numberContext * /*ctx*/) override { }

  virtual void enterExpression(parser_antlr4::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(parser_antlr4::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogical_or_expression(parser_antlr4::Logical_or_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_or_expression(parser_antlr4::Logical_or_expressionContext * /*ctx*/) override { }

  virtual void enterLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext * /*ctx*/) override { }

  virtual void enterLogical_and_expression(parser_antlr4::Logical_and_expressionContext * /*ctx*/) override { }
  virtual void exitLogical_and_expression(parser_antlr4::Logical_and_expressionContext * /*ctx*/) override { }

  virtual void enterEquality_expression(parser_antlr4::Equality_expressionContext * /*ctx*/) override { }
  virtual void exitEquality_expression(parser_antlr4::Equality_expressionContext * /*ctx*/) override { }

  virtual void enterRelational_expression(parser_antlr4::Relational_expressionContext * /*ctx*/) override { }
  virtual void exitRelational_expression(parser_antlr4::Relational_expressionContext * /*ctx*/) override { }

  virtual void enterAdditive_expression(parser_antlr4::Additive_expressionContext * /*ctx*/) override { }
  virtual void exitAdditive_expression(parser_antlr4::Additive_expressionContext * /*ctx*/) override { }

  virtual void enterMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext * /*ctx*/) override { }
  virtual void exitMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext * /*ctx*/) override { }

  virtual void enterPower_expression(parser_antlr4::Power_expressionContext * /*ctx*/) override { }
  virtual void exitPower_expression(parser_antlr4::Power_expressionContext * /*ctx*/) override { }

  virtual void enterUnary_expression(parser_antlr4::Unary_expressionContext * /*ctx*/) override { }
  virtual void exitUnary_expression(parser_antlr4::Unary_expressionContext * /*ctx*/) override { }

  virtual void enterPrimary(parser_antlr4::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(parser_antlr4::PrimaryContext * /*ctx*/) override { }

  virtual void enterUnary_combo(parser_antlr4::Unary_comboContext * /*ctx*/) override { }
  virtual void exitUnary_combo(parser_antlr4::Unary_comboContext * /*ctx*/) override { }

  virtual void enterOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext * /*ctx*/) override { }
  virtual void exitOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext * /*ctx*/) override { }

  virtual void enterOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext * /*ctx*/) override { }
  virtual void exitOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext * /*ctx*/) override { }

  virtual void enterArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext * /*ctx*/) override { }
  virtual void exitArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext * /*ctx*/) override { }

  virtual void enterParameter_setting(parser_antlr4::Parameter_settingContext * /*ctx*/) override { }
  virtual void exitParameter_setting(parser_antlr4::Parameter_settingContext * /*ctx*/) override { }

  virtual void enterParameter_value(parser_antlr4::Parameter_valueContext * /*ctx*/) override { }
  virtual void exitParameter_value(parser_antlr4::Parameter_valueContext * /*ctx*/) override { }

  virtual void enterComment(parser_antlr4::CommentContext * /*ctx*/) override { }
  virtual void exitComment(parser_antlr4::CommentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

