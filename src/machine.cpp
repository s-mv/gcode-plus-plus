#include "machine.hpp"
#include "bytecode.hpp"

#include <iostream>

gpp::Machine::Machine(std::string input) : input(input), emitter(input) {
  this->position = (Vec3D){0, 0, 0};
  this->unit = g_unit_mm;
  this->feed_rate = 600; // 600.0 mm per minute => 1 cm per second
  std::cout << "Initialized machine!\n";
  gpp::Machine::print_specs();

  handlers[g_command::move_linear] =
      std::bind(&gpp::Machine::move_linear, this, std::placeholders::_1);
  handlers[g_command::move_rapid] =
      std::bind(&gpp::Machine::move_rapid, this, std::placeholders::_1);
  handlers[g_command::set_feed_rate] =
      std::bind(&gpp::Machine::set_feed_rate, this, std::placeholders::_1);
  handlers[g_command::set_unit_in] =
      std::bind(&gpp::Machine::set_unit_in, this, std::placeholders::_1);
  handlers[g_command::set_unit_mm] =
      std::bind(&gpp::Machine::set_unit_mm, this, std::placeholders::_1);
}

bool gpp::Machine::next() {
  Instruction inst = emitter.next();
  // TODO, change machine state

  if (inst.command == no_command)
    return false;

  handlers[inst.command](inst.arguments);

  return true;
}

void gpp::Machine::print_specs() {}

void gpp::Machine::move_linear(std::vector<f64> args) {
  std::cout << "move_linear(" << args.at(0) << ", " << args.at(1) << ", "
            << args.at(2) << ")\n";
}

void gpp::Machine::move_rapid(std::vector<f64> args) {
  std::cout << "move_rapid(" << args.at(0) << ", " << args.at(1) << ", "
            << args.at(2) << ")\n";
}

void gpp::Machine::set_feed_rate(std::vector<f64> args) {
  std::cout << "set_feed_rate(" << args.at(0) << ")\n";
}

void gpp::Machine::set_unit_in(std::vector<f64> args) {
  std::cout << "set_unit(in)\n";
}

void gpp::Machine::set_unit_mm(std::vector<f64> args) {
  std::cout << "set_unit(mm)\n";
}
