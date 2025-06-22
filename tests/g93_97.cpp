#define smv_gpp_testing

#include "machine.hpp"
#include "testutil.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("g93-95 feed modes with motion dependencies", "[g-code]") {
  SECTION("g93 inverse time mode - feed rate should be 1/F") {
    std::string code = "g93\n"
                       "f0.1\n"
                       "g1 x10 y10\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);
    REQUIRE(instruction.arguments.at(0) == gpp::inverse_time);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(1.0 / 0.1));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_linear);
  }

  SECTION("g94 units per minute - direct feed rate") {
    std::string code = "g94\n"
                       "f1500\n"
                       "g1 x20\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);
    REQUIRE(instruction.arguments.at(0) == gpp::units_per_minute);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(1500.0));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_linear);
  }

  SECTION("g95 units per revolution - depends on spindle speed") {
    std::string code = "s1000\n"
                       "m3\n"
                       "g95\n"
                       "f0.1\n"
                       "g1 x5\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::start_spindle_clockwise);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);
    REQUIRE(instruction.arguments.at(0) == gpp::units_per_revolution);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(0.1 * 1000));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_linear);
  }

  SECTION("g95 with zero spindle speed - edge case") {
    std::string code = "s0\n"
                       "g95\n"
                       "f0.1\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(0.0));
  }
}

TEST_CASE("g96-97 spindle modes with motion dependencies", "[g-code]") {
  SECTION("g96 constant surface speed - depends on position") {
    std::string code = "g0 x25 y0\n"
                       "g96 s200\n"
                       "g1 x50\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_mode);
    REQUIRE(instruction.arguments.at(0) == gpp::constant_surface_speed);

    REQUIRE(machine.spindleSpeed ==
            Catch::Approx(1000 * 200 / (2 * M_PI * 25)).margin(1.0));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_linear);
    REQUIRE(machine.spindleSpeed ==
            Catch::Approx(1000 * 200 / (2 * M_PI * 50)).margin(1.0));
  }

  SECTION("g96 at origin - should set speed to zero") {
    std::string code = "g0 x0 y0\n"
                       "g96 s250\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_mode);
    REQUIRE(machine.spindleSpeed == Catch::Approx(0.0));
  }

  SECTION("g97 fixed RPM mode") {
    std::string code = "g97 s2500\n"
                       "g0 x10 y10\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);
    REQUIRE_approx_equal(instruction.arguments, {2500});

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_mode);
    REQUIRE(instruction.arguments.at(0) == gpp::fixed_rpm);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_rapid);
    REQUIRE(machine.spindleSpeed == Catch::Approx(2500));
  }
}

TEST_CASE("g93-97 interdependence - tricky edge cases", "[g-code]") {
  SECTION("g95 + g96 combination - feed depends on calculated RPM") {
    std::string code = "g0 x20 y0\n"
                       "g96 s150\n"
                       "g95\n"
                       "f0.05\n"
                       "g1 x50\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_mode);
    REQUIRE(machine.spindleSpeed ==
            Catch::Approx(1000 * 150 / (2 * M_PI * 20)).margin(1.0));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate ==
            Catch::Approx(0.05 * (1000 * 150 / (2 * M_PI * 20))).margin(0.5));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_linear);
    REQUIRE(machine.spindleSpeed ==
            Catch::Approx(1000 * 150 / (2 * M_PI * 50)).margin(0.5));
    REQUIRE(machine.feedRate ==
            Catch::Approx(0.05 * (1000 * 150 / (2 * M_PI * 50))).margin(0.2));
  }

  SECTION("Mode switching during operation") {
    std::string code = "s1500\n"
                       "g95\n"
                       "f0.1\n"
                       "g0 x30\n"
                       "g96 s200\n"
                       "g94\n"
                       "f800\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);
    REQUIRE(machine.spindleSpeed == Catch::Approx(1500));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(0.1 * 1500));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::move_rapid);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_mode);
    REQUIRE(machine.spindleSpeed ==
            Catch::Approx(1000 * 200 / (2 * M_PI * 30)).margin(1.0));
    REQUIRE(machine.feedRate ==
            Catch::Approx(0.1 * (1000 * 200 / (2 * M_PI * 30))).margin(0.5));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(800.0));
  }

  SECTION("g93 with changing spindle speeds") {
    std::string code = "s1000\n"
                       "g93\n"
                       "f0.2\n"
                       "s2000\n"
                       "g95\n"
                       "f0.05\n";

    gpp::Machine machine(code);
    gpp::Instruction instruction;

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(1.0 / 0.2));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_spindle_speed);
    REQUIRE(machine.spindleSpeed == Catch::Approx(2000.0));

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_mode);

    instruction = machine.next();
    REQUIRE(instruction.command == gpp::set_feed_rate);
    REQUIRE(machine.feedRate == Catch::Approx(0.05 * 2000));
  }
}
