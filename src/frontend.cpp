
#include <iostream>

#include "gpp.hpp"
#include "lexer_antlr4.h"
#include "parser_antlr4.h"

std::unique_ptr<parser_antlr4> gpp::FrontendParse(const std::string &code) {
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

  auto tree = parser->block();
  if (!tree) {
    std::cerr << "Error: Parsing failed. Syntax tree is null." << std::endl;
    return;
  }

  std::cout << antlr4::tree::Trees::toStringTree(tree) << std::endl;
}
