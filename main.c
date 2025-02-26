#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"
#include "util.h"

#define max_input_len 256

int main(int argc, char **argv) {
  char input[max_input_len];

  printf("rs274 (g-code) JIT interpreter\n"
         "TODO, everything!\n"
         "Run `exit` to exit.\n");

  if (argc > 1) {
    const char *src = argv[1];

    char *input = read_file(src);
    if (!input) {
      // TODO, better error handling
      fprintf(stderr, "Erorr reading file at %s!", src);
      return 1;
    }

    g_dynarr(g_token) tokens;
    tokens = g_lex(input);
    for (int i = 0; i < tokens.len; i++) {
      g_token token = *(g_token *)g_dynarr_get(&tokens, i);
      print_token(token);
    }
    g_parser parser;
    g_parser_init(&parser, tokens);
    g_parse_tree tree = g_parse(&parser);
    g_print_parse_tree(tree);
    g_parse_tree_free(tree);
    g_dynarr_free(&tokens);

    free(input);

    return 0;
  }

  // ...else REPL

  while (1) {
    printf("> ");
    if (fgets(input, sizeof(input), stdin) == NULL)
      break;

    if (strncmp(input, "exit", 4) == 0)
      break;

    g_dynarr(g_token) tokens;
    tokens = g_lex(input);
    for (int i = 0; i < tokens.len; i++) {
      g_token token = *(g_token *)g_dynarr_get(&tokens, i);
      print_token(token);
    }
    g_parser parser;
    g_parser_init(&parser, tokens);
    g_parse_tree tree = g_parse(&parser);
    g_print_parse_tree(tree);
    g_parse_tree_free(tree);
    g_dynarr_free(&tokens);
  }

  return 0;
}
