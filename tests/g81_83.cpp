#include <cmath>
#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[g-code] g81") {
  SUBCASE("g81 basic with g98 g90") {
    std::string code = "g20 s100 m3 g81 g98 g90 x10 y10 z-5 r1 f100 p2 l2\n";
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
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g81 basic with g98 g91") {
    std::string code = "g20 s100 m3 g81 g98 g91 x10 y10 z-5 r1 f100 p2 l2\n";
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
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}

TEST_CASE("[g-code] g82") {
  SUBCASE("g82 basic with g98 g90") {
    std::string code = "g20 s100 m3 g82 g98 g90 x10 y10 z-5 r1 f100 p2 l2\n";
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
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g82 basic with g98 g91") {
    std::string code = "g20 s100 m3 g82 g98 g91 x10 y10 z-5 r1 f100 p2 l2\n";
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
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}

TEST_CASE("g83") {
  SUBCASE("g83 basic with g98 g90") {
    std::string code = "s400 m3 g20 f600 g90 g98 g83 x5 y5 z-4 r1 q0.5\n";
    gpp::Machine machine(code);
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {600.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {400.0};
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
    expected_args = {127, 127, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -38.1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -50.8};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -63.5};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -76.2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -88.9};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {127, 127, -101.6};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {127, 127, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {127, 127, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g83 basic with g98 g91") {
    std::string code = "s400 m3 g20 f600 g91 g98 g83 x4 y4 z-4 r1 q0.5 l2\n";
    gpp::Machine machine(code);
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {600.0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {400.0};
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
    expected_args = {101.6, 101.6, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    for (int i = 0; i < 10; ++i) {
      instruction = expectValidInstruction(machine.next());
      CHECK(instruction.command == gpp::move_linear);
      expected_args = {0, 0, -12.7};
      CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);
    }

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {101.6, 101.6, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    for (int i = 0; i < 10; ++i) {
      instruction = expectValidInstruction(machine.next());
      CHECK(instruction.command == gpp::move_linear);
      expected_args = {0, 0, -12.7};
      CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);
    }

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}
