#include "machine.hpp"
#include "util.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

TEST_CASE("regression test with captured output") {
  std::string code = readFile("examples/learnxiny.cnc");
  std::string expected = readFile("tests/regression.txt");
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  std::ostringstream buffer;
  std::streambuf *oldBuffer = std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());

  gpp::Machine machine = gpp::Machine(code);

  while (machine.next().command != no_command)
    ;

  std::cout.rdbuf(oldBuffer);

  std::string captured = buffer.str();

  CHECK(captured == expected);
}
