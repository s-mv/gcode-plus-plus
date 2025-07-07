#ifndef smv_gpp_test_util_hpp
#define smv_gpp_test_util_hpp

#include <cmath>
#include <cstdlib>
#include <vector>

#define smv_gpp_testing
#include "gpp.hpp"
#include "machine.hpp"
#include "util.hpp"

#include "doctest.h"

#define CHECK_VEC3D_EQUAL(a, b)                                                \
  do {                                                                         \
    CHECK(a.x == doctest::Approx(b.x).epsilon(1e-5));                          \
    CHECK(a.y == doctest::Approx(b.y).epsilon(1e-5));                          \
    CHECK(a.z == doctest::Approx(b.z).epsilon(1e-5));                          \
  } while (0)

#define CHECK_ARRAY_EQUAL(a, b)                                                \
  do {                                                                         \
    CHECK(a.size() == b.size());                                               \
    for (size_t i = 0; i < a.size(); ++i)                                      \
      CHECK(a.at(i) == doctest::Approx(b.at(i)).epsilon(1e-5));                \
  } while (0)

gpp::Instruction expectValidInstruction(const SafeInstruction &result);

#endif
