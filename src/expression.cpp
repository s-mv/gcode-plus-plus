#include "bytecode.hpp"
#include "parser_antlr4.h"
#include <cmath>

antlrcpp::Any
gpp::BytecodeEmitter::visitExpression(parser_antlr4::ExpressionContext *ctx) {
  return visit(ctx->logical_or_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_or_expression(
    parser_antlr4::Logical_or_expressionContext *ctx) {
  if (ctx->logical_or_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->logical_or_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->logical_xor_expression()));
    return (left != 0 || right != 0) ? 1.0 : 0.0;
  }
  return visit(ctx->logical_xor_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_xor_expression(
    parser_antlr4::Logical_xor_expressionContext *ctx) {
  if (ctx->logical_xor_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->logical_xor_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->logical_and_expression()));
    return ((left != 0) != (right != 0)) ? 1.0 : 0.0;
  }
  return visit(ctx->logical_and_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_and_expression(
    parser_antlr4::Logical_and_expressionContext *ctx) {
  if (ctx->logical_and_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->logical_and_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->equality_expression()));
    return (left != 0 && right != 0) ? 1.0 : 0.0;
  }
  return visit(ctx->equality_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitEquality_expression(
    parser_antlr4::Equality_expressionContext *ctx) {
  if (ctx->equality_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->equality_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->relational_expression()));
    if (ctx->EQ())
      return (left == right) ? 1.0 : 0.0;
    if (ctx->NE())
      return (left != right) ? 1.0 : 0.0;
  }
  return visit(ctx->relational_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitRelational_expression(
    parser_antlr4::Relational_expressionContext *ctx) {
  if (ctx->relational_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->relational_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->additive_expression()));
    if (ctx->LT())
      return (left < right) ? 1.0 : 0.0;
    if (ctx->LE())
      return (left <= right) ? 1.0 : 0.0;
    if (ctx->GT())
      return (left > right) ? 1.0 : 0.0;
    if (ctx->GE())
      return (left >= right) ? 1.0 : 0.0;
  }
  return visit(ctx->additive_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitAdditive_expression(
    parser_antlr4::Additive_expressionContext *ctx) {
  if (ctx->additive_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->additive_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->multiplicative_expression()));
    if (ctx->PLUS())
      return left + right;
    if (ctx->MINUS())
      return left - right;
  }
  return visit(ctx->multiplicative_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitMultiplicative_expression(
    parser_antlr4::Multiplicative_expressionContext *ctx) {
  if (ctx->multiplicative_expression()) {
    f64 left = std::any_cast<f64>(visit(ctx->multiplicative_expression()));
    f64 right = std::any_cast<f64>(visit(ctx->power_expression()));
    if (ctx->TIMES())
      return left * right;
    if (ctx->SLASH())
      return left / right;
    if (ctx->MODULO())
      return fmod(left, right);
  }
  return visit(ctx->power_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitPower_expression(
    parser_antlr4::Power_expressionContext *ctx) {
  if (ctx->POWER()) {
    f64 base = std::any_cast<f64>(visit(ctx->unary_expression()));
    f64 exponent = std::any_cast<f64>(visit(ctx->power_expression()));
    return std::pow(base, exponent);
  }
  return visit(ctx->unary_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitUnary_expression(
    parser_antlr4::Unary_expressionContext *ctx) {
  if (ctx->PLUS())
    return visit(ctx->unary_expression());
  if (ctx->MINUS())
    return -1.0 * std::any_cast<f64>(visit(ctx->unary_expression()));
  if (ctx->unary_combo())
    return visit(ctx->unary_combo());
  return visit(ctx->primary());
}

antlrcpp::Any
gpp::BytecodeEmitter::visitPrimary(parser_antlr4::PrimaryContext *ctx) {
  if (ctx->real_number())
    return stod(ctx->real_number()->getText());
  if (ctx->parameter_value())
    return visit(ctx->parameter_value()); // Implement as needed
  return visit(ctx->expression());
}