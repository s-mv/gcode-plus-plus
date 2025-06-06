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

TEST_CASE("g0, g1, g20, g21, g90, g91", "[bytecode]") {
  std::string code = readFile("examples/basic.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(instruction.arguments == std::vector<f64>{(f64)gpp::Unit::mm});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{1200});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 3});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(instruction.arguments == std::vector<f64>{(f64)gpp::Unit::inch});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::use_distance_mode);
  REQUIRE(instruction.arguments ==
          std::vector<f64>{gpp::DistanceMode::relative});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 50});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("g2, g3", "[bytecode]") {
  std::string code = readFile("examples/g2g3.cnc");

  gpp::Machine machine = gpp::Machine(code);

  std::string expected = "set_feed_rate(600)\n"
                         "move_rapid(0, 0, 0)\n"
                         "arc_feed(2, 0, 1, 0, 1, 0)\n"
                         "arc_feed(0, 0, 1, 0, -1, 0)\n"
                         "move_rapid(0, 0, 0)\n"
                         "arc_feed(2, 2, 1, 1, 1, 0)\n"
                         "arc_feed(0, 0, 1, 1, -1, 0)\n";

  std::ostringstream buffer;
  std::streambuf *oldBuffer = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());

  while (machine.next())
    ;

  std::cout.rdbuf(oldBuffer);

  std::string captured = buffer.str();

  REQUIRE(captured == expected);
}

TEST_CASE("if-else-if-else-end", "[bytecode]") {
  std::string code = readFile("examples/if.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{27, 9, 3});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("while/do-while", "[bytecode]") {
  std::string code = readFile("examples/while.cnc");

  gpp::Machine machine(code);
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);
  emitter.machine = &machine;

  gpp::Instruction instruction;

  for (f64 i = 3; i > 0; i--) {
    instruction = emitter.next();
    REQUIRE(instruction.command == gpp::Command::move_rapid);
    REQUIRE(instruction.arguments == std::vector<f64>{i, 0, 0});
  }

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{5, 0, 0});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("for", "[bytecode]") {
  std::string code = readFile("examples/for.cnc");

  gpp::Machine machine(code);
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);
  // unorthodox but for the test case, we have to do this
  emitter.machine = &machine;

  gpp::Instruction instruction;

  for (f64 i = 0; i < 3; i++) {
    for (f64 j = 0; j < 3; j++) {
      instruction = emitter.next();
      REQUIRE(instruction.command == gpp::Command::move_rapid);
      REQUIRE(instruction.arguments == std::vector<f64>{1, i, j});
    }
  }

  instruction = emitter.next();
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
