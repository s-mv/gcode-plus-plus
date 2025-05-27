#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "bytecode.hpp"
#include "lexer_antlr4.h"

TEST_CASE("Bytecode generation - example test", "bytecode") {
  antlr4::ANTLRInputStream ip("g0 x10 y-10 z20 f600\n");
  lexer_antlr4 lexer(&ip);

  antlr4::CommonTokenStream tokens(&lexer);
  parser_antlr4 parser(&tokens);

  g_bytecode_emitter emitter;
  emitter.run(parser.program());

  std::vector<g_tempcode_data> expected = {
      {.code = g_tempcode::move_rapid},
      {.code = g_tempcode::set_x},
      {.attr = 10},
      {.code = g_tempcode::set_y},
      {.attr = -10},
      {.code = g_tempcode::set_z},
      {.attr = 20},
      {.code = g_tempcode::set_feedrate},
      {.attr = 600},
      {.code = g_tempcode::end_line},
  };

  REQUIRE(emitter.buffer.size() == expected.size());

  for (size_t i = 0; i < expected.size(); ++i) {
    CHECK(emitter.buffer[i].code == expected[i].code);
    CHECK(emitter.buffer[i].attr == expected[i].attr);
  }
}
