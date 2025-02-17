#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "util.h"

#define max_input_len 256

int main() {
  char input[max_input_len];

  printf("r274 (g-code) JIT interpreter\n"
         "TODO, everything!\n"
         "Run `exit` to exit.\n");

  // TODO: optional REPL, allow file upload
  while (1) {
    printf("> ");
    if (fgets(input, sizeof(input), stdin) == NULL)
      break;

    if (strncmp(input, "exit", 4) == 0)
      break;

    g_dynarr(g_token) tokens;
    tokens = lex(input);
    for (int i = 0; i < tokens.len; i++) {
      g_token token = *(g_token *)g_dynarr_get(&tokens, i);
      printf("Token:\n");
      printf("  Token word: %c\n", token.word_type);
      if (token.is_float)
        printf("  Token magnitude: %lf\n", token.data.fnum);
      else
        printf("  Token magnitude: %li\n", token.data.num);
    }
    g_dynarr_free(&tokens);
  }

  return 0;
}
