#ifndef smv_gpp_machine_hpp
#define smv_gpp_machine_hpp

#include "bytecode.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <functional>
#include <vector>

enum gpp::Unit : u8 { mm = 0, inch = 1, cm = 2 };
enum gpp::DistanceMode : u8 { absolute = 0, relative = 1 };

struct gpp::Vec3D {
  f64 x, y, z;
};

// this length is temporary
#define g_command_len (256)
enum gpp::Command : u8 {
  move_linear = 0,
  move_rapid = 1,

  set_feed_rate = 2,

  use_length_units = 3,
  use_distance_mode = 4,

  /*** this is temporary ***/
  write_parameter_to_file = 253,
  write_parameters_to_file = 254,

  no_command = 255, // invalid
};

// represents the current state of a CNC machine
// this is EXTREMELY INCOMPLETE, all caps
// constant work in progress
struct gpp::Machine {
private:
  BytecodeEmitter emitter;

  Vec3D position; // CURRENT position
  Vec3D target;   // target position, NOTE is this needed?
  Unit unit;      // unit could be mm or inch (as per me -- read TODO below)
  DistanceMode distanceMode; // absolute vs relative
  f64 feedRate;              // "speed" of the head in unit/min
  // (TODO, add some references in comments)

  std::string input;
  std::function<void(std::vector<f64>)> handlers[g_command_len];

public:
  std::vector<f64> memory;

  Machine(std::string input);
  f64 get_memory(i64 address);
  void set_memory(i64 address, f64 value);
  bool next();

private:
  void print_specs();

  void move_linear(std::vector<f64> args);
  void move_rapid(std::vector<f64> args);
  void set_feed_rate(std::vector<f64> args);
  void use_length_units(std::vector<f64> args);
  void use_distance_mode(std::vector<f64> args);

  /*** this is temporary ***/
  void write_parameter_to_file(std::vector<f64> args);
  void write_parameters_to_file(std::vector<f64> args);

  // helpers
  constexpr f64 UnitMultiplier(Unit unit);
  constexpr const char *UnitToString(Unit unit);
  Vec3D ResolvePosition(const f64 x, const f64 y, const f64 z);
};

gpp::Vec3D operator+(const gpp::Vec3D &a, const gpp::Vec3D &b);

#endif
