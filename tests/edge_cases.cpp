#include "util.hpp"
#include <vector>

#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[edge-cases] missing axes in g0/g1") {
  std::string code = "g0 x0 y0 z0\n"
                     "g1 f600 z-10\n"
                     "g0 y100\n";

  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  instruction = expectValidInstruction(machine.next());
  expected_args = {0, 0, 0};
  CHECK(instruction.command == gpp::move_rapid);
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = expectValidInstruction(machine.next());
  expected_args = {600};
  CHECK(instruction.command == gpp::set_feed_rate);
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

  instruction = expectValidInstruction(machine.next());
  expected_args = {0, 0, -10};
  CHECK(instruction.command == gpp::move_linear);
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);
  expected_vec = {0, 0, -10};
  CHECK_VEC3D_EQUAL(machine.position, expected_vec);

  instruction = expectValidInstruction(machine.next());
  expected_args = {0, 100, -10};
  CHECK(instruction.command == gpp::move_rapid);
  CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);
  expected_vec = {0, 100, -10};
  CHECK_VEC3D_EQUAL(machine.position, expected_vec);

  instruction = expectValidInstruction(machine.next());
  CHECK(instruction.command == gpp::no_command);
}
