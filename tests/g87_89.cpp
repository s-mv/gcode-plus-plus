#include <cmath>
#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[g-code] g89") {
  SUBCASE("g89 basic with g98 g91") {
    std::string code = "g20 s100 m3 g89 g98 g90 x3 y3 z-2 r1 f100 p1 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::use_length_units);
    expected_args = {gpp::inch};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::use_distance_mode);
    expected_args = {gpp::absolute};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_retract_mode);
    expected_args = {gpp::old_z};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, -50.8};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, -50.8};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {76.2, 76.2, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g89 basic with g98 g91") {
    std::string code = "g20 s100 m3 g89 g98 g91 x3 y3 z-2 r1 f100 p1 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::use_length_units);
    expected_args = {gpp::inch};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::use_distance_mode);
    expected_args = {gpp::relative};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_retract_mode);
    expected_args = {gpp::old_z};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -76.2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, 76.2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {76.2, 76.2, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -76.2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, 76.2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}
