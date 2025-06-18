#include "testutil.hpp"

#include <cstdlib>

bool approx_equal(const gpp::Vec3D &a, const gpp::Vec3D &b, f64 epsilon) {
  return std::abs(a.x - b.x) < epsilon && std::abs(a.y - b.y) < epsilon &&
         std::abs(a.z - b.z) < epsilon;
}

bool approx_equal(const std::vector<f64> &a, const std::vector<f64> &b,
                  f64 epsilon) {
  if (a.size() != b.size())
    return false;

  for (size_t i = 0; i < a.size(); ++i) {
    if (std::abs(a.at(i) - b.at(i)) > epsilon)
      return false;
  }
  return true;
}
