#ifndef smv_gpp_util_hpp
#define smv_gpp_util_hpp

#include <cstdint>
#include <string>

using u8 = std::uint64_t;
using u16 = std::uint16_t;
using u64 = std::uint64_t;
using i8 = std::int64_t;
using i64 = std::int64_t;
using f64 = double;

enum ErrorCode : int {
  no_error = 0,
  modal_group_overlap_error = 1,
};

std::string readFile(const std::string &filename);
void prettyPrintError(const std::string message, const std::string code,
                      int line, int column);

#endif
