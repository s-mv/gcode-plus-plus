#include <cmath>
#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[g-code] g84") {
  SUBCASE("g84 basic with g98 g91") {
    std::string code =
        "g20 s100 f400 m3 g98 g91 g84 x0.5 y-0.75 z-0.605 p3 r0.2 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {400.0};
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
    expected_args = {0, 0, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -20.447};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_counterclockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {3};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 20.447};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -20.447};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_counterclockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {3};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 20.447};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g84 basic with g98 g90") {
    std::string code =
        "g20 s100 f400 m3 g98 g90 g84 x0.5 y-0.75 z-0.605 p3 r0.2 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {400.0};
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
    expected_args = {0, 0, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, -15.367};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_counterclockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {3};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {12.7, -19.05, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {12.7, -19.05, -15.367};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_counterclockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {3};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {12.7, -19.05, 5.08};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {12.7, -19.05, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}

TEST_CASE("[g-code] g85") {
  SUBCASE("g85 basic with g98 g90") {
    std::string code = "g20 s100 m3 g98 g90 g85 x2 y2 z-1 r0.5 f20 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {20.0};
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
    expected_args = {0, 0, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {50.8, 50.8, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {50.8, 50.8, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {50.8, 50.8, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {50.8, 50.8, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {50.8, 50.8, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {50.8, 50.8, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {50.8, 50.8, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g85 basic with g98 g91") {
    std::string code = "g20 s100 m3 g98 g91 g85 x2 y2 z-1 r0.5 f20 l2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::set_feed_rate);
    expected_args = {20.0};
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
    expected_args = {0, 0, 12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {50.8, 50.8, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -38.1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, 38.1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {50.8, 50.8, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -38.1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, 38.1};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -12.7};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}

TEST_CASE("[g-code] g86") {
  SUBCASE("g86 basic with g98 g90") {
    std::string code = "g20 s100 m3 g86 g98 g90 x10 y10 z-5 r1 f100 p2 l2\n";
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
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::stop_spindle_turning);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {254, 254, -127};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::stop_spindle_turning);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }

  SUBCASE("g86 basic with g98 g91") {
    std::string code = "g20 s100 m3 g86 g98 g91 x10 y10 z-5 r1 f100 p2 l2\n";
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
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -152.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::stop_spindle_turning);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 152.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {254, 254, 0};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_linear);
    expected_args = {0, 0, -152.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::dwell);
    expected_args = {2};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::stop_spindle_turning);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, 152.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {0, 0, -25.4};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = expectValidInstruction(machine.next());
    CHECK(instruction.command == gpp::no_command);
  }
}