#include "machine.hpp"
#include "testutil.hpp"
#include "util.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("m3, m4, m5", "[m-code]") {
  std::string code = readFile("examples/m3m4m5.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_spindle_speed);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{100}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::start_spindle_clockwise);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_spindle_speed);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{300}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::start_spindle_counterclockwise);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::stop_spindle_turning);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}
