#ifndef smv_gcodepp_machine_h
#define smv_gcodepp_machine_h

#include "util.h"

typedef struct g_position {
  i64 x, y, z;
} g_position;

// represents the current state of a CNC machine
typedef struct machine {
  g_position position;
} machine;

#endif