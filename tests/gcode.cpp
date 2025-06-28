#define smv_gpp_testing

#include "machine.hpp"
#include "testutil.hpp"

#include "catch_amalgamated.hpp"

TEST_CASE("g0 g1 g20 g21 g90 g91", "[g-code]") {
  SECTION("Basic unit switching and movement") {
    std::string code = "g21\n"
                       "g1 x1 y2 z3 f1200\n"
                       "g20 g91\n"
                       "g0 x1 y2 z50\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_length_units);
    expected_args = {(f64)gpp::Unit::mm};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {1200};
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {1, 2, 3};
    CHECK(instruction.command == gpp::move_linear);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {(f64)gpp::Unit::inch};
    CHECK(instruction.command == gpp::use_length_units);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {gpp::DistanceMode::relative};
    CHECK(instruction.command == gpp::use_distance_mode);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    f64 multiplier = machine.unitMultiplier(gpp::inch);

    instruction = machine.next();
    expected_args = {1 * multiplier, 2 * multiplier, 50 * multiplier};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::no_command);
  }

  SECTION("Absolute mode positioning") {
    std::string code = "g90 g21\n"
                       "g0 x10 y20 z5\n"
                       "g1 x15 y25 z10 f800\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    expected_args = {(f64)gpp::Unit::mm};
    CHECK(instruction.command == gpp::use_length_units);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_distance_mode);
    expected_args = {gpp::DistanceMode::absolute};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {10, 20, 5};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {800};
    CHECK(instruction.command == gpp::set_feed_rate);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {15, 25, 10};
    CHECK(instruction.command == gpp::move_linear);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
  }

  SECTION("Multiple unit conversions") {
    std::string code = "g20\n"
                       "g0 x1\n"
                       "g21\n"
                       "g0 y25.4\n"
                       "g20\n"
                       "g0 z2\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_length_units);
    expected_args = {(f64)gpp::Unit::inch};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {25.4, 0, 0};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {(f64)gpp::Unit::mm};
    CHECK(instruction.command == gpp::use_length_units);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {25.4, 25.4, 0};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {(f64)gpp::Unit::inch};
    CHECK(instruction.command == gpp::use_length_units);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    f64 multiplier = machine.unitMultiplier(gpp::inch);
    expected_args = {1 * multiplier, 1 * multiplier, 2 * multiplier};
    std::cout << expected_args.at(0) << " " << expected_args.at(1) << " "
              << expected_args.at(2) << std::endl;
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
  }

  SECTION("Relative mode cumulative movement") {
    std::string code = "g91 g21\n"
                       "g0 x10 y10\n"
                       "g0 x5 y5\n"
                       "g0 x-5 y-5\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    expected_args = {(f64)gpp::Unit::mm};
    CHECK(instruction.command == gpp::use_length_units);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_distance_mode);
    expected_args = {gpp::DistanceMode::relative};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {10, 10, 0};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {5, 5, 0};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    expected_args = {-5, -5, 0};
    CHECK(instruction.command == gpp::move_rapid);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
  }
}

TEST_CASE("g43", "[g-code]") {
  SECTION("Basic tool length offset") {
    std::string code = "g10 p1 l1 z2\n"
                       "t1 m6\n"
                       "g43 h1\n"
                       "g0 z0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_tool_length_offset);

    instruction = machine.next();
    expected_args = {1};
    CHECK(instruction.command == gpp::select_tool);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::change_tool);

    instruction = machine.next();
    expected_args = {2};
    CHECK(instruction.command == gpp::use_tool_length_offset);
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    CHECK(machine.toolOffset == Catch::Approx(2));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_vec = {0, 0, -2};
    CHECK_approx_equal(machine.position, expected_vec);

    instruction = machine.next();
    CHECK(instruction.command == gpp::no_command);
  }

  SECTION("Multiple tool offsets") {
    std::string code = "g10 p1 l1 z2.5\n"
                       "g10 p2 l1 z3.8\n"
                       "t1 m6\n"
                       "g43 h1\n"
                       "g0 z5\n"
                       "t2 m6\n"
                       "g43 h2\n"
                       "g0 z5\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    machine.next(); // g10 p1
    machine.next(); // g10 p2
    machine.next(); // t1
    machine.next(); // m6

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_tool_length_offset);
    expected_args = {2.5};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    machine.next(); // g0 z5
    machine.next(); // t2
    machine.next(); // m6

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_tool_length_offset);
    expected_args = {3.8};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    CHECK(machine.toolOffset == Catch::Approx(3.8));
  }

  SECTION("Negative tool offset") {
    std::string code = "g10 p3 l1 z-1.2\n"
                       "t3 m6\n"
                       "g43 h3\n"
                       "g0 z10\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    machine.next(); // g10
    machine.next(); // t3
    machine.next(); // m6

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_tool_length_offset);
    expected_args = {-1.2};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    CHECK(machine.toolOffset == Catch::Approx(-1.2));

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_vec = {0, 0, 11.2};
    CHECK_approx_equal(machine.position, expected_vec);
  }
}

