#ifndef smv_gpp_machine_hpp
#define smv_gpp_machine_hpp

#include "bytecode.hpp"
#include "canvas.hpp"
#include "gpp.hpp"
#include "util.hpp"

#include <functional>
#include <unordered_map>
#include <vector>

#ifdef smv_gpp_testing
#define private public
#endif

enum gpp::Unit : u8 { mm = 0, inch = 1, cm = 2 };
enum gpp::DistanceMode : u8 { absolute = 0, relative = 1 };
enum gpp::SpindleDirection : i8 {
  clockwise = 1,
  off = 0,
  counterclockwise = -1,
};

enum gpp::FeedMode : u8 {
  inverse_time = 0,
  units_per_minute = 1,
  units_per_revolution = 2
};

enum gpp::SpindleMode : u8 { fixed_rpm = 0, constant_surface_speed = 1 };

// this length is temporary
#define g_command_len (256)
enum gpp::Command : u8 {
  move_linear = 1,
  move_rapid = 2,

  set_feed_rate = 3,
  set_feed_mode = 4,

  use_length_units = 5,
  use_distance_mode = 6,
  select_plane = 7,

  arc_feed = 8,

  dwell = 9,
  set_origin_offsets = 10,

  start_spindle_clockwise = 11,
  start_spindle_counterclockwise = 12,
  stop_spindle_turning = 13,
  set_spindle_speed = 14,
  set_spindle_mode = 15,

  select_tool = 16,
  change_tool = 17,

  program_stop = 18,
  optional_program_stop = 19,
  program_end = 20,

  use_tool_length_offset = 21,
  set_tool_length_offset = 22,

  set_wcs_coordinates = 23,
  use_workspace = 24,

  /*** this is temporary ***/
  write_parameter_to_file = 254,
  write_parameters_to_file = 255,

  no_command = 0, // invalid, wrapped around from 255+1
};

enum gpp::Plane : u8 {
  plane_xy = 0,
  plane_yz = 1,
  plane_xz = 2,
};

struct gpp::Tool {
  i64 pocket; // pocket number
  i64 fms;    // flexible manufacturing system (FMS) tool number T<>
  f64 tlo;    // tool length offset
  f64 diam;   // diameter
  i64 holder; // tool holder ID
  std::string description;
};
std::ostream &operator<<(std::ostream &os, const gpp::Tool &tool);

struct gpp::Vec3D {
  f64 x, y, z;
  Vec3D operator+(const Vec3D &rhs);
  Vec3D operator-(const Vec3D &rhs);
  Vec3D operator*(f64 scalar);
  bool operator==(const Vec3D &rhs);
  f64 dot(const Vec3D &rhs);
  Vec3D cross(const Vec3D &rhs);
};
std::ostream &operator<<(std::ostream &os, const gpp::Vec3D &v);

struct gpp::Vec2D {
  f64 x, y;
  Vec2D operator+(const Vec2D &rhs);
  Vec2D operator-(const Vec2D &rhs);
  Vec2D operator*(f64 scalar);
  f64 dot(const Vec2D &rhs);
  Vec3D cross(const Vec2D &rhs);
};

// represents the current state of a CNC machine
// constant work in progress
struct gpp::Machine {
  friend class BytecodeEmitter;

private:
  std::string input;
  BytecodeEmitter emitter;

  Vec3D position;       // current position relative to (0, 0, 0)
  Vec3D g5xoffset;      // offset from the origin due to g54-g59
  Vec3D g92offset;      // offset from the origin due to g92/g52
  f64 toolOffset;       // offset from the origin due to g43
  Vec3D workOffsets[6]; // offsets for g54-g59
  // Vec3D target;   // target position, NOTE is this needed?
  Unit unit; // unit could be mm or inch (as per me -- read TODO below)
  DistanceMode distanceMode; // absolute vs relative
  Plane plane;
  f64 rawFeedRate; // raw feedrate from set_feed_rate assuming unit/time
  f64 feedRate;    // always in mm/min
  FeedMode feedMode;
  SpindleMode spindleMode;
  SpindleDirection spindleDirection;
  f64 spindleSpeed;
  f64 rawSpindleSpeed;
  u64 selectedTool;
  u64 currentTool;
  std::unordered_map<int, Tool> tools;
  // (TODO, add some references in comments)

  std::function<void(std::vector<f64>)> handlers[g_command_len];

  Canvas canvasXY, canvasYZ, canvasXZ;
  bool plotToCanvas = false;

public:
  std::vector<f64> memory;

  Machine(std::string input);

  void setMemory(i64 address, f64 value);
  f64 getMemory(i64 address);
  Instruction next();
  void printSpecs();
  void saveCanvases();

private:
  void initTools(std::string file);

  void move_linear(std::vector<f64> args);
  void move_rapid(std::vector<f64> args);

  void set_feed_rate(std::vector<f64> args);
  void set_feed_mode(std::vector<f64> args);

  void use_length_units(std::vector<f64> args);
  void use_distance_mode(std::vector<f64> args);
  void select_plane(std::vector<f64> args);

  void arc_feed(std::vector<f64> args);

  void dwell(std::vector<f64> args);
  void set_origin_offsets(std::vector<f64> args);

  void start_spindle_clockwise(std::vector<f64> args);
  void start_spindle_counterclockwise(std::vector<f64> args);
  void stop_spindle_turning(std::vector<f64> args);
  void set_spindle_speed(std::vector<f64> args);
  void set_spindle_mode(std::vector<f64> args);

  void select_tool(std::vector<f64> args);
  void change_tool(std::vector<f64> args);

  void program_stop(std::vector<f64> args);
  void optional_program_stop(std::vector<f64> args);
  void program_end(std::vector<f64> args);

  void use_tool_length_offset(std::vector<f64> args);
  void set_tool_length_offset(std::vector<f64> args);

  void set_wcs_coordinates(std::vector<f64> args);
  void use_workspace(std::vector<f64> args);

  void canned_cycle_cancel(std::vector<f64> args);
  void canned_cycle_drill(std::vector<f64> args);
  void canned_cycle_dwell_drill(std::vector<f64> args);
  void canned_cycle_peck_drill(std::vector<f64> args);
  void canned_cycle_tap(std::vector<f64> args);
  void canned_cycle_bore(std::vector<f64> args);
  void canned_cycle_back_bore(std::vector<f64> args);
  void canned_cycle_bore_manual(std::vector<f64> args);
  void canned_cycle_bore_dwell(std::vector<f64> args);

  /*** this is temporary ***/
  void write_parameter_to_file(std::vector<f64> args);
  void write_parameters_to_file(std::vector<f64> args);

  // helpers
  f64 unitMultiplier(Unit unit);
  const char *unitToString(Unit unit);
  const char *planeToString(Plane plane);
  Vec3D getLogicalPosition();
  Vec3D resolvePosition(Vec3D delta);
  void handleCSSMode();
  void drawLineOnPlane(Canvas &canvas, Plane plane, Vec3D from, Vec3D to);
  void drawLinesOnPlanes(Vec3D from, Vec3D to);
};

#ifdef smv_gpp_testing
#undef private
#endif

#endif
