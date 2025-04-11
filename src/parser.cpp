#include "parser.hpp"

#include "antlr4-runtime.h" 

#include "lexer_antlr4.h"
#include "parser_antlr4.h"

parser_antlr4::ProgramContext *g_parse(const std::string &code) {
  antlr4::ANTLRInputStream input(code);
  lexer_antlr4 lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  parser_antlr4 parser(&tokens);

  parser_antlr4::ProgramContext *tree = parser.program(); // Entry point

  return tree;
}
