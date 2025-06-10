#ifndef smv_gpp_machine_hpp
#define smv_gpp_machine_hpp

#include "bytecode.hpp"
#include "canvas.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <functional>
#include <vector>

enum gpp::Unit : u8 { mm = 0, inch = 1, cm = 2 };
enum gpp::DistanceMode : u8 { absolute = 0, relative = 1 };
enum gpp::SpindleDirection : i8 {
  clockwise = 1,
  off = 0,
  counterclockwise = -1,
};

struct gpp::Vec3D {
  f64 x, y, z;
  Vec3D operator+(const Vec3D &rhs);
  Vec3D operator-(const Vec3D &rhs);
  Vec3D operator*(f64 scalar);
  f64 dot(const Vec3D &rhs);
  Vec3D cross(const Vec3D &rhs);
};

struct gpp::Vec2D {
  f64 x, y;
  Vec2D operator+(const Vec2D &rhs);
  Vec2D operator-(const Vec2D &rhs);
  Vec2D operator*(f64 scalar);
  f64 dot(const Vec2D &rhs);
  Vec3D cross(const Vec2D &rhs);
};

// this length is temporary
#define g_command_len (256)
enum gpp::Command : u8 {
  move_linear = 0,
  move_rapid = 1,

  set_feed_rate = 2,

  use_length_units = 3,
  use_distance_mode = 4,
  select_plane = 5,

  arc_feed = 6,

  dwell = 7,
  set_origin_offsets = 8,

  start_spindle_clockwise = 9,
  start_spindle_counterclockwise = 10,
  stop_spindle_turning = 11,

  /*** this is temporary ***/
  write_parameter_to_file = 253,
  write_parameters_to_file = 254,

  no_command = 255, // invalid
};

enum gpp::Plane : u8 {
  plane_xy = 0,
  plane_yz = 1,
  plane_xz = 2,
};

// represents the current state of a CNC machine
// constant work in progress
struct gpp::Machine {
  friend class BytecodeEmitter;

private:
  BytecodeEmitter emitter;

  Vec3D position; // current position relative to (0, 0, 0), not origin
  Vec3D origin;   // absolute offset
  // Vec3D target;   // target position, NOTE is this needed?
  Unit unit; // unit could be mm or inch (as per me -- read TODO below)
  DistanceMode distanceMode; // absolute vs relative
  Plane plane;
  f64 feedRate; // "speed" of the head in unit/min
  SpindleDirection spindleDirection;
  // (TODO, add some references in comments)

  std::string input;
  std::function<void(std::vector<f64>)> handlers[g_command_len];

  Canvas canvasXY, canvasYZ, canvasXZ;

public:
  std::vector<f64> memory;

  Machine(std::string input);

  void setMemory(i64 address, f64 value);
  f64 getMemory(i64 address);
  Instruction next();
  void saveCanvases();

private:
  void print_specs();

  void move_linear(std::vector<f64> args);
  void move_rapid(std::vector<f64> args);

  void set_feed_rate(std::vector<f64> args);

  void use_length_units(std::vector<f64> args);
  void use_distance_mode(std::vector<f64> args);
  void select_plane(std::vector<f64> args);

  void arc_feed(std::vector<f64> args);

  void dwell(std::vector<f64> args);
  void set_origin_offsets(std::vector<f64> args);

  void start_spindle_clockwise(std::vector<f64> args);
  void start_spindle_counterclockwise(std::vector<f64> args);
  void stop_spindle_turning(std::vector<f64> args);

  /*** this is temporary ***/
  void write_parameter_to_file(std::vector<f64> args);
  void write_parameters_to_file(std::vector<f64> args);

  // helpers
  f64 unitMultiplier(Unit unit);
  const char *unitToString(Unit unit);
  const char *planeToString(Plane plane);
  Vec3D resolvePosition(const f64 x, const f64 y, const f64 z);
  void drawLineOnPlane(Canvas &canvas, gpp::Plane plane, gpp::Vec3D from,
                       gpp::Vec3D to);
  void drawLinesOnPlanes(Vec3D from, Vec3D to);
};

#endif
