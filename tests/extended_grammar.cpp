#include "machine.hpp"
#include "testutil.hpp"
#include "util.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("if-else-if-else-end", "[extended-grammar]") {
  std::string code = readFile("examples/if.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{27, 9, 3});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("while/do-while", "[extended-grammar]") {
  std::string code = readFile("examples/while.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  for (f64 i = 3; i > 0; i--) {
    instruction = machine.next();
    REQUIRE(instruction.command == gpp::Command::move_rapid);
    REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{i, 0, 0});
  }

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{5, 0, 0});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

TEST_CASE("for", "[extended-grammar]") {
  std::string code = readFile("examples/for.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  for (f64 i = 0; i < 3; i++) {
    for (f64 j = 0; j < 3; j++) {
      instruction = machine.next();
      REQUIRE(instruction.command == gpp::Command::move_rapid);
      REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{1, i, j});
    }
  }

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}
