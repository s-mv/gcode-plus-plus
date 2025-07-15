/*
 * This file is heavily inspired by src/emc/canterp/canterp.cc
 * Author: Shreerang Vaidya (https://github.com/s-mv)
 * Copyright: GPL Version 2
 */

#include "config.h"
#include "emc/linuxcnc.h"
#include "emc/nml_intf/canon.hh"
#include "emc/nml_intf/interp_return.hh"
#include "emc/rs274ngc/interp_base.hh"
#include "modal_state.hh"
#include <algorithm>
#include <ctype.h>
#include <limits.h>
#include <memory>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <variant>

#include "bytecode.hpp"
#include "gpp.hpp"
#include "machine.hpp"

extern "C" void force_antlr4_lexer_rtti() { (void)typeid(antlr4::Lexer); }

gpp::Machine machine = gpp::Machine();
std::string currentLine;

class Sterp : public InterpBase {
  friend class gpp::Machine;

public:
  Sterp() : f(0) {
    std::cout << "STERP: Constructor called\n";
    force_antlr4_lexer_rtti();
  }

  char *error_text(int errcode, char *buf, size_t buflen);
  char *stack_name(int index, char *buf, size_t buflen);
  char *line_text(char *buf, size_t buflen);
  char *file_name(char *buf, size_t buflen);
  size_t line_length();
  int sequence_number();
  int ini_load(const char *inifile);
  int init();
  int execute();
  int execute(const char *line);
  int execute(const char *line, int line_number);
  int synch();
  int exit();
  int open(const char *filename);
  int read();
  int read(const char *line);
  int close();
  int reset();
  int line();
  int call_level();
  char *command(char *buf, size_t buflen);
  char *file(char *buf, size_t buflen);
  int on_abort(int reason, const char *message);
  void active_g_codes(int active_gcodes[ACTIVE_G_CODES]);
  void active_m_codes(int active_mcodes[ACTIVE_M_CODES]);
  void active_settings(double active_settings[ACTIVE_SETTINGS]);
  int active_modes(int g_codes[ACTIVE_G_CODES], int m_codes[ACTIVE_M_CODES],
                   double settings[ACTIVE_SETTINGS], StateTag const &tag);
  int restore_from_tag(StateTag const &tag);
  void print_state_tag(StateTag const &tag);
  void set_loglevel(int level);
  void set_loop_on_main_m99(bool state);
  FILE *f;
  char filename[PATH_MAX];
};

enum ControlToken {
  control_if,
  control_while,
  control_for,
  control_do,
  control_end,
};

using ControlStack = std::stack<ControlToken>;

ControlStack controlStack;

std::string controlSequence;

bool startsWith(const std::string &str, const std::string &pre) {
  return str.compare(0, pre.size(), pre) == 0;
}

bool endsWith(const std::string &str, const std::string &suf) {
  if (suf.size() > str.size())
    return false;
  return std::equal(suf.rbegin(), suf.rend(), str.rbegin());
}

char *Sterp::error_text(int errcode, char *buf, size_t buflen) {
  std::cout << "STERP: error_text(" << errcode << ")\n";
  if (errcode < INTERP_MIN_ERROR)
    snprintf(buf, buflen, "OK %d", errcode);
  else
    snprintf(buf, buflen, "ERROR %d", errcode);
  return buf;
}

char *Sterp::stack_name(int index, char *buf, size_t buflen) {
  std::cout << "STERP: stack_name(" << index << ")\n";
  snprintf(buf, buflen, "<stack %d>", index);
  return buf;
}

int Sterp::ini_load(const char *inifile) {
  std::cout << "STERP: ini_load(" << inifile << ")\n";
  return 0;
}

int Sterp::read(const char *line) {
  std::cout << "STERP: read(line=" << line << ")\n";

  currentLine = line;

  return INTERP_OK;
}

int Sterp::read() {
  std::cout << "STERP: read() from file\n";
  char buf[LINELEN];
  if (!f || !fgets(buf, sizeof(buf), f)) {
    std::cout << "STERP: Reached end of file\n";
    return INTERP_ENDFILE;
  }

  std::string line(buf);
  std::cout << "STERP: Read buffer = \"" << line
            << "\" (length = " << line.length() << ")\n";

  currentLine = line;

  return INTERP_OK;
}

