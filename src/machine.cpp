#include "machine.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <cmath>
#include <iostream>
#include <vector>

gpp::Machine::Machine(std::string input) : input(input), emitter(input) {
  this->position = (Vec3D){0, 0, 0};
  this->offset = (Vec3D){0, 0, 0};
  this->unit = Unit::mm;
  this->distanceMode = absolute;
  this->plane = plane_xy;
  this->feedRate = 0;
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
  handlers[Command::select_plane] =
      std::bind(&gpp::Machine::select_plane, this, std::placeholders::_1);
  handlers[Command::arc_feed] =
      std::bind(&gpp::Machine::arc_feed, this, std::placeholders::_1);
  handlers[Command::dwell] =
      std::bind(&gpp::Machine::dwell, this, std::placeholders::_1);

  handlers[Command::set_origin_offsets] =
      std::bind(&gpp::Machine::set_origin_offsets, this, std::placeholders::_1);

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
  position = resolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_linear(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";
}

void gpp::Machine::move_rapid(std::vector<f64> args) {
  position = resolvePosition(args.at(0), args.at(1), args.at(2));
  std::cout << "move_rapid(" << position.x << ", " << position.y << ", "
            << position.z << ")\n";
}

void gpp::Machine::set_feed_rate(std::vector<f64> args) {
  feedRate = args.at(0);
  std::cout << "set_feed_rate(" << feedRate << ")\n";
}

void gpp::Machine::use_length_units(std::vector<f64> args) {
  unit = (Unit)args.at(0);

  std::cout << "use_length_units(";
  std::cout << unitToString(unit);
  std::cout << ")\n";
}

void gpp::Machine::use_distance_mode(std::vector<f64> args) {
  distanceMode = (DistanceMode)args.at(0);

  std::cout << "use_distance_mode(";
  std::cout << (distanceMode == absolute ? "absolute" : "relative");
  std::cout << ")\n";
};

void gpp::Machine::select_plane(std::vector<f64> args) {
  plane = (Plane)args.at(0);

  std::cout << "use_length_units(";
  std::cout << plane;
  std::cout << ")\n";
}

void gpp::Machine::arc_feed(std::vector<f64> args) {
  f64 first_end = args.at(0);
  f64 second_end = args.at(1);
  f64 first_axis = args.at(2);
  f64 second_axis = args.at(3);
  int rotation = args.at(4);
  f64 axis_end_point = args.at(5);

  if (plane == plane_xy)
    position = resolvePosition(first_end, second_end, axis_end_point);
  else if (plane == plane_yz)
    position = resolvePosition(axis_end_point, first_end, second_end);
  else
    position = resolvePosition(first_end, axis_end_point, second_end);

  std::cout << "arc_feed(" << first_end << ", " << second_end << ", "
            << first_axis << ", " << second_axis << ", " << rotation << ", "
            << axis_end_point << ")\n";
}

void gpp::Machine::dwell(std::vector<f64> args) {
  std::cout << "dwell(" << args.at(0) << ")\n";
}

void gpp::Machine::set_origin_offsets(std::vector<f64> args) {
  std::cout << "TODO!()\n";
}

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

/* helpers */

f64 gpp::Machine::unitMultiplier(Unit unit) {
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

const char *gpp::Machine::unitToString(Unit unit) {
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

const char *gpp::Machine::planeToString(Plane plane) {
  return plane == plane_xy ? "XY" : (plane == plane_yz ? "YZ" : "XZ");
}

gpp::Vec3D gpp::Machine::resolvePosition(const f64 x, const f64 y,
                                         const f64 z) {
  if (std::isnan(x) && std::isnan(y) && std::isnan(z))
    ; // TODO, error handling and handling individual axes

  Vec3D delta = {x, y, z};
  delta = delta * unitMultiplier(unit);

  if (distanceMode == DistanceMode::relative)
    return position + delta;
  else {
    Vec3D logical_target = delta;
    return logical_target + offset;
  }
}

gpp::Vec3D gpp::Vec3D::operator+(const Vec3D &rhs) {
  return {x + rhs.x, y + rhs.y, z + rhs.z};
}

gpp::Vec3D gpp::Vec3D::operator-(const Vec3D &rhs) {
  return {x - rhs.x, y - rhs.y, z - rhs.z};
}

gpp::Vec3D gpp::Vec3D::operator*(f64 scalar) {
  return {x * scalar, y * scalar, z * scalar};
}

f64 gpp::Vec3D::dot(const Vec3D &rhs) {
  return x * rhs.x + y * rhs.y + z * rhs.z;
}

gpp::Vec3D gpp::Vec3D::cross(const Vec3D &rhs) {
  return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x};
}

gpp::Vec2D gpp::Vec2D::operator+(const Vec2D &rhs) {
  return {x + rhs.x, y + rhs.y};
}

gpp::Vec2D gpp::Vec2D::operator-(const Vec2D &rhs) {
  return {x - rhs.x, y - rhs.y};
}

gpp::Vec2D gpp::Vec2D::operator*(f64 scalar) {
  return {x * scalar, y * scalar};
}

f64 gpp::Vec2D::dot(const Vec2D &rhs) { return x * rhs.x + y * rhs.y; }

gpp::Vec3D gpp::Vec2D::cross(const Vec2D &rhs) {
  return {0, 0, x * rhs.y - y * rhs.x};
}
