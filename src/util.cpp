#include "util.hpp"

#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

std::string readFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return "";
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  return buffer.str();
}

void prettyPrintError(const std::string message, const std::string code,
                      int line, int column) {
  std::string caretLine(column > 1 ? column - 1 : 0, ' ');
  caretLine += '^';

  std::cout << "error: " << message << "\n";
  std::cout << " --> line " << line << ", column " << column << "\n";
  std::cout << "  |\n";
  std::cout << std::setw(3) << line << " | " << code << "\n";
  std::cout << "    | " << caretLine << std::endl;
}
