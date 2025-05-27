#ifndef smv_gcodepp_machine_hpp
#define smv_gcodepp_machine_hpp

#include "bytecode.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <functional>

typedef enum g_unit {
  g_unit_mm,
  g_unit_inch,
} g_unit;

typedef struct g_vec3d {
  i64 x, y, z;
} g_vec3d;

// represents the current state of a CNC machine
// this is EXTREMELY INCOMPLETE, all caps
// constant work in progress
struct /* gpp:: */ g_machine {

private:
  g_vec3d position; // CURRENT position
  g_vec3d target;   // target position, NOTE is this needed?
  g_unit unit;      // unit could be mm or inch (as per me -- read TODO below)
  f64 feed_rate;    // "speed" of the head in unit/min
  // (TODO, add some references in comments)
  std::string input;
  g_bytecode_emitter emitter;
  std::function<void(std::vector<f64>)> handlers[g_command_len];

public:
  g_machine(std::string input);
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