int Sterp::execute(const char *line) {
  std::cout << "STERP: execute(\"" << (line ? line : "null") << "\")\n";

  std::string lineStr;

  if (!line)
    lineStr = currentLine;
  else
    lineStr = line;

  if (lineStr.empty()) {
    std::cout << "STERP: Null line passed. "
                 "Exiting Sterp::execute with no error...\n";
    return INTERP_OK;
  }

  lineStr.erase(0, lineStr.find_first_not_of(" \t\r\n"));
  lineStr.erase(lineStr.find_last_not_of(" \t\r\n") + 1);

  if (lineStr.empty()) {
    std::cout << "STERP: Empty or whitespace-only line, skipping\n";
    return INTERP_OK;
  }

  std::cout << "STERP: line is not empty or null.\n";
  lineStr += "\n";

  if (startsWith(lineStr, "if")) {
    controlStack.push(control_if);
    controlSequence += lineStr;
    return INTERP_OK;
  } else if (startsWith(lineStr, "for")) {
    std::cout << "lmao this line actually is a for loop\n";
    controlStack.push(control_for);
    controlSequence += lineStr;
    return INTERP_OK;
  } else if (startsWith(lineStr, "while")) {
    controlStack.push(control_while);
    controlSequence += lineStr;
    return INTERP_OK;
  }

  if (startsWith(lineStr, "end")) {
    std::cout << "yay this works lmao lesgo\n";
    if (!controlStack.empty())
      controlStack.pop();
    controlSequence += lineStr;
    lineStr = controlSequence;
    controlSequence.clear();
  }

  if (!controlStack.empty()) {
    controlSequence += lineStr;
    return INTERP_OK;
  }

  std::cout << "STERP: Parsing line: " << lineStr << "\n";

  auto emitter = std::make_shared<gpp::BytecodeEmitter>(machine, lineStr);

  std::string inputStash = machine.input;
  machine.input = lineStr;
  machine.bind(emitter);

  int line_num = 0;

  while (true) {
    SafeInstruction safeInstruction = machine.next();

    if (std::holds_alternative<gpp::Error>(safeInstruction)) {
      gpp::Error error = std::get<gpp::Error>(safeInstruction);
      std::cout << "STERP: Error while parsing line\n";
      error.print();
      machine.unbind();
      machine.input = inputStash;
      return INTERP_ERROR;
    }

    gpp::Instruction instruction = std::get<gpp::Instruction>(safeInstruction);

    if (instruction.command == gpp::no_command) {
      std::cout << "STERP: Reached end of instruction stream\n";
      break;
    }

    const std::vector<f64> &args = instruction.arguments;

    std::cout << "STERP: Instruction command -> " << instruction.command
              << "\n";
    std::cout << "STERP: Args -> ";
    for (f64 arg : args)
      std::cout << arg << " ";
    std::cout << "\n";
    std::cout << "STERP: Machine pos -> " << machine.position << "\n";

    switch (instruction.command) {
    case gpp::move_linear: {
      std::cout << "STERP: move linear\n";
      STRAIGHT_FEED(line_num, machine.position.x, machine.position.y,
                    machine.position.z, 0, 0, 0, 0, 0, 0);
      break;
    }
    case gpp::move_rapid: {
      std::cout << "STERP: move rapid\n";
      STRAIGHT_TRAVERSE(line_num, machine.position.x, machine.position.y,
                        machine.position.z, 0, 0, 0, 0, 0, 0);
      break;
    }

    case gpp::set_feed_rate: {
      SET_FEED_RATE(args.at(0));
      break;
    }
    case gpp::set_feed_mode: {
      break;
    }

    case gpp::use_length_units: {
      if (machine.unit == gpp::Unit::mm)
        USE_LENGTH_UNITS(CANON_UNITS::CANON_UNITS_MM);
      else if (machine.unit == gpp::Unit::inch)
        USE_LENGTH_UNITS(CANON_UNITS::CANON_UNITS_INCHES);
      break;
    }
    case gpp::use_distance_mode: {
      break;
    }
    case gpp::select_plane: {
      CANON_PLANE plane = CANON_PLANE_XZ;
      if (machine.plane == gpp::plane_xy)
        plane = CANON_PLANE_XY;
      if (machine.plane == gpp::plane_yz)
        plane = CANON_PLANE_YZ;
      if (machine.plane == gpp::plane_xz)
        plane = CANON_PLANE_XZ;

      SELECT_PLANE(plane);
      break;
    }

    case gpp::arc_feed: {
      break;
    }

    case gpp::dwell: {
      DWELL(args.at(0));
      break;
    }
    case gpp::set_origin_offsets: {
      break;
    }

    case gpp::start_spindle_clockwise: {
      START_SPINDLE_CLOCKWISE(0);
      break;
    }
    case gpp::start_spindle_counterclockwise: {
      break;
      START_SPINDLE_COUNTERCLOCKWISE(0);
    }
    case gpp::stop_spindle_turning: {
      STOP_SPINDLE_TURNING(0);
      break;
    }
    case gpp::set_spindle_speed: {
      SET_SPINDLE_SPEED(0, args.at(0));
      break;
    }
    case gpp::set_spindle_mode: {
      break;
    }

    case gpp::select_tool: {
      SELECT_TOOL(args.at(0));
      break;
    }
    case gpp::change_tool: {
      CHANGE_TOOL_NUMBER(machine.currentTool);
      break;
    }

    case gpp::program_stop: {
      PROGRAM_STOP();
      break;
    }
    case gpp::optional_program_stop: {
      OPTIONAL_PROGRAM_STOP();
      break;
    }
    case gpp::program_end: {
      PROGRAM_END();
      break;
    }

    case gpp::use_tool_length_offset: {
      // USE_TOOL_LENGTH_OFFSET(); // TODO
      break;
    }
    case gpp::set_tool_length_offset: {
      // TODO
      break;
    }

    case gpp::set_wcs_coordinates: {
      break;
    }
    case gpp::use_workspace: {
      break;
    }

    case gpp::set_retract_mode: {
      break;
    }
    case gpp::set_motion_control_mode: {
      CANON_MOTION_MODE mode = CANON_CONTINUOUS;
      if (machine.motionControlMode == gpp::exact_stop)
        mode = CANON_EXACT_STOP;
      if (machine.motionControlMode == gpp::exact_path)
        mode = CANON_EXACT_PATH;
      if (machine.motionControlMode == gpp::continuous)
        mode = CANON_CONTINUOUS;
      SET_MOTION_CONTROL_MODE(mode, 0);
      break;
    }

    /*** this is temporary ***/
    case gpp::write_parameter_to_file: {
      break;
    }
    case gpp::write_parameters_to_file: {
      break;
    }

    case gpp::no_command: {
      std::cout << "STERP: No Command! This shouldn't even be printed.\n";
      break;
    }

    default:
      return INTERP_ERROR;
    }
  }
  machine.unbind();
  machine.input = inputStash;

  return INTERP_OK;
}

