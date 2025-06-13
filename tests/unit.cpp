#include "lexer_antlr4.h"
#include "parser_antlr4.h"

#include "bytecode.hpp"
#include "machine.hpp"
#include "util.hpp"

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

TEST_CASE("basic arithmetic", "[calculation]") {
  std::vector<std::string> expressions = {
      "[2 + 3 * [4 - 1]]",
      "[10 / [5 - 3] + 1]",
      "[[8 - 3] ** 2 + 1]",
      "[2 * -3 + 4]",
  };
  std::vector<f64> expected_results = {11, 6, 26, -2};

  for (size_t i = 0; i < expressions.size(); i++) {
    const std::string &input = expressions[i];

    antlr4::ANTLRInputStream inputStream(input);
    lexer_antlr4 lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser_antlr4 parser(&tokens);

    parser_antlr4::ExpressionContext *tree = parser.expression();

    gpp::BytecodeEmitter emitter(input);
    f64 result = std::any_cast<f64>(emitter.visit(tree));

    REQUIRE(result == Catch::Approx(expected_results[i]));
  }
}

TEST_CASE("g0, g1, g20, g21, g90, g91", "[g-code]") {
  std::string code = readFile("examples/basic.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(instruction.arguments == std::vector<f64>{(f64)gpp::Unit::mm});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{1200});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 3});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(instruction.arguments == std::vector<f64>{(f64)gpp::Unit::inch});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_distance_mode);
  REQUIRE(instruction.arguments ==
          std::vector<f64>{gpp::DistanceMode::relative});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 50});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("g2, g3", "[g-code]") {
  std::string code = readFile("examples/g2g3.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{600});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{0, 0, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(instruction.arguments == std::vector<f64>{2, 0, 1, 0, 1, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(instruction.arguments == std::vector<f64>{0, 0, 1, 0, -1, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{0, 0, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(instruction.arguments == std::vector<f64>{2, 2, 1, 1, 1, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(instruction.arguments == std::vector<f64>{0, 0, 1, 1, -1, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("if-else-if-else-end", "[bytecode]") {
  std::string code = readFile("examples/if.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{27, 9, 3});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("while/do-while", "[bytecode]") {
  std::string code = readFile("examples/while.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  for (f64 i = 3; i > 0; i--) {
    instruction = machine.next();
    REQUIRE(instruction.command == gpp::Command::move_rapid);
    REQUIRE(instruction.arguments == std::vector<f64>{i, 0, 0});
  }

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{5, 0, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("for", "[bytecode]") {
  std::string code = readFile("examples/for.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  for (f64 i = 0; i < 3; i++) {
    for (f64 j = 0; j < 3; j++) {
      instruction = machine.next();
      REQUIRE(instruction.command == gpp::Command::move_rapid);
      REQUIRE(instruction.arguments == std::vector<f64>{1, i, j});
    }
  }

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("trigonometric functions", "[calculation]") {
  std::vector<std::string> expressions = {
      "[sin 0]", "[cos 0]", "[sqrt 16]", "[abs -5]", "[exp 1]", "[ln 2.71828]",
  };
  std::vector<f64> expected_results = {0, 1, 4, 5, 2.71828, 1};

  for (size_t i = 0; i < expressions.size(); i++) {
    const std::string &input = expressions[i];

    antlr4::ANTLRInputStream inputStream(input);
    lexer_antlr4 lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    parser_antlr4 parser(&tokens);

    parser_antlr4::ExpressionContext *tree = parser.expression();

    gpp::BytecodeEmitter emitter(input);
    f64 result = std::any_cast<f64>(emitter.visit(tree));

    REQUIRE(result == Catch::Approx(expected_results[i]));
  }
}

TEST_CASE("m3, m4, m5", "[m-code]") {
  std::string code = readFile("examples/m3m4m5.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_spindle_speed);
  REQUIRE(instruction.arguments == std::vector<f64>{100});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::start_spindle_clockwise);
  REQUIRE(instruction.arguments == std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_spindle_speed);
  REQUIRE(instruction.arguments == std::vector<f64>{300});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::start_spindle_counterclockwise);
  REQUIRE(instruction.arguments == std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::stop_spindle_turning);
  REQUIRE(instruction.arguments == std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}
