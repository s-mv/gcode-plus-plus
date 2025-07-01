#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[g-code] g81") {
  SUBCASE("g81 basic") {
    std::string code = "g20 s100 m3 g81 g98 g91 x10 y10 z-5 r1 f100 p2 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {100.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_length_units);
    expected_args = {gpp::inch};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_distance_mode);
    expected_args = {gpp::relative};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_retract_mode);
    expected_args = {gpp::old_z};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::no_command);
  }
}
