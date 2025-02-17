#include "lexer.h"

#include <ctype.h>
#include <string.h>

#include "util.h"

void skip(const char *code, g_token_position *pos);
char next(const char *code, g_token_position *pos);
char current(const char *code, g_token_position *pos);
char peek(const char *code, g_token_position *pos);
char peek2(const char *code, g_token_position *pos);

bool parse_num(const char *code, g_token_position *pos, g_token *token);

g_dynarr(g_token) lex(const char *code) {
  g_dynarr(g_token) tokens; // RESPONSIBILITY OF DEALLOCATION TO CALLEE
  g_dynarr_init(&tokens, sizeof(g_token));

  g_token_position pos = {.index = 0, .line = 1, .column = 1};
  const int len = strlen(code);
  for (pos.index = 0; pos.index < len; pos.index++) {
    char current = code[pos.index];
    g_token token = {0};

    switch (current) {
    case 'g':
    case 'x':
    case 'y':
    case 'z':
      token.word_type = current;
      skip(code, &pos);
      if (!parse_num(code, &pos, &token))
        ; // TODO, error (some kind of panic mode)

      g_dynarr_push(&tokens, &token);
      break;

    case '/':
    case ';':
      // TODO, skip single line comments
      break;

    case '(':
      // TODO, skip `(...)` comments
      break;

    default: // TODO
      break;
    }
  }
  return tokens;
}

bool parse_num(const char *code, g_token_position *pos, g_token *token) {
  bool has_digits = false;
  bool has_dot = false;
  bool is_negative = false;
  f64 decimals = 10;

  u64 start_index = pos->index;

  if (current(code, pos) == '-') {
    is_negative = true;
    skip(code, pos);
  }

  while (pos->index < strlen(code)) {
    char current_char = current(code, pos);
    if (isdigit(current_char)) {
      has_digits = true;
      if (token->is_float) {
        token->data.fnum += (current_char - '0') / decimals;
        decimals *= 10;
      } else {
        token->data.num = token->data.num * 10 + (current_char - '0');
      }
      skip(code, pos);
    } else if (current_char == '.') {
      if (has_dot)
        return false; // TODO error handling

      token->is_float = true;
      has_dot = true;
      token->data.fnum = (f64)token->data.num;
      skip(code, pos);
    } else
      break;
  }

  if (is_negative) {
    if (token->is_float)
      token->data.fnum = -token->data.fnum;
    else
      token->data.num = -token->data.num;
  }

  return has_digits;
}

void skip(const char *code, g_token_position *pos) {
  char current = code[pos->index++];
  if (current == '\n') {
    pos->line++;
    pos->column = 1;
  } else
    pos->column++;
}

inline char next(const char *code, g_token_position *pos) {
  skip(code, pos);
  return code[pos->index];
}

inline char current(const char *code, g_token_position *pos) {
  return code[pos->index];
}

inline char peek(const char *code, g_token_position *pos) {
  return code[pos->index + 1];
}

inline char peek2(const char *code, g_token_position *pos) {
  return code[pos->index + 2];
}
