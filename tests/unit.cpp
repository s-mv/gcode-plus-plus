#include "bytecode.hpp"
#include "util.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

TEST_CASE("g0, g1, g20, g21", "bytecode") {
  std::string code = read_file("examples/basic.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{1200});

  instruction = emitter.next();
  REQUIRE(instruction.command == move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 3});

  instruction = emitter.next();
  REQUIRE(instruction.command == move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 50});
}

TEST_CASE("if-else-if-else-end", "bytecode") {
  std::string code = read_file("examples/if.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{250});

  instruction = emitter.next();
  REQUIRE(instruction.command == move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{27, 9, 3});
}

// TEST_CASE("while-do-end", "unit") {}

// TEST_CASE("do-while-end", "unit") {}
