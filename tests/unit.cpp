#include "bytecode.hpp"
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

TEST_CASE("g0, g1, g20, g21", "bytecode") {
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter("g0 g21 x1 y1 z1\n"
                                                      "g1 g20 x1 y1 z1 f100\n");

  while (true)
    gpp::Instruction instruction = emitter.next();
}

TEST_CASE("if-else-if-else-end", "bytecode") {}

// TEST_CASE("while-do-end", "unit") {}

// TEST_CASE("do-while-end", "unit") {}
