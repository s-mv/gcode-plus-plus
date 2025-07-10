/*
 * This file is heavily inspired by src/emc/canterp/canterp.cc
 * Author: Shreerang Vaidya (https://github.com/s-mv)
 * Copyright: GPL Version 2
 * */

#include "config.h"
#include "emc/linuxcnc.h"
#include "emc/nml_intf/canon.hh"
#include "emc/nml_intf/interp_return.hh"
#include "emc/rs274ngc/interp_base.hh"
#include "modal_state.hh"
#include <algorithm>
#include <ctype.h> // isspace()
#include <limits.h>
#include <stdio.h>  // FILE, fopen(), fclose()
#include <string.h> // strcpy()

#include "bytecode.hpp"
#include "gpp.hpp"
#include "machine.hpp"
#include "util.hpp"

static char the_command[LINELEN] = {0};      // our current command
static char the_command_name[LINELEN] = {0}; // just the name part
static char the_command_args[LINELEN] = {0}; // just the args part

class Sterp : public InterpBase {
public:
  Sterp() : f(0) {}
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

private:
  gpp::Machine machine;
};

char *Sterp::error_text(int errcode, char *buf, size_t buflen) {
  if (errcode < INTERP_MIN_ERROR)
    snprintf(buf, buflen, "OK %d", errcode);
  else
    snprintf(buf, buflen, "ERROR %d", errcode);
  return buf;
}

char *Sterp::stack_name(int index, char *buf, size_t buflen) {
  snprintf(buf, buflen, "<stack %d>", index);
  return buf;
}

int Sterp::ini_load(const char *inifile) { return 0; }

static char *skipwhite(char *ptr) {
  while (isspace(*ptr))
    ptr++;
  return ptr;
}

static char *findwhite(char *ptr) {
  while (!isspace(*ptr) && 0 != *ptr)
    ptr++;
  return ptr;
}

static int sterp_parse(char *buffer) { machine = gpp::Machine(buffer); }

int Sterp::read(const char *line) { return sterp_parse((char *)line); }

int Sterp::read() {
  char buf[LINELEN];
  if (!f)
    return INTERP_ERROR;
  if (!fgets(buf, sizeof(buf), f))
    return INTERP_ENDFILE;
  return sterp_parse(buf);
}

int Sterp::execute(const char *line) {
  gpp::BytecodeEmitter emitter = gpp::BytecodeEmitter(machine, line);
  machine.bind(emitter);
  
  

  machine.unbind(emitter);
}

int Sterp::execute(const char *line, int line_number) { return execute(line); }

int Sterp::execute() { return execute(0); }

int Sterp::open(const char *newfilenam) {
  if (f)
    fclose(f);
  f = fopen(newfilename, "r");
  if (f)
    snprintf(filename, sizeof(filename), "%s", newfilename);
  return f ? INTERP_OK : INTERP_ERROR;
}

int Sterp::close() { return INTERP_OK; }

int Sterp::exit() { return 0; }
int Sterp::synch() { return 0; }
int Sterp::reset() { return 0; }
int Sterp::line() { return 0; }
int Sterp::call_level() { return 0; }

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
  fprintf(stderr, "Sterp::on_abort reason=%d message='%s'", reason, message);
  reset();
  return INTERP_OK;
}
char *Sterp::command(char *buf, size_t bufsize) {
  snprintf(buf, bufsize, "<Sterp::command>");
  return buf;
}
size_t Sterp::line_length() { return 0; }
int Sterp::sequence_number() { return -1; }
int Sterp::init() { return INTERP_OK; }
void Sterp::active_g_codes(int gees[]) {
  std::fill(gees, gees + ACTIVE_G_CODES, 0);
}
void Sterp::active_m_codes(int emms[]) {
  std::fill(emms, emms + ACTIVE_M_CODES, 0);
}
void Sterp::active_settings(double sets[]) {
  std::fill(sets, sets + ACTIVE_SETTINGS, 0.0);
}
// NOT necessary for sterp
int Sterp::restore_from_tag(StateTag const &tag) { return -1; }
void Sterp::print_state_tag(StateTag const &tag) {}

int Sterp::active_modes(int g_codes[ACTIVE_G_CODES],
                        int m_codes[ACTIVE_M_CODES],
                        double settings[ACTIVE_SETTINGS], StateTag const &tag) {
  return -1;
}

void Sterp::set_loglevel(int level) {}
void Sterp::set_loop_on_main_m99(bool state) {}

InterpBase *makeInterp() { return new Sterp; }

