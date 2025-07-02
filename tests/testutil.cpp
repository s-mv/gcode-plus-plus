#include "testutil.hpp"

gpp::Instruction expectValidInstruction(const SafeInstruction &result) {
  if (std::holds_alternative<gpp::Error>(result)) {
    const gpp::Error &error = std::get<gpp::Error>(result);
    std::string fullMessage =
        std::string("Unexpected error in instruction: ") + error.message;
    DOCTEST_FAIL(fullMessage);
  }
  return std::get<gpp::Instruction>(result);
}
