#include "machine.hpp"
#include "testutil.hpp"
#include "util.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("if-else-if-else-end", "[extended-grammar]") {
  std::string code = readFile("examples/if.cnc");
  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  instruction = machine.next();
  expected_args = {27, 9, 3};
  CHECK(instruction.command == gpp::Command::move_rapid);
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::Command::no_command);
}

TEST_CASE("while/do-while", "[extended-grammar]") {
  std::string code = readFile("examples/while.cnc");
  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  for (f64 i = 3; i > 0; i--) {
    instruction = machine.next();
    expected_args = {i, 0, 0};
    CHECK(instruction.command == gpp::Command::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
  }

  instruction = machine.next();
  expected_args = {5, 0, 0};
  CHECK(instruction.command == gpp::Command::move_rapid);
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::Command::no_command);
}

TEST_CASE("for", "[extended-grammar]") {
  std::string code = readFile("examples/for.cnc");
  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  for (f64 i = 0; i < 3; i++) {
    for (f64 j = 0; j < 3; j++) {
      instruction = machine.next();
      expected_args = {1, i, j};
      CHECK(instruction.command == gpp::Command::move_rapid);
      CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    }
  }

  instruction = machine.next();
  CHECK(instruction.command == gpp::Command::no_command);
}