TEST_CASE("g54-59", "[g-code]") {
  SECTION("Basic workspace coordinate system") {
    std::string code = "g10 p2 l2 x100 z10\n"
                       "g55\n"
                       "g0 x10 y10\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_wcs_coordinates);
    expected_args = {2, 100, 0, 10};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    expected_vec = {100, 0, 10};
    CHECK(machine.workOffsets[1] == expected_vec);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_workspace);
    CHECK(machine.g5xoffset == machine.workOffsets[1]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_args = {10, 10, -10};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);
    expected_vec = {110, 10, 0};
    CHECK_approx_equal(machine.position, expected_vec);

    instruction = machine.next();
    CHECK(instruction.command == gpp::no_command);
  }

  SECTION("Multiple workspace switching") {
    std::string code = "g10 p1 l2 x10 y20 z5\n"
                       "g10 p3 l2 x50 y100 z15\n"
                       "g54\n"
                       "g0 x5 y5 z5\n"
                       "g56\n"
                       "g0 x5 y5 z5\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    machine.next(); // g10 p1
    machine.next(); // g10 p3

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_workspace);
    CHECK(machine.g5xoffset == machine.workOffsets[0]);

    machine.next(); // g0 in g54

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_workspace);
    CHECK(machine.g5xoffset == machine.workOffsets[2]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_vec = {55, 105, 20};
    CHECK_approx_equal(machine.position, expected_vec);
  }

  SECTION("Workspace with all axes") {
    std::string code = "g10 p4 l2 x25 y35 z45\n"
                       "g57\n"
                       "g0 x0 y0 z0\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    instruction = machine.next();
    CHECK(instruction.command == gpp::set_wcs_coordinates);
    expected_args = {4, 25, 35, 45};
    CHECK_VEC_EQUAL(instruction.arguments, expected_args);

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_workspace);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_vec = {25, 35, 45};
    CHECK_approx_equal(machine.position, expected_vec);
  }

  SECTION("Default workspace G54") {
    std::string code = "g10 p1 l2 x15 y25\n"
                       "g0 x10 y10\n"
                       "g54\n"
                       "g0 x10 y10\n";
    gpp::Machine machine(code);
    gpp::Vec3D expected_vec;
    std::vector<f64> expected_args;

    gpp::Instruction instruction;

    machine.next(); // g10
    machine.next(); // g0 (machine coordinates)

    instruction = machine.next();
    CHECK(instruction.command == gpp::use_workspace);
    CHECK(machine.g5xoffset == machine.workOffsets[0]);

    instruction = machine.next();
    CHECK(instruction.command == gpp::move_rapid);
    expected_vec = {25, 35, 0};
    CHECK_approx_equal(machine.position, expected_vec);
  }
}

TEST_CASE("g2 g3", "[g-code]") {
  std::string code = "f600\n"
                     "g0 x0 y0 z0\n"
                     "g2 x2 r1\n"
                     "g3 x0 r1\n"
                     "g0 x0 y0 z0\n"
                     "g2 x2 y2 i1 j1\n"
                     "g3 x0 y0 i-1 j-1\n";

  gpp::Machine machine(code);
  gpp::Vec3D expected_vec;
  std::vector<f64> expected_args;

  gpp::Instruction instruction;

  instruction = machine.next();
  CHECK(instruction.command == gpp::set_feed_rate);
  expected_args = {600};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::move_rapid);
  expected_args = {0, 0, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::arc_feed);
  expected_args = {2, 0, 1, 0, 1, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::arc_feed);
  expected_args = {0, 0, 1, 0, -1, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::move_rapid);
  expected_args = {0, 0, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::arc_feed);
  expected_args = {2, 2, 1, 1, 1, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::arc_feed);
  expected_args = {0, 0, 1, 1, -1, 0};
  CHECK_VEC_EQUAL(instruction.arguments, expected_args);

  instruction = machine.next();
  CHECK(instruction.command == gpp::no_command);
}
