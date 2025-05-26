#include <cstring>
#include <iostream>
#include <string>

#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include "bytecode.hpp"
#include "frontend.hpp"
#include "lexer_antlr4.h"
#include "machine.hpp"
#include "parser_antlr4.h"
#include "util.hpp"

#define max_input_len 256

int main(int argc, char **argv) {
  if (argc > 1) {
    const char *src = argv[1];

    std::string input(read_file(src));
    if (input.empty()) {
      std::cerr << "Error reading file at " << src << "!" << std::endl;
      return 1;
    }

    auto tree = g_frontend_parse(input);
    // g_print_tree(tree);

    return 0;
  }

  std::cout << "rs274 (g-code) JIT interpreter\n"
            << "TODO, everything!\n"
            << "Run `exit` to exit.\n";

  g_machine machine;
  machine.init();

  while (true) {
    std::cout << ">> ";
    std::string input;
    if (!std::getline(std::cin, input))
      break;

    input += "\n";

    if (input == "exit")
      break;

    antlr4::ANTLRInputStream ip(input);
    lexer_antlr4 lexer(&ip);
    antlr4::CommonTokenStream tokens(&lexer);
    parser_antlr4 parser(&tokens);

    // antlr4::tree::ParseTree *tree = parser.program();
    // std::cout << tree->toStringTree(&parser) << std::endl;
    // g_print_tree(parser);

    g_bytecode_emitter emitter = g_bytecode_emitter();
    emitter.run(parser.program());

    // std::cout << "Bytecode:\n";
    // emitter.print();
    // std::cout << std::endl;

    for (g_inst x : emitter.bytecode)
      std::cout << x.code << " " << x.attr << " ";
    std::cout << std::endl;
    machine.run(emitter.bytecode);
  }

  return 0;
}
