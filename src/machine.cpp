#include "machine.hpp"
#include "gpp.hpp"

#include <cmath>
#include <iostream>

gpp::Machine::Machine(std::string input) : input(input), emitter(input) {
  this->position = (Vec3D){0, 0, 0};
  this->unit = Unit::mm;
  this->feedRate = 600; // 600.0 mm per minute => 1 cm per second
  std::cout << "Initialized machine!\n";
  gpp::Machine::print_specs();
  this->emitter.machine = this;

  handlers[Command::move_linear] =
      std::bind(&gpp::Machine::move_linear, this, std::placeholders::_1);
  handlers[Command::move_rapid] =
      std::bind(&gpp::Machine::move_rapid, this, std::placeholders::_1);
  handlers[Command::set_feed_rate] =
      std::bind(&gpp::Machine::set_feed_rate, this, std::placeholders::_1);
  handlers[Command::use_length_units] =
      std::bind(&gpp::Machine::use_length_units, this, std::placeholders::_1);
  handlers[Command::use_distance_mode] =
      std::bind(&gpp::Machine::use_distance_mode, this, std::placeholders::_1);
  handlers[Command::write_parameter_to_file] = std::bind(
      &gpp::Machine::write_parameter_to_file, this, std::placeholders::_1);
  handlers[Command::write_parameters_to_file] = std::bind(
      &gpp::Machine::write_parameters_to_file, this, std::placeholders::_1);
}

f64 gpp::Machine::get_memory(i64 address) {
  if (address < 0 || address >= memory.size()) {
    return NAN; // TODO replace with error later
  }

  return memory.at(address);
}

void gpp::Machine::set_memory(i64 address, f64 value) {
  if (address < 0)
    return;
  if (address >= memory.size()) {
    memory.resize(address + 1);
  }

  memory.at(address) = value;
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
  position = ResolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_linear(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";
}

void gpp::Machine::move_rapid(std::vector<f64> args) {
  position = ResolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_rapid(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";
}

void gpp::Machine::set_feed_rate(std::vector<f64> args) {
  std::cout << "set_feed_rate(" << args.at(0) << ")\n";
}

void gpp::Machine::use_length_units(std::vector<f64> args) {
  unit = (Unit)args.at(0);

  std::cout << "use_length_units(";
  std::cout << UnitToString(unit);
  std::cout << ")\n";
}

void gpp::Machine::use_distance_mode(std::vector<f64> args) {
  distanceMode = (DistanceMode)args.at(0);

  std::cout << "use_distance_mode(";
  std::cout << (distanceMode == absolute ? "absolute" : "relative");
  std::cout << ")\n";
};

void gpp::Machine::write_parameter_to_file(std::vector<f64> args) {
  std::cout << "write_parameter_to_file(" << args.at(0) << ")\n";
  std::ofstream file(".data.txt");
  if (!file) {
    std::cerr << "Failed to open .data.txt for writing\n";
    return;
  }

  file << "#" << args.at(0) << " = " << memory[args.at(0)] << "\n";

  file.close();
}

void gpp::Machine::write_parameters_to_file(std::vector<f64> args) {
  std::cout << "write_parameters_to_file(";

  std::ofstream file(".data.txt");
  if (!file) {
    std::cerr << "Failed to open .data.txt for writing\n";
    return;
  }

  for (size_t i = 1; i < memory.size(); ++i) {
    file << "#" << i << " = " << memory[i] << "\n";
  }

  file.close();

  std::cout << ")\n";
}

constexpr f64 gpp::Machine::UnitMultiplier(Unit unit) {
  switch (unit) {
  case Unit::mm:
    return 1.0;
  case Unit::cm:
    return 10.0;
  case Unit::inch:
    return 25.4;
  }
  return 1.0; // fallback
}

constexpr const char *gpp::Machine::UnitToString(Unit unit) {
  switch (unit) {
  case Unit::mm:
    return "mm";
  case Unit::cm:
    return "cm";
  case Unit::inch:
    return "in";
  }
  return "unknown";
}

gpp::Vec3D gpp::Machine::ResolvePosition(const f64 x, const f64 y,
                                         const f64 z) {
  Vec3D delta = {
      x * UnitMultiplier(unit),
      y * UnitMultiplier(unit),
      z * UnitMultiplier(unit),
  };

  if (distanceMode == DistanceMode::relative)
    return position + delta;
  else
    return delta;
}

gpp::Vec3D operator+(const gpp::Vec3D &a, const gpp::Vec3D &b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}