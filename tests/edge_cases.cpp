#define smv_gpp_testing

#include "machine.hpp"
#include "testutil.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("missing axes in g0/g1", "[edge-cases]") {
  std::string code = "g0 x0 y0 z0\n"
                     "g1 f600 z-10\n"
                     "g0 y100\n";

  gpp::Machine machine(code);

  gpp::Instruction instruction;

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, {0, 0, 0}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_linear);
  REQUIRE(approx_equal(instruction.arguments, {0, 0, -10}));
  REQUIRE(approx_equal(machine.position, gpp::Vec3D{0, 0, -10}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::move_rapid);
  REQUIRE(approx_equal(instruction.arguments, {0, 100, 0}));
  REQUIRE(approx_equal(machine.position, gpp::Vec3D{0, 100, -10}));

  instruction = machine.next();
  REQUIRE(instruction.command == gpp::no_command);
}
