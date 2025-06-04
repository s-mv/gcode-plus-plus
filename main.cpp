#include <iostream>
#include <string>

#include "machine.hpp"
#include "util.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "No file provided as an argument!\n";
    return -1;
  }

  const char *src = argv[1];

  std::string input(ReadFile(src));
  if (input.empty()) {
    std::cerr << "Error reading file at " << src << "!" << std::endl;
    return 1;
  }

  gpp::Machine machine(input);

  std::cout << "Type `next` to step, `exit` to quit!\n";

  std::string command;
  bool next_used = false;

  while (true) {
    std::cout << "> ";
    std::getline(std::cin, command);

    if (command == "exit") {
      break;
    } else if (command == "next" || next_used) {
      next_used = true;
      if (!machine.next()) {
        std::cout << "No more instructions left!\n";
        break;
      }
    } else {
      std::cout
          << "Unknown command... Available commands: `next` and `exit`.\n";
    }
  }

  return 0;
}
