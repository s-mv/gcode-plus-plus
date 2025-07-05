#include <cmath>
#define smv_gpp_testing

#include "doctest.h"
#include "machine.hpp"
#include "testutil.hpp"

TEST_CASE("[error-handling] error handling") {
  SUBCASE("gcodes from the same modal group on the same line") {
    std::string code = "g1 f500 g0 x4\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();

    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
  }
}
