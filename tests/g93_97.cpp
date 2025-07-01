#define smv_gpp_testing

#include "doctest.h"

#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[g-code] g93-95 feed modes with motion dependencies") {
  SUBCASE("g93 inverse time mode - feed rate should be 1/F") {
    std::string code = "g93\n"
                       "f0.1\n"
                       "g1 x10 y10\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);
    expected_args = {gpp::inverse_time};
    CHECK(instruction.arguments.at(0) == expected_args[0]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(1.0 / 0.1));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
  }

  SUBCASE("g94 units per minute - direct feed rate") {
    std::string code = "g94\n"
                       "f1500\n"
                       "g1 x20\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);
    expected_args = {gpp::units_per_minute};
    CHECK(instruction.arguments.at(0) == expected_args[0]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(1500.0));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
  }

  SUBCASE("g95 units per revolution - depends on spindle speed") {
    std::string code = "s1000\n"
                       "m3\n"
                       "g95\n"
                       "f0.1\n"
                       "g1 x5\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::start_spindle_clockwise);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);
    expected_args = {gpp::units_per_revolution};
    CHECK(instruction.arguments.at(0) == expected_args[0]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(0.1 * 1000));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
  }

  SUBCASE("g95 with zero spindle speed - edge case") {
    std::string code = "s0\n"
                       "g95\n"
                       "f0.1\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(0.0));
  }
}

TEST_CASE("[g-code] g96-97 spindle modes with motion dependencies") {
  SUBCASE("g96 constant surface speed - depends on position") {
    std::string code = "g0 x25 y0\n"
                       "g96 s200\n"
                       "g1 x50\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_mode);
    expected_args = {gpp::constant_surface_speed};
    CHECK(instruction.arguments.at(0) == expected_args[0]);

    CHECK(machine.spindleSpeed ==
          doctest::Approx(1000 * 200 / (2 * M_PI * 25)).epsilon(1.0));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    CHECK(machine.spindleSpeed ==
          doctest::Approx(1000 * 200 / (2 * M_PI * 50)).epsilon(1.0));
  }

  SUBCASE("g96 at origin - should set speed to zero") {
    std::string code = "g0 x0 y0\n"
                       "g96 s250\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_mode);
    CHECK(machine.spindleSpeed == doctest::Approx(0.0));
  }

  SUBCASE("g97 fixed RPM mode") {
    std::string code = "g97 s2500\n"
                       "g0 x10 y10\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);
    expected_args = {2500};
    CHECK_ARRAY_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_mode);
    expected_args = {gpp::fixed_rpm};
    CHECK(instruction.arguments.at(0) == expected_args[0]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    CHECK(machine.spindleSpeed == doctest::Approx(2500));
  }
}

TEST_CASE("[g-code] g93-97 interdependence - tricky edge cases") {
  SUBCASE("g95 + g96 combination - feed depends on calculated RPM") {
    std::string code = "g0 x20 y0\n"
                       "g96 s150\n"
                       "g95\n"
                       "f0.05\n"
                       "g1 x50\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_mode);
    CHECK(machine.spindleSpeed ==
          doctest::Approx(1000 * 150 / (2 * M_PI * 20)).epsilon(1.0));

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate ==
          doctest::Approx(0.05 * (1000 * 150 / (2 * M_PI * 20))).epsilon(0.5));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_linear);
    CHECK(machine.spindleSpeed ==
          doctest::Approx(1000 * 150 / (2 * M_PI * 50)).epsilon(0.5));
    CHECK(machine.feedRate ==
          doctest::Approx(0.05 * (1000 * 150 / (2 * M_PI * 50))).epsilon(0.2));
  }

  SUBCASE("Mode switching during operation") {
    std::string code = "s1500\n"
                       "g95\n"
                       "f0.1\n"
                       "g0 x30\n"
                       "g96 s200\n"
                       "g94\n"
                       "f800\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);
    CHECK(machine.spindleSpeed == doctest::Approx(1500));

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(0.1 * 1500));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_mode);
    CHECK(machine.spindleSpeed ==
          doctest::Approx(1000 * 200 / (2 * M_PI * 30)).epsilon(1.0));
    CHECK(machine.feedRate ==
          doctest::Approx(0.1 * (1000 * 200 / (2 * M_PI * 30))).epsilon(0.5));

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(800.0));
  }

  SUBCASE("g93 with changing spindle speeds") {
    std::string code = "s1000\n"
                       "g93\n"
                       "f0.2\n"
                       "s2000\n"
                       "g95\n"
                       "f0.05\n";

    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(1.0 / 0.2));

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_spindle_speed);
    CHECK(machine.spindleSpeed == doctest::Approx(2000.0));

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK(machine.feedRate == doctest::Approx(0.05 * 2000));
  }
}
