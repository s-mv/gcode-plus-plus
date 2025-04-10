#ifndef smv_gcodepp_lexer_hpp
#define smv_gcodepp_lexer_hpp

#include "util.hpp"

/*
 * g_token_type
 *
 * small foreword - most these start with `g_word` because it's easier to
 * identify words as opposed to, say, operator tokens, number tokens, etc.
 *
 * "A word is a letter other than N followed by a real value. Words may begin
 * with any of the letters shown in the following Table. The table includes N
 * for completeness, even though, as defined above, line numbers are not words.
 * Several letters (I, J, K, L, P, R) may have different meanings in different
 * contexts. Letters which refer to axis names are not valid on a machine which
 * does not have the corresponding axis."
 *
 * REFERENCE: https://linuxcnc.org/docs/stable/html/gcode/overview.html#_word
 *
 * NOTE: words that have been assigned a character in the enum (like 'g' or 'x')
 * are the ones being implemented (or are already implemented)
 */

typedef enum g_token_type {
  a,       // A axis of machine
  b,       // B axis of machine
  c,       // C axis of machine
  d,       // Tool radius compensation number
  f = 'f', // Feed rate
  g = 'g', // General function (See table G-code Modal Groups)
  h,       // Tool length offset index
  i,       // X offset for arcs and G87 canned cycles
  j,       // Y offset for arcs and G87 canned cycles
  k,       // Z offset for arcs and G87 canned cycles. Spindle-Motion Ratio for
           // G33 synchronized movements
  l,       // Generic parameter word for G10, M66 and others
  m,       // Miscellaneous function (See table M-code Modal Groups)
  n,       // Line number
  p,       // Dwell time in canned cycles and with G4. Key used with G10
  q,       // Feed increment in G73, G83 canned cycles
  r,       // Arc radius or canned cycle plane
  s,       // Spindle speed
  t,       // Tool selection
  u,       // U axis of machine
  v,       // V axis of machine
  w,       // W axis of machine
  x = 'x', // X axis of machine
  y = 'y', // Y axis of machine
  z = 'z', // Z axis of machine

  // I don't know if these can be considered words
  // but for now let's call them that for the sake of it
  at,        // @ - polar distance
  xor_angle, // ^ - polar angle, not named `xor` since it's a keyword

  newline,

  symbol, // +, -, [, ], etc.
  number, // real number or integer

  function, // https://linuxcnc.org/docs/stable/html/gcode/overview.html#gcode:functions

  if_token,
  else_token,
  then,
  end,

  variable, // TODO, what is this? decide or find existing specification

  /* TODO: see how to handle g_token_block and g_token_comment */
} g_token_type;

struct g_token_position {
  u64 line;
  u64 column;
  u64 index;

  g_token_position(u64 line, u64 column, u64 index)
      : line(line), column(column), index(index) {}
};

union g_token_data {
  i64 num;
  u64 unum;
  f64 fnum;
  char symbol;
  g_dynarr(char) string;
  void *misc;
};

struct g_token {
  g_token_position position;
  g_token_type type;
  bool is_float;
  // the type of the data can be easily determined based on
  // token_type and is_float
  g_token_data data;

  g_token() : position(1, 1, 0), type(g_token_type::end), is_float(false) {};
};

g_dynarr(g_token) g_lex(const char *code);
void print_token(g_token token);

#endif
