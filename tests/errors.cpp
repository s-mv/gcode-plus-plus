#define smv_gpp_testing
#include "bytecode.hpp"
#include "gpp.hpp"

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
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("division by zero") {
    std::string code = "g[0 / 0] x0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::MATH_ERROR);

    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("invalid tool with t<>") {
    std::string code = "t300 m6\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::MACHINE_ERROR);
  }

  SUBCASE("group 1 - no axes") {
    std::string code = "g0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("invalid tool with g43 h<>") {
    std::string code = "g43 h300\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::MACHINE_ERROR);
  }

  SUBCASE("g1 without feedrate") {}

  SUBCASE("g2/g2 without feedrate") {}

  SUBCASE("g2/g3 radius error") {
    std::string code = "f300 g2 x0 y0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("g2/g3 radius override") {
    std::string code = "f300 g2 x0 y0 r3 i3\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("g2/g3 missing axes") {
    std::string code = "f300 g2 i3 j3\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("g2/g3 3D arc") {
    std::string code = "f300 g2 x0 y0 i1 j1 k1\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("g2/g3 zero length arc") {
    std::string code = "f300 g2 x0 y0 i0 j0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }

  SUBCASE("g2/g3 negative radius") {
    std::string code = "f300 g2 x0 y0 i-1\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;
    SafeInstruction instruction;

    instruction = machine.next();
    instruction = machine.next();
    REQUIRE(std::holds_alternative<gpp::Error>(instruction));
    gpp::Error error = std::get<gpp::Error>(instruction);
    REQUIRE(error.type == gpp::ErrorType::PARAMETER_ERROR);
  }
}
