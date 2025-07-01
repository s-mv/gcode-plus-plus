#include "machine.hpp"
#include "testutil.hpp"
#include "util.hpp"

#include "doctest.h"

TEST_CASE("[m-code] m0 m1 m2") {
  std::string code = "m0\n"
                     "m1\n"
                     "m2\n";

  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  instruction = machine.next();
  CHECK(instruction.command == gpp::program_stop);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::optional_program_stop);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  machine.next();
  machine.next();
  instruction = machine.next();
  CHECK(instruction.command == gpp::program_end);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);
}

TEST_CASE("[m-code] m3 m4 m5") {
  std::string code = "m3 s100\n"
                     "s300 m4\n"
                     "m5\n";

  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  instruction = machine.next();
  CHECK(instruction.command == gpp::set_spindle_speed);
  expected_args = {100};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::start_spindle_clockwise);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::set_spindle_speed);
  expected_args = {300};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::start_spindle_counterclockwise);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::stop_spindle_turning);
  expected_args = {};
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::no_command);
}
