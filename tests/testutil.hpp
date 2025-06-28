#ifndef smv_gpp_test_util_hpp
#define smv_gpp_test_util_hpp

#include <cstdlib>
#include <vector>
#include <cmath>

#include "gpp.hpp"
#include "machine.hpp"
#include "util.hpp"

#include "catch_amalgamated.hpp"

#define CHECK_approx_equal(a, b)                                               \
  do {                                                                         \
    CHECK(std::abs(a.x - b.x) < 1e-5);                                         \
    CHECK(std::abs(a.y - b.y) < 1e-5);                                         \
    CHECK(std::abs(a.z - b.z) < 1e-5);                                         \
  } while (0);

#define CHECK_VEC_EQUAL(a, b)                                                  \
  do {                                                                         \
    CHECK(a.size() == b.size());                                               \
    for (size_t i = 0; i < a.size(); ++i)                                      \
      CHECK(std::abs(a.at(i) - b.at(i)) < 1e-5);                               \
  } while (0);

#endif
