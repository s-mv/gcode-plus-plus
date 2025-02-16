#include "lexer.h"
#include "util.h"
#include <string.h>

g_dynarr(g_token) lex(const char *code) {
  g_dynarr(g_token) tokens; // RESPONSIBILITY OF DEALLOCATION TO CALLEE
  g_dynarr_init(&tokens, sizeof(g_token));

  int index = 0;
  const int len = strlen(code);
  for (index = 0; index < len; index++) {
    char current = code[index];
    switch (current) {
    case 'g':
      // TODO
      g_token token = {
          .word_type = g_word_g,
          .position = {},
          .data.num = 0,
      };
      g_dynarr_push(&tokens, &token);
      break;
    case 'x':
    case 'y':
    case 'z':
      // TODO
      break;
    }
  }
  return tokens;
}