#include "util.hpp"

#include <cstdarg>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

std::string ReadFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return "";
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  return buffer.str();
}

/* todo - maybe remove? */

// int g_log(g_log_level level, const char *format, ...) {
//   if (level > g_log_current_level || level == g_log_level::g_log_none)
//     return 0;

//   std::string prefix;

//   switch (level) {
//   case g_log_level::g_log_error:
//     prefix = "[ERR]  ";
//     break;
//   case g_log_level::g_log_warning:
//     prefix = "[WARN] ";
//     break;
//   case g_log_level::g_log_info:
//     prefix = "[INFO] ";
//     break;
//   default:
//     break;
//   }

//   std::cout << prefix;

//   va_list args;
//   va_start(args, format);
//   int len = vprintf(format, args);
//   va_end(args);

//   return len;
// }