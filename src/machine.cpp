#include "machine.hpp"
#include "bytecode.hpp"

#include <iostream>

void g_machine::init() {
  this->position = (g_vec3d){0, 0, 0};
  this->unit = g_unit_mm;
  this->feed_rate = 600; // 600.0 mm per minute => 1 cm per second
  std::cout << "Initialized machine!\n";
  g_machine::print_specs();
}

void g_machine::run(std::vector<g_inst> bytecode) {
  for (int i = 0; i < bytecode.size(); i++) {
    int start = i, end = i;
    g_inst inst = bytecode.at(i);
    g_inst next;
    switch (inst.code) {
    case g_opcode::rapid_move:
      std::cout << "RAPID MOVE\n";
      break;
    case g_opcode::linear_move:
      std::cout << "LINEAR MOVE\n";
      break;
    case g_opcode::set_x:
      next = bytecode.at(++i);
      std::cout << "SET X TO " << next.attr << "\n";
      break;
    case g_opcode::set_y:
      next = bytecode.at(++i);
      std::cout << "SET Y TO " << next.attr << "\n";
      break;
    case g_opcode::set_z:
      next = bytecode.at(++i);
      std::cout << "SET Z TO " << next.attr << "\n";
      break;
    case g_opcode::set_feedrate:
      next = bytecode.at(++i);
      std::cout << "SET FEED RATE TO " << next.attr << "\n";
      break;
    case g_opcode::end_line:
      // TODO
      std::cout << "END LINE\n";
      break;
    default:
      break;
    }
  }
  std::cout << std::endl;
}

void g_machine::print_specs() {}
