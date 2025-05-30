#include "bytecode.hpp"
#include "machine.hpp"
#include "util.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

TEST_CASE("g0, g1, g20, g21", "bytecode") {
  std::string code = read_file("examples/basic.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{1200});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 3});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{1, 2, 50});
}

TEST_CASE("if-else-if-else-end", "bytecode") {
  std::string code = read_file("examples/if.cnc");
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);

  gpp::Instruction instruction;

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(instruction.arguments == std::vector<f64>{250});

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_linear);
  REQUIRE(instruction.arguments == std::vector<f64>{27, 9, 3});
}

TEST_CASE("while/do-while", "bytecode") {
  std::string code = read_file("examples/while.cnc");

  gpp::Machine machine(code);
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(code);
  // unorthodox but for the test case, we have to do this
  emitter.machine = &machine;

  gpp::Instruction instruction;

  for (f64 i = 3; i > 0; i--) {
    instruction = emitter.next();
    REQUIRE(instruction.command == gpp::Command::move_rapid);
    REQUIRE(instruction.arguments == std::vector<f64>{i, 0, 0});
  }

  instruction = emitter.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(instruction.arguments == std::vector<f64>{0, 0, 0});
}
