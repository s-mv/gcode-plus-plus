#include "bytecode.hpp"
#include "gpp.hpp"
#include "parser_antlr4.h"
#include <cmath>
#include <type_traits>

antlrcpp::Any gpp::BytecodeEmitter::visitExpression(
    parser_antlr4::ExpressionContext *context) {
  return visit(context->logical_or_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_or_expression(
    parser_antlr4::Logical_or_expressionContext *context) {
  if (context->logical_or_expression()) {
    f64 left = std::any_cast<f64>(visit(context->logical_or_expression()));
    f64 right = std::any_cast<f64>(visit(context->logical_xor_expression()));
    return (left != 0 || right != 0) ? 1.0 : 0.0;
  }
  return visit(context->logical_xor_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_xor_expression(
    parser_antlr4::Logical_xor_expressionContext *context) {
  if (context->logical_xor_expression()) {
    f64 left = std::any_cast<f64>(visit(context->logical_xor_expression()));
    f64 right = std::any_cast<f64>(visit(context->logical_and_expression()));
    return ((left != 0) != (right != 0)) ? 1.0 : 0.0;
  }
  return visit(context->logical_and_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitLogical_and_expression(
    parser_antlr4::Logical_and_expressionContext *context) {
  if (context->logical_and_expression()) {
    f64 left = std::any_cast<f64>(visit(context->logical_and_expression()));
    f64 right = std::any_cast<f64>(visit(context->equality_expression()));
    return (left != 0 && right != 0) ? 1.0 : 0.0;
  }
  return visit(context->equality_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitEquality_expression(
    parser_antlr4::Equality_expressionContext *context) {
  if (context->equality_expression()) {
    f64 left = std::any_cast<f64>(visit(context->equality_expression()));
    f64 right = std::any_cast<f64>(visit(context->relational_expression()));
    if (context->EQ())
      return (left == right) ? 1.0 : 0.0;
    if (context->NE())
      return (left != right) ? 1.0 : 0.0;
  }
  return visit(context->relational_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitRelational_expression(
    parser_antlr4::Relational_expressionContext *context) {
  if (context->relational_expression()) {
    f64 left = std::any_cast<f64>(visit(context->relational_expression()));
    f64 right = std::any_cast<f64>(visit(context->additive_expression()));
    if (context->LT())
      return (left < right) ? 1.0 : 0.0;
    if (context->LE())
      return (left <= right) ? 1.0 : 0.0;
    if (context->GT())
      return (left > right) ? 1.0 : 0.0;
    if (context->GE())
      return (left >= right) ? 1.0 : 0.0;
  }
  return visit(context->additive_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitAdditive_expression(
    parser_antlr4::Additive_expressionContext *context) {
  if (context->additive_expression()) {
    f64 left = std::any_cast<f64>(visit(context->additive_expression()));
    f64 right = std::any_cast<f64>(visit(context->multiplicative_expression()));
    if (context->PLUS())
      return left + right;
    if (context->MINUS())
      return left - right;
  }
  return visit(context->multiplicative_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitMultiplicative_expression(
    parser_antlr4::Multiplicative_expressionContext *context) {
  if (context->multiplicative_expression()) {
    f64 left = std::any_cast<f64>(visit(context->multiplicative_expression()));
    f64 right = std::any_cast<f64>(visit(context->power_expression()));
    if (context->TIMES())
      return left * right;
    if (context->SLASH()) {
      if (right == 0) {
        verboseInstructions.push_back(
            {.word = 'e',
             .instruction =
                 gpp::Error(ErrorType::MATH_ERROR, "Division by zero!",
                            getLineFromSource(line))});

        return NAN;
      }

      return left / right;
    }
    if (context->MODULO())
      return fmod(left, right);
  }
  return visit(context->power_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitPower_expression(
    parser_antlr4::Power_expressionContext *context) {
  if (context->POWER()) {
    f64 base = std::any_cast<f64>(visit(context->unary_expression()));
    f64 exponent = std::any_cast<f64>(visit(context->power_expression()));
    return std::pow(base, exponent);
  }
  return visit(context->unary_expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitUnary_expression(
    parser_antlr4::Unary_expressionContext *context) {
  if (context->PLUS())
    return visit(context->unary_expression());
  if (context->MINUS())
    return -1.0 * std::any_cast<f64>(visit(context->unary_expression()));
  if (context->unary_combo())
    return visit(context->unary_combo());
  return visit(context->primary());
}

antlrcpp::Any
gpp::BytecodeEmitter::visitPrimary(parser_antlr4::PrimaryContext *context) {
  if (context->real_number())
    return stod(context->real_number()->getText());
  if (context->parameter_value())
    return visit(context->parameter_value());
  return visit(context->expression());
}

antlrcpp::Any gpp::BytecodeEmitter::visitUnary_combo(
    parser_antlr4::Unary_comboContext *context) {
  if (context->ordinary_unary_combo()) {
    return visit(context->ordinary_unary_combo());
  }
  return visit(context->arc_tangent_combo());
}

antlrcpp::Any gpp::BytecodeEmitter::visitOrdinary_unary_combo(
    parser_antlr4::Ordinary_unary_comboContext *context) {
  parser_antlr4::Ordinary_unary_operationContext *operation =
      context->ordinary_unary_operation();
  f64 value = std::any_cast<f64>(visit(context->expression()));
  if (operation->ABSOLUTE_VALUE())
    return std::abs(value);
  if (operation->ARC_COSINE())
    return std::acos(value);
  if (operation->ARC_SINE())
    return std::asin(value);
  if (operation->COSINE())
    return std::cos(value);
  if (operation->E_RAISED_TO())
    return std::exp(value);
  if (operation->FIX_DOWN())
    return std::floor(value);
  if (operation->FIX_UP())
    return std::ceil(value);
  if (operation->NATURAL_LOG_OF())
    return std::log(value);
  if (operation->ROUND_OPERATION())
    return std::round(value);
  if (operation->SINE())
    return std::sin(value);
  if (operation->SQUARE_ROOT())
    return std::sqrt(value);
  if (operation->TANGENT())
    return std::tan(value);

  return NAN;
}

antlrcpp::Any gpp::BytecodeEmitter::visitArc_tangent_combo(
    parser_antlr4::Arc_tangent_comboContext *context) {
  f64 x = std::any_cast<f64>(visit(context->expression(0)));
  f64 y = std::any_cast<f64>(visit(context->expression(1)));

  if (y == 0) {
    verboseInstructions.push_back(
        {.word = 'e',
         .instruction = gpp::Error(ErrorType::MATH_ERROR, "Division by zero!",
                                   getLineFromSource(line))});

    return NAN;
  }

  return std::atan(x / y);
}
