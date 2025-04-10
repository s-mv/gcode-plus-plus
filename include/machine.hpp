#ifndef smv_gcodepp_machine_hpp
#define smv_gcodepp_machine_hpp

#include "util.hpp"

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
typedef struct g_machine {
  g_vec3d position; // CURRENT position
  g_unit unit;      // unit could be mm or inch (as per me -- read TODO below)
  f64 feed_rate;    // "speed" of the head in unit/min
                    // (TODO, add some references in comments)
} g_machine;


void g_machine_init(g_machine *machine);
void g_machine_run(g_dynarr(char) code);


/* "canonical operations" as I like to call them
 *
 * notice how there's an src/vm.c and no src/machine.c
 * this is because this header assumes that some machine.c would be linked
 * instead of vm.c for a specific machine
 */




 #endif
