
// Generated from parser_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "parser_antlr4.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by parser_antlr4.
 */
class  parser_antlr4Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by parser_antlr4.
   */
    virtual std::any visitBlock(parser_antlr4::BlockContext *context) = 0;

    virtual std::any visitStatement(parser_antlr4::StatementContext *context) = 0;

    virtual std::any visitLine(parser_antlr4::LineContext *context) = 0;

    virtual std::any visitIf_statement(parser_antlr4::If_statementContext *context) = 0;

    virtual std::any visitWhile_statement(parser_antlr4::While_statementContext *context) = 0;

    virtual std::any visitDo_while_statement(parser_antlr4::Do_while_statementContext *context) = 0;

    virtual std::any visitFor_statement(parser_antlr4::For_statementContext *context) = 0;

    virtual std::any visitBreak_statement(parser_antlr4::Break_statementContext *context) = 0;

    virtual std::any visitContinue_statement(parser_antlr4::Continue_statementContext *context) = 0;

    virtual std::any visitBlock_delete(parser_antlr4::Block_deleteContext *context) = 0;

    virtual std::any visitLine_number(parser_antlr4::Line_numberContext *context) = 0;

    virtual std::any visitSegment(parser_antlr4::SegmentContext *context) = 0;

    virtual std::any visitMid_line_word(parser_antlr4::Mid_line_wordContext *context) = 0;

    virtual std::any visitMid_line_letter(parser_antlr4::Mid_line_letterContext *context) = 0;

    virtual std::any visitReal_value(parser_antlr4::Real_valueContext *context) = 0;

    virtual std::any visitReal_number(parser_antlr4::Real_numberContext *context) = 0;

    virtual std::any visitExpression(parser_antlr4::ExpressionContext *context) = 0;

    virtual std::any visitLogical_or_expression(parser_antlr4::Logical_or_expressionContext *context) = 0;

    virtual std::any visitLogical_xor_expression(parser_antlr4::Logical_xor_expressionContext *context) = 0;

    virtual std::any visitLogical_and_expression(parser_antlr4::Logical_and_expressionContext *context) = 0;

    virtual std::any visitEquality_expression(parser_antlr4::Equality_expressionContext *context) = 0;

    virtual std::any visitRelational_expression(parser_antlr4::Relational_expressionContext *context) = 0;

    virtual std::any visitAdditive_expression(parser_antlr4::Additive_expressionContext *context) = 0;

    virtual std::any visitMultiplicative_expression(parser_antlr4::Multiplicative_expressionContext *context) = 0;

    virtual std::any visitPower_expression(parser_antlr4::Power_expressionContext *context) = 0;

    virtual std::any visitUnary_expression(parser_antlr4::Unary_expressionContext *context) = 0;

    virtual std::any visitPrimary(parser_antlr4::PrimaryContext *context) = 0;

    virtual std::any visitUnary_combo(parser_antlr4::Unary_comboContext *context) = 0;

    virtual std::any visitOrdinary_unary_combo(parser_antlr4::Ordinary_unary_comboContext *context) = 0;

    virtual std::any visitOrdinary_unary_operation(parser_antlr4::Ordinary_unary_operationContext *context) = 0;

    virtual std::any visitArc_tangent_combo(parser_antlr4::Arc_tangent_comboContext *context) = 0;

    virtual std::any visitParameter_setting(parser_antlr4::Parameter_settingContext *context) = 0;

    virtual std::any visitParameter_value(parser_antlr4::Parameter_valueContext *context) = 0;

    virtual std::any visitParameter_index(parser_antlr4::Parameter_indexContext *context) = 0;

    virtual std::any visitComment(parser_antlr4::CommentContext *context) = 0;


};

