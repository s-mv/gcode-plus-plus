#include "machine.h"

void g_machine_init(g_machine *machine) {
  machine->position = (g_vec3d){0, 0, 0};
  machine->unit = g_unit_mm;
  machine->feed_rate = 600; // 600.0 mm per minute => 1 cm per second
}