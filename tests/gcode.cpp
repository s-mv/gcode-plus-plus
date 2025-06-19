#define smv_gpp_testing

#include "machine.hpp"
#include "testutil.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("g0 g1 g20 g21 g90 g91", "[g-code]") {
  std::string code = "g21\n"
                     "g1 x1 y2 z3 f1200\n"
                     "g20 g91\n"
                     "g0 x1 y2 z50\n";
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::use_length_units);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{(f64)gpp::Unit::mm}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_feed_rate);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1200}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_linear);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1, 2, 3}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::use_length_units);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{(f64)gpp::Unit::inch}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::use_distance_mode);
  REQUIRE(approx_equal(instruction.arguments,
                       std::vector<f64>{gpp::DistanceMode::relative}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{1, 2, 50}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}

TEST_CASE("g43", "[g-code]") {
  std::string code = "g10 p1 l1 z2\n"
                     "t1 m6\n"
                     "g43 h1\n"
                     "g0 z0\n";
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_tool_length_offset);

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::select_tool);
  REQUIRE(approx_equal(instruction.arguments, {1}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::change_tool);

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::use_tool_length_offset);
  REQUIRE(approx_equal(instruction.arguments, {2}));
  REQUIRE(machine.toolOffset == Catch::Approx(2));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(machine.position, {0, 0, -2}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}

TEST_CASE("g54-59", "[g-code]") {
  std::string code = "g10 p2 l2 x100 z10\n"
                     "g55\n"
                     "g0 x10 y10\n";
  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_wcs_coordinates);
  REQUIRE(approx_equal(instruction.arguments, {2, 100, 0, 10}));
  REQUIRE(machine.workOffsets[1] == (gpp::Vec3D){100, 0, 10});

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::use_workspace);
  REQUIRE(machine.g5xoffset == machine.workOffsets[1]);

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, {10, 10, -10}));
  REQUIRE(approx_equal(machine.position, gpp::Vec3D{110, 10, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}

TEST_CASE("g2 g3", "[g-code]") {
  std::string code = "f600\n"
                     "g0 x0 y0 z0\n"
                     "g2 x2 r1\n"
                     "g3 x0 r1\n"
                     "g0 x0 y0 z0\n"
                     "g2 x2 y2 i1 j1\n"
                     "g3 x0 y0 i-1 j-1\n";

  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::set_feed_rate);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{600}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{2, 0, 1, 0, 1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{0, 0, 1, 0, -1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, std::vector<f64>{0, 0, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{2, 2, 1, 1, 1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::arc_feed);
  REQUIRE(
      approx_equal(instruction.arguments, std::vector<f64>{0, 0, 1, 1, -1, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}
