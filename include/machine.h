#ifndef smv_gcodepp_machine_h
#define smv_gcodepp_machine_h

#include "util.h"

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

void g_machine_init(g_machine *machine) {
  machine->position = (g_vec3d){0, 0, 0};
  machine->unit = g_unit_mm;
  machine->feed_rate = 600; // 600.0 mm per minute => 1 cm per second
}

#endif
