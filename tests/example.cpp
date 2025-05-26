#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "bytecode.hpp"
#include "lexer_antlr4.h"

TEST_CASE("BytecodeGeneration - ExampleTest1", "[bytecode]") {
  antlr4::ANTLRInputStream ip("g0 x10 y-10 z20 f600\n");
  lexer_antlr4 lexer(&ip);

  antlr4::CommonTokenStream tokens(&lexer);
  parser_antlr4 parser(&tokens);

  g_bytecode_emitter emitter;
  emitter.run(parser.program());

  std::vector<g_inst> expected = {
      {.code = g_opcode::rapid_move},
      {.code = g_opcode::set_x},
      {.attr = 10},
      {.code = g_opcode::set_y},
      {.attr = -10},
      {.code = g_opcode::set_z},
      {.attr = 20},
      {.code = g_opcode::set_feedrate},
      {.attr = 600},
      {.code = g_opcode::end_line},
  };

  REQUIRE(emitter.bytecode.size() == expected.size());

  for (size_t i = 0; i < expected.size(); ++i) {
    CHECK(emitter.bytecode[i].code == expected[i].code);
    CHECK(emitter.bytecode[i].attr == expected[i].attr);
  }
}
