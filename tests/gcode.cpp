#define smv_gpp_testing

#include "machine.hpp"
#include "testutil.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("g0, g1, g20, g21, g90, g91", "[g-code]") {
  std::string code = readFile("examples/basic.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{(f64)gpp::Unit::mm}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1200}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_linear);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1, 2, 3}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_length_units);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{(f64)gpp::Unit::inch}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::use_distance_mode);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{gpp::DistanceMode::relative}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1, 2, 50}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}

/* TEST_CASE("g92, g54-g59", "[g-code]") {
  std::string code = readFile("examples/g92g5x.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1, 0, 1}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_origin_offsets);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 0}));
  REQUIRE(approx_equal(machine.g92offset, gpp::Vec3D{1, 0, 1}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 1}));
  REQUIRE(approx_equal(machine.position, gpp::Vec3D{1, 0, 2}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
} */

TEST_CASE("g2, g3", "[g-code]") {
  std::string code = readFile("examples/g2g3.cnc");
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::set_feed_rate);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{600}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{2, 0, 1, 0, 1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{0, 0, 1, 0, -1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{2, 2, 1, 1, 1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{0, 0, 1, 1, -1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::Command::no_command);
}
