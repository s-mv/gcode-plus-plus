#ifndef smv_gcodepp_lexer_h
#define smv_gcodepp_lexer_h

#include "util.h"

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

  g_word_a,       // A axis of machine
  g_word_b,       // B axis of machine
  g_word_c,       // C axis of machine
  g_word_d,       // Tool radius compensation number
  g_word_f,       // Feed rate
  g_word_g = 'g', // General function (See table G-code Modal Groups)
  g_word_h,       // Tool length offset index
  g_word_i,       // X offset for arcs and G87 canned cycles
  g_word_j,       // Y offset for arcs and G87 canned cycles
  g_word_k, // Z offset for arcs and G87 canned cycles. Spindle-Motion Ratio for
            // G33 synchronized movements
  g_word_l, // Generic parameter word for G10, M66 and others
  g_word_m, // Miscellaneous function (See table M-code Modal Groups)
  g_word_n, // Line number
  g_word_p, // Dwell time in canned cycles and with G4. Key used with G10
  g_word_q, // Feed increment in G73, G83 canned cycles
  g_word_r, // Arc radius or canned cycle plane
  g_word_s, // Spindle speed
  g_word_t, // Tool selection
  g_word_u, // U axis of machine
  g_word_v, // V axis of machine
  g_word_w, // W axis of machine
  g_word_x = 'x', // X axis of machine
  g_word_y = 'y', // Y axis of machine
  g_word_z = 'z', // Z axis of machine

  // I don't know if these can be considered words
  // but for now let's call them that for the sake of it
  g_word_at,  // @ - polar distance
  g_word_xor, // ^ - polar angle

  g_token_newline,

  g_token_symbol, // +, -, [, ], etc.
  g_token_number, // real number or integer

  g_token_function, // https://linuxcnc.org/docs/stable/html/gcode/overview.html#gcode:functions

  g_token_variable, // TODO, what is this? decide or find existing specification
} g_token_type;

typedef struct g_token_position {
  u64 line;
  u64 column;
  u64 index;
} g_token_position;

typedef union g_token_data {
  i64 num;
  u64 unum;
  f64 fnum;
  char symbol;
  g_dynarr(char) string;
  void *misc;
} g_token_data;

typedef struct g_token {
  g_token_position position;
  g_token_type type;
  bool is_float;
  // the type of the data can be easily determined based on
  // token_type and is_float
  g_token_data data;
} g_token;

g_dynarr(g_token) lex(const char *code);
void print_token(g_token token);

#endif
