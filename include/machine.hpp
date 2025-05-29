#ifndef smv_gcodepp_machine_hpp
#define smv_gcodepp_machine_hpp

#include "bytecode.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <functional>
#include <vector>

enum gpp::Unit : u8 {
  g_unit_mm,
  g_unit_inch,
};

struct gpp::Vec3D {
  i64 x, y, z;
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
  f64 feed_rate;  // "speed" of the head in unit/min
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
  void set_unit_in(std::vector<f64> args);
  void set_unit_mm(std::vector<f64> args);
};

#endif
