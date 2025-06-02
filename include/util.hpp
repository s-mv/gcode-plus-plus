#ifndef smv_gcodepp_util_hpp
#define smv_gcodepp_util_hpp

#include <cstdint>
#include <string>

using u8 = std::uint64_t;
using u16 = std::uint16_t;
using u64 = std::uint64_t;
using i8 = std::int64_t;
using i64 = std::int64_t;
using f64 = double;

/* misc. utility functions */

std::string ReadFile(const std::string &filename);

/* logging utility - todo maybe remove this? */

// typedef enum g_log_level {
//   g_log_none = 0,
//   g_log_error = 1,
//   g_log_warning = 2,
//   g_log_info = 3,
// } g_log_level;

// #ifndef g_log_current_level
// #define g_log_current_level g_log_info

// #endif

// int g_log(g_log_level level, const char *format, ...);

#endif
