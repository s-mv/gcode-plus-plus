#ifndef smv_gcodepp_util_hpp
#define smv_gcodepp_util_hpp

#include <stdint.h>
#include <string>

typedef uint64_t u8;
typedef uint16_t u16;
typedef uint64_t u64;
typedef int64_t i8;
typedef int64_t i64;
typedef double f64;


/* misc. utility functions */

std::string read_file(const std::string &filename);

/* logging utility */

typedef enum g_log_level {
  g_log_none = 0,
  g_log_error = 1,
  g_log_warning = 2,
  g_log_info = 3,
} g_log_level;

#ifndef g_log_current_level
#define g_log_current_level g_log_info

#endif

int g_log(g_log_level level, const char *format, ...);

#endif
