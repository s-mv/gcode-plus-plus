#include "testutil.hpp"
#include "catch_amalgamated.hpp"

#include <cstdlib>

void REQUIRE_approx_equal(const gpp::Vec3D &a, const gpp::Vec3D &b,
                          f64 epsilon) {
  REQUIRE(a.x == Catch::Approx(b.x).margin(epsilon));
  REQUIRE(a.y == Catch::Approx(b.y).margin(epsilon));
  REQUIRE(a.z == Catch::Approx(b.z).margin(epsilon));
}

void REQUIRE_approx_equal(const std::vector<f64> &a, const std::vector<f64> &b,
                          f64 epsilon) {
  REQUIRE(a.size() == b.size());

  for (size_t i = 0; i < a.size(); ++i)
    REQUIRE(a.at(i) == Catch::Approx(b.at(i)).margin(epsilon));
}
