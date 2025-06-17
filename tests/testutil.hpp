#ifndef smv_gpp_test_util_hpp
#define smv_gpp_test_util_hpp

#include "util.hpp"

#include <vector>

#include "gpp.hpp"
#include "machine.hpp"

bool approx_equal(const gpp::Vec3D &a, const gpp::Vec3D &b, f64 epsilon = 1e-5);
bool approx_equal(const std::vector<f64> &a, const std::vector<f64> &b,
                  double epsilon = 1e-5);
#endif
