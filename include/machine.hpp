#ifndef smv_gcodepp_machine_hpp
#define smv_gcodepp_machine_hpp

#include "bytecode.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <vector>

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
typedef struct /* gpp:: */ g_machine {
  g_vec3d position; // CURRENT position
  g_unit unit;      // unit could be mm or inch (as per me -- read TODO below)
  f64 feed_rate;    // "speed" of the head in unit/min
                    // (TODO, add some references in comments)
  std::string code;
  void init();
  void run(std::vector<g_inst> bytecode);
  void print_specs();

  // TODO, decide if we're making functions like this
  // void rapid_move();
  // void move_linear();
  // void set_x();
  // void set_y();
  // void set_z();
  // void set_feedrate();
} g_machine;

/* "canonical operations" as I like to call them
 *
 * notice how there's an src/vm.c and no src/machine.c
 * this is because this header assumes that some machine.c would be linked
 * instead of vm.c for a specific machine
 */

#endif
