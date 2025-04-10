#include "lexer.hpp"

#include <ctype.h>
#include <string.h>

#define g_log_current_level g_log_info
#include "util.hpp"

static void skip(const char *code, g_token_position *pos);
static char next(const char *code, g_token_position *pos);
static char current(const char *code, g_token_position *pos);
static char peek(const char *code, g_token_position *pos);
static char peek2(const char *code, g_token_position *pos);

bool parse_num(const char *code, g_token_position *pos, g_token *token);
void skip_whitespace(const char *code, g_token_position *pos);

g_dynarr(g_token) g_lex(const char *code) {
  g_dynarr(g_token) tokens; // RESPONSIBILITY OF DEALLOCATION TO CALLEE
  g_dynarr_init(&tokens, sizeof(g_token));

  g_token_position pos = g_token_position(1, 1, 0);
  const int len = strlen(code);
  for (pos.index = 0; pos.index < len; skip(code, &pos)) {
    char current_char;
    g_token token = g_token();

    skip_whitespace(code, &pos);

    current_char = current(code, &pos);

    // handle numbers FIRST, I don't want to write 12 cases for this
    if (isdigit(current_char) || current_char == '-' || current_char == '.') {
      bool success = parse_num(code, &pos, &token); // TODO, error handling
      token.type = g_token_number;
      g_dynarr_push(&tokens, &token);
    }

    skip_whitespace(code, &pos);

    current_char = current(code, &pos);

    switch (current_char) {
    case '\n':
      token.type = g_token_newline;
      g_dynarr_push(&tokens, &token);
      break;

    case 'i': // can either be `if` or `i` (`i` being TODO)
      if (strncmp(code + pos.index, "if", 2) == 0 &&
          !isalnum(code[pos.index + 2])) {
        skip(code, &pos);
        token.type = g_token_if;
        g_dynarr_push(&tokens, &token);
        break;
      }

    case 't': // this can also be tool select word
      if (strncmp(code + pos.index, "then", 4) == 0 &&
          !isalnum(code[pos.index + 4])) {
        for (int i = 0; i < 3; i++)
          skip(code, &pos);
        token.type = g_token_then;
        g_dynarr_push(&tokens, &token);
        break;
      }

    case 'f':
    case 'g':
    case 'x':
    case 'y':
    case 'z':
      token.type = (g_token_type)current_char;
      g_dynarr_push(&tokens, &token);
      break;

    case 'e': // NOTE: there's no word for e
      if (strncmp(code + pos.index, "end", 3) == 0 &&
          !isalnum(code[pos.index + 3])) {
        skip(code, &pos);
        skip(code, &pos);
        token.type = g_token_end;
        g_dynarr_push(&tokens, &token);
      }
      if (strncmp(code + pos.index, "else", 4) == 0 &&
          !isalnum(code[pos.index + 4])) {
        for (int i = 0; i < 3; i++)
          skip(code, &pos);
        token.type = g_token_else;
        g_dynarr_push(&tokens, &token);
      }
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
  switch (token.type) {
  case g_token_newline:
    g_log(g_log_info, "Token - Newline\n");
    break;
  case g_token_symbol:
    g_log(g_log_info, "Token - Symbol: `%c`\n", token.data.symbol);
    break;
  case g_token_number:
    if (token.is_float)
      g_log(g_log_info, "Token - Number: %lf\n", token.data.fnum);
    else
      g_log(g_log_info, "Token - Number: %ld\n", token.data.num);
    break;

  case g_token_if:
    g_log(g_log_info, "Token - if\n");
    break;
  case g_token_else:
    g_log(g_log_info, "Token - else\n");
    break;
  case g_token_then:
    g_log(g_log_info, "Token - then\n");
    break;
  case g_token_end:
    g_log(g_log_info, "Token - end\n");
    break;

  case 'f':
  case 'x':
  case 'y':
  case 'z':
  case 'g':
    g_log(g_log_info, "Token - Word: %c\n", token.type);
    break;
  default:
    break;
  }
}

static void skip(const char *code, g_token_position *pos) {
  char current = code[pos->index++];
  if (current == '\n') {
    pos->line++;
    pos->column = 1;
  } else
    pos->column++;
}

static inline char next(const char *code, g_token_position *pos) {
  skip(code, pos);
  return code[pos->index];
}

static inline char current(const char *code, g_token_position *pos) {
  return code[pos->index];
}

static inline char peek(const char *code, g_token_position *pos) {
  return code[pos->index + 1];
}

static inline char peek2(const char *code, g_token_position *pos) {
  return code[pos->index + 2];
}

inline void skip_whitespace(const char *code, g_token_position *pos) {
  while (current(code, pos) != '\n' && isspace(current(code, pos)))
    skip(code, pos);
}
