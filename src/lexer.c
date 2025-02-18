#include "lexer.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "util.h"

void skip(const char *code, g_token_position *pos);
char next(const char *code, g_token_position *pos);
char current(const char *code, g_token_position *pos);
char peek(const char *code, g_token_position *pos);
char peek2(const char *code, g_token_position *pos);

bool parse_num(const char *code, g_token_position *pos, g_token *token);
void skip_whitespace(const char *code, g_token_position *pos);

g_dynarr(g_token) lex(const char *code) {
  g_dynarr(g_token) tokens; // RESPONSIBILITY OF DEALLOCATION TO CALLEE
  g_dynarr_init(&tokens, sizeof(g_token));

  g_token_position pos = {.index = 0, .line = 1, .column = 1};
  const int len = strlen(code);
  for (pos.index = 0; pos.index < len; pos.index++) {
    char current_char = current(code, &pos);
    g_token token = {0};

    skip_whitespace(code, &pos);

    // handle numbers FIRST, I don't want to write 12 cases for this
    if (isdigit(current_char) || current_char == '-' || current_char == '.') {
      bool success = parse_num(code, &pos, &token); // TODO, error handling
      token.type = g_token_number;
      g_dynarr_push(&tokens, &token);
    }

    skip_whitespace(code, &pos);

    switch (current_char) {
    case 'g':
    case 'x':
    case 'y':
    case 'z':
      token.type = current_char;
      skip(code, &pos);
      if (!parse_num(code, &pos, &token))
        ; // TODO, error (some kind of panic mode)

      g_dynarr_push(&tokens, &token);
      break;

    /* expression parsing... ahem, lexing */
    case '[':
    case ']':
    case '*':
    case '+':
    case '-':
      token.type = g_token_symbol;
      token.data.symbol = current_char;
      token.position = pos;
      g_dynarr_push(&tokens, &token);
      break;

    case '/':
      if (pos.column != 1) {
        token.type = g_token_symbol;
        token.data.symbol = current_char;
        g_dynarr_push(&tokens, &token);
        break;
      }
      // otherwise continue with ';' case
    case ';':
      while (current(code, &pos) != '\n' && current(code, &pos) != '\0') {
        skip(code, &pos);
      }
      // TODO (?), add the comment as a token too
      break;

    case '(':
      while (next(code, &pos) != ')')
        ;
      skip(code, &pos);
      // major TODO, logging and debug functionality
      // TODO (?), if it's a comment, add it as a token too
      break;

    default: // TODO, error handling
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

  // TODO, hate this dirty fix, make it more elegant
  pos->index--;
  pos->column--;

  if (is_negative) {
    if (token->is_float)
      token->data.fnum = -token->data.fnum;
    else
      token->data.num = -token->data.num;
  }

  return has_digits;
}

void print_token(g_token token) {
  printf("Token:\n");
  switch (token.type) {
  case g_token_symbol:
    printf("  Symbol: `%c`\n", token.data.symbol);
    break;
  case g_token_number:
    if (token.is_float)
      printf("  Number: %lf\n", token.data.fnum);
    else
      printf("  Number: %ld\n", token.data.num);
    break;

  default:
    if (token.is_float)
      printf("       Word: %c\n"
             "  Magnitude: %lf\n",
             token.type, token.data.fnum);
    else
      printf("       Word: %c\n"
             "  Magnitude: %ld\n",
             token.type, token.data.num);
    break;
  }
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

inline void skip_whitespace(const char *code, g_token_position *pos) {
  while (isspace(current(code, pos)))
    skip(code, pos);
}