int Sterp::execute(const char *line, int line_number) {
  std::cout << "STERP: execute(line, line_number=" << line_number << ")\n";
  if (!line)
    return execute(currentLine.c_str());
  return execute(line);
}

int Sterp::execute() {
  std::cout << "STERP: execute() [no-arg]\n";
  return execute(currentLine.c_str());
}

int Sterp::open(const char *newfilename) {
  std::cout << "STERP: open(\"" << newfilename << "\")\n";
  if (f)
    fclose(f);
  f = fopen(newfilename, "r");
  if (f) {
    snprintf(filename, sizeof(filename), "%s", newfilename);
    std::cout << "STERP: Successfully opened file\n";
  } else {
    std::cerr << "STERP: Failed to open file\n";
  }
  return f ? INTERP_OK : INTERP_ERROR;
}

int Sterp::close() {
  std::cout << "STERP: close()\n";
  if (f)
    fclose(f);
  f = nullptr;
  return INTERP_OK;
}

int Sterp::exit() {
  std::cout << "STERP: exit()\n";
  return 0;
}

int Sterp::synch() {
  std::cout << "STERP: synch()\n";
  return 0;
}

int Sterp::reset() {
  std::cout << "STERP: reset()\n";
  return 0;
}

int Sterp::line() {
  std::cout << "STERP: line()\n";
  return 0;
}

int Sterp::call_level() {
  std::cout << "STERP: call_level()\n";
  return 0;
}

char *Sterp::line_text(char *buf, size_t bufsize) {
  snprintf(buf, bufsize, "<Sterp::line_text>");
  return buf;
}

char *Sterp::file_name(char *buf, size_t bufsize) {
  snprintf(buf, bufsize, "%s", filename);
  return buf;
}

char *Sterp::file(char *buf, size_t bufsize) {
  snprintf(buf, bufsize, "%s", filename);
  return buf;
}

int Sterp::on_abort(int reason, const char *message) {
  std::cerr << "STERP: on_abort(reason=" << reason << ", message=" << message
            << ")\n";
  reset();
  return INTERP_OK;
}

char *Sterp::command(char *buf, size_t bufsize) {
  snprintf(buf, bufsize, "<Sterp::command>");
  return buf;
}

size_t Sterp::line_length() {
  std::cout << "STERP: line_length()\n";
  return 0;
}

int Sterp::sequence_number() {
  std::cout << "STERP: sequence_number()\n";
  return -1;
}

int Sterp::init() {
  std::cout << "STERP: init()\n";
  return INTERP_OK;
}

void Sterp::active_g_codes(int gees[]) {
  // std::cout << "STERP: active_g_codes()\n";
  std::fill(gees, gees + ACTIVE_G_CODES, 0);
}

void Sterp::active_m_codes(int emms[]) {
  // std::cout << "STERP: active_m_codes()\n";
  std::fill(emms, emms + ACTIVE_M_CODES, 0);
}

void Sterp::active_settings(double sets[]) {
  // std::cout << "STERP: active_settings()\n";
  std::fill(sets, sets + ACTIVE_SETTINGS, 0.0);
}

int Sterp::restore_from_tag(StateTag const &tag) {
  std::cout << "STERP: restore_from_tag()\n";
  return -1;
}

void Sterp::print_state_tag(StateTag const &tag) {
  std::cout << "STERP: print_state_tag()\n";
}

int Sterp::active_modes(int g_codes[], int m_codes[], double settings[],
                        const StateTag &tag) {
  // std::cout << "STERP: active_modes()\n";
  return -1;
}

void Sterp::set_loglevel(int level) {
  std::cout << "STERP: set_loglevel(" << level << ")\n";
}

void Sterp::set_loop_on_main_m99(bool state) {
  std::cout << "STERP: set_loop_on_main_m99(" << (state ? "true" : "false")
            << ")\n";
}

extern "C" InterpBase *makeInterp() {
  std::cout << "STERP: makeInterp() called\n";
  return new Sterp;
}
