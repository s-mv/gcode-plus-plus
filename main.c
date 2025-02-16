#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "util.h"

#define max_input_len 256

int main() {
  char input[max_input_len];

  printf("r247 (g-code) JIT interpreter\n"
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
    printf("Number of tokens: %lu\n", tokens.len);
    g_dynarr_free(&tokens);
  }

  return 0;
}
