
// Generated from parser_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "parser_antlr4Visitor.h"


/**
 * This class provides an empty implementation of parser_antlr4Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  parser_antlr4BaseVisitor : public parser_antlr4Visitor {
public:

  virtual std::any visitBlock(parser_antlr4::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(parser_antlr4::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLine(parser_antlr4::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_statement(parser_antlr4::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_statement(parser_antlr4::While_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDo_while_statement(parser_antlr4::Do_while_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_statement(parser_antlr4::For_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_statement(parser_antlr4::Break_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinue_statement(parser_antlr4::Continue_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_delete(parser_antlr4::Block_deleteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLine_number(parser_antlr4::Line_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSegment(parser_antlr4::SegmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMid_line_word(parser_antlr4::Mid_line_wordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMid_line_letter(parser_antlr4::Mid_line_letterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReal_value(parser_antlr4::Real_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReal_number(parser_antlr4::Real_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(parser_antlr4::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_or_expression(parser_antlr4::Logical_or_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical_and_expression(parser_antlr4::Logical_and_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEquality_expression(parser_antlr4::Equality_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelational_expression(parser_antlr4::Relational_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditive_expression(parser_antlr4::Additive_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPower_expression(parser_antlr4::Power_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_expression(parser_antlr4::Unary_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(parser_antlr4::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_combo(parser_antlr4::Unary_comboContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_setting(parser_antlr4::Parameter_settingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_value(parser_antlr4::Parameter_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComment(parser_antlr4::CommentContext *ctx) override {
    return visitChildren(ctx);
  }


};

