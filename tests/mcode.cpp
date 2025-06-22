#include "machine.hpp"
#include "testutil.hpp"
#include "util.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("m3 m4 m5", "[m-code]") {
  std::string code = "m3 s100\n"
                     "s300 m4\n"
                     "m5\n";

  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_spindle_speed);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{100});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::start_spindle_clockwise);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_spindle_speed);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{300});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::start_spindle_counterclockwise);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::stop_spindle_turning);
  REQUIRE_approx_equal(instruction.arguments, std::vector<f64>{});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}
