#define smv_gpp_testing

#include "doctest.h"

#include "bytecode.hpp"
#include "lexer_antlr4.h"
#include "machine.hpp"
#include "parser_antlr4.h"
#include "util.hpp"

TEST_CASE("[calculation] basic arithmetic") {
  std::vector<std::string> expressions = {
      "[2 + 3 * [4 - 1]]",
      "[10 / [5 - 3] + 1]",
      "[[8 - 3] ** 2 + 1]",
      "[2 * -3 + 4]",
  };
  std::vector<f64> expected_results = {11, 6, 26, -2};
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  for (size_t i = 0; i < expressions.size(); i++) {
    const std::string &input = expressions[i];

    antlr4::ANTLRInputStream inputStream(input);
    lexer_antlr4 lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser_antlr4 parser(&tokens);

    parser_antlr4::ExpressionContext *tree = parser.expression();

    gpp::Machine machine(input);
    f64 result = std::any_cast<f64>(machine.emitter->visit(tree));

    CHECK(result == doctest::Approx(expected_results[i]));
  }
}

TEST_CASE("[calculation] trigonometric functions") {
  std::vector<std::string> expressions = {
      "[sin 0]", "[cos 0]", "[sqrt 16]", "[abs -5]", "[exp 1]", "[ln 2.71828]",
  };
  std::vector<f64> expected_results = {0, 1, 4, 5, 2.71828, 1};
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  for (size_t i = 0; i < expressions.size(); i++) {
    const std::string &input = expressions[i];

    antlr4::ANTLRInputStream inputStream(input);
    lexer_antlr4 lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser_antlr4 parser(&tokens);

    parser_antlr4::ExpressionContext *tree = parser.expression();

    gpp::Machine machine(input);
    f64 result = std::any_cast<f64>(machine.emitter->visit(tree));

    CHECK(result == doctest::Approx(expected_results[i]));
  }
}
