#include "frontend.hpp"

#include "parser_antlr4.h"
#include <iostream>

std::unique_ptr<parser_antlr4> g_frontend_parse(const std::string &code) {
  antlr4::ANTLRInputStream input(code);
  lexer_antlr4 lexer(&input);

  antlr4::CommonTokenStream tokens(&lexer);
  return std::make_unique<parser_antlr4>(&tokens);
}

void g_print_tree(const std::unique_ptr<parser_antlr4> &parser) {
  if (!parser) {
    std::cerr << "Error: Parser is null!" << std::endl;
    return;
  }

  auto tree = parser->program();
  if (!tree) {
    std::cerr << "Error: Parsing failed. Syntax tree is null." << std::endl;
    return;
  }

  std::cout << antlr4::tree::Trees::toStringTree(tree) << std::endl;
}
