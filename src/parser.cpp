#include "parser.hpp"

#include <cstring>
#include <ctype.h>

#include "lexer.hpp"
#include "util.hpp"

typedef u64 token_pointer;

// helper array for modal groups of g-codes
// possible TODO: organize/refactor this more properly
// here, -1 is like the '\0' in strings
const f64 *g_modal_groups[16] = {
    (const f64[]){4, 10, 28, 30, 52, 53, 92, 92.1, 92.2, 92.3, -1},
    (const f64[]){0, 1, 2, 3, 33, 38, 73, 76, 80, 81, 82, 83, 84, 85, 86, 87,
                  88, 89, -1},
    (const f64[]){17, 18, 19, 17.1, 18.1, 19.1, -1},
    (const f64[]){90, 91, -1},
    (const f64[]){90.1, 91.1, -1},
    (const f64[]){93, 94, 95, -1},
    (const f64[]){20, 21, -1},
    (const f64[]){40, 41, 42, 41.1, 42.1, -1},
    (const f64[]){43, 43.1, 49, -1},

    (const f64[]){-1},

    (const f64[]){98, 99, -1},

    (const f64[]){-1},

    (const f64[]){54, 55, 56, 57, 58, 59, 59.1, 59.2, 59.3, -1},
    (const f64[]){61, 61.1, 64, -1},
    (const f64[]){96, 97, -1},
    (const f64[]){7, 8, -1},
};

static g_token current(g_parser *parser);
static void skip(g_parser *parser);
static g_token peek(g_parser *parser);
static g_token peek2(g_parser *parser);
static g_token next(g_parser *parser);

// help with "semantic" analysis
int get_modal_group_g(f64 number);

g_block parse_block(g_parser *parser);

g_expression parse_expression(g_parser *parser) {
  g_token current_token = current(parser);

  if (current_token.type == g_token_symbol &&
      current_token.data.symbol == '[') {
    // TODO...
  }

  if (current_token.type != g_token_number) {
    return (g_expression){}; // TODO, error handling
  }

  return (g_expression){
      .data = {.num = current_token.data.num}, // adjusts for fnum
      .is_float = current_token.is_float,
  };
}

g_word parse_word(g_parser *parser) {
  g_token current_token = current(parser);
  if (!isalpha(current_token.type)) {
    return (g_word){
        .letter = 'e', // TODO, error handling
    };
  }

  skip(parser);

  g_expression expression = parse_expression(parser);

  return {
      .letter = (char)current_token.type,
      .expression = expression,
  };
}

g_block parse_command_block(g_parser *parser) {
  g_dynarr(g_word) words;
  g_dynarr_init(&words, sizeof(g_word));
  while (current(parser).type != g_token_newline) {
    g_word word = parse_word(parser);
    g_dynarr_push(&words, &word);
    skip(parser);
  }

  /* validate command block */
  // 1. check modal groups of the words
  bool encountered_modal_groups[g_modal_groups_num];
  memset(encountered_modal_groups, false, g_modal_groups_num);
  for (int i = 0; i < words.len; i++) {
    g_word word = *(g_word *)g_dynarr_get(&words, i);
    if ((char)word.letter == 'g') {
      g_expression expr = word.expression;
      f64 number = expr.is_float ? expr.data.fnum : (f64)expr.data.num;
      int group = get_modal_group_g(number);
      if (group == -1)
        continue;
      if (encountered_modal_groups[group]) {
        g_log(g_log_error,
              "Multiple g-codes of the same modal group (%d) used in the same "
              "command block!\n",
              group);
        // TODO proper error handling
        continue;
      }
      encountered_modal_groups[group] = true;
    }
  }

  return (g_block){
      .words = words,
      .type = g_block::command_block, // TODO other block types
  };
}

g_block parse_if_block(g_parser *parser) {
  g_block block = {0};
  block.type = g_block::if_block;

  skip(parser); // skip `if`

  block.expression = parse_expression(parser);
  skip(parser);

  if (current(parser).type != g_token_then &&
      peek(parser).type != g_token_newline) {
    // TODO, bettererror handling
    g_log(g_log_error, "Expected `then` keyword followed by newline!\n");
    return block;
  }

  skip(parser); // skip `then`
  skip(parser); // skip newline token

  g_dynarr_init(&block.then_blocks, sizeof(g_block));
  while (current(parser).type != g_token_else &&
         current(parser).type != g_token_end) {
    g_block new_block = parse_block(parser);
    g_dynarr_push(&block.then_blocks, &new_block);
    skip(parser);
  }

  if (current(parser).type == g_token_else) {
    skip(parser); // skip `else`

    g_dynarr_init(&block.else_blocks, sizeof(g_block));
    while (current(parser).type != g_token_end) {
      g_block new_block = parse_block(parser);
      g_dynarr_push(&block.else_blocks, &new_block);
      skip(parser);
    }
  }

  if (current(parser).type != g_token_end) {
    g_log(g_log_error,
          "Expected 'end' keyword!\n"); // TODO, better error handling
    return block;
  }

  skip(parser); // skip `end`

  return block;
}

g_block parse_block(g_parser *parser) {
  if (current(parser).type == g_token_if)
    return parse_if_block(parser);
  return parse_command_block(parser);
}

void g_parser_init(g_parser *parser, g_token_stream tokens) {
  parser->token_pointer = 0;
  parser->tokens = tokens;
}

g_parse_tree g_parse(g_parser *parser) {
  g_parse_tree tree;
  g_dynarr_init(&tree.blocks, sizeof(g_block));
  while (parser->token_pointer < parser->tokens.len) {
    g_block block = parse_block(parser);
    g_dynarr_push(&tree.blocks, &block);
    skip(parser);
  }
  return tree;
}

void g_parse_tree_free(g_parse_tree tree) {
  for (int i = 0; i < tree.blocks.len; i++) {
    g_block block = *(g_block *)g_dynarr_get(&tree.blocks, i);
    if (block.type == g_block::command_block)
      g_dynarr_free(&block.words);
  }
  g_dynarr_free(&tree.blocks);
}

inline g_token current(g_parser *parser) {
  return *(g_token *)g_dynarr_get(&parser->tokens, parser->token_pointer);
}

inline void skip(g_parser *parser) { parser->token_pointer++; }

inline g_token peek(g_parser *parser) {
  return *(g_token *)g_dynarr_get(&parser->tokens, parser->token_pointer + 1);
}

inline g_token peek2(g_parser *parser) {
  return *(g_token *)g_dynarr_get(&parser->tokens, parser->token_pointer + 2);
}

inline g_token next(g_parser *parser) {
  return *(g_token *)g_dynarr_get(&parser->tokens, ++parser->token_pointer);
}

/***  functions that help with "semantic" analysis ***/
int get_modal_group_g(f64 number) {
  for (int i = 0; i < g_modal_groups_num; i++) {
    for (int j = 0; g_modal_groups[i][j] != -1; j++) {
      if (number == g_modal_groups[i][j])
        return i;
    }
  }
  return -1;
}

/*** helper functions for printing the parse tree ***/

void print_expression(g_expression *expr, int *indent) {
  if (expr->is_float)
    g_log(g_log_info, "%*s(float %f)\n", *indent, "", expr->data.fnum);
  else
    g_log(g_log_info, "%*s(int %ld)\n", *indent, "", expr->data.num);
}

void print_word(g_word *word, int *indent) {
  g_log(g_log_info, "%*s(word\n", *indent, "");
  g_log(g_log_info, "%*s  (type %c)\n", *indent, "", word->letter);
  *indent += 2;
  print_expression(&word->expression, indent);
  *indent -= 2;
  g_log(g_log_info, "%*s)\n", *indent, " ");
}

void print_blocks(g_dynarr blocks, int *indent);

void print_block(g_block block, int *indent) {
  switch (block.type) {
  case g_block::command_block:
    g_log(g_log_info, "%*s(block\n", *indent, " ");
    *indent += 2;
    for (int i = 0; i < block.words.len; i++) {
      g_word *word = (g_word *)g_dynarr_get(&block.words, i);
      print_word(word, indent);
    }
    *indent -= 2;
    g_log(g_log_info, "%*s)\n", *indent, " ");
    break;
  case g_block::if_block:
    g_log(g_log_info, "%*s(if-block\n", *indent, " ");
    *indent += 2;

    g_log(g_log_info, "%*s(condition\n", *indent, " ");
    *indent += 2;
    print_expression(&block.expression, indent);
    *indent -= 2;
    g_log(g_log_info, "%*s)\n", *indent, " ");

    if (block.then_blocks.len > 0) {
      g_log(g_log_info, "%*s(then\n", *indent, " ");
      *indent += 2;
      print_blocks(block.then_blocks, indent);
      *indent -= 2;
      g_log(g_log_info, "%*s)\n", *indent, " ");
    }

    if (block.else_blocks.len > 0) {
      g_log(g_log_info, "%*s(else\n", *indent, " ");
      *indent += 2;
      print_blocks(block.else_blocks, indent);
      *indent -= 2;
      g_log(g_log_info, "%*s)\n", *indent, " ");
    }

    *indent -= 2;
    g_log(g_log_info, "%*s)\n", *indent, " ");
    break;

  default:
    g_log(g_log_info, "Unknown block type!\n");
    break;
  }
}

void print_blocks(g_dynarr blocks, int *indent) {
  for (int i = 0; i < blocks.len; i++) {
    g_block *inner_block = (g_block *)g_dynarr_get(&blocks, i);
    print_block(*inner_block, indent);
  }
}

void g_print_parse_tree(g_parse_tree tree) {
  int indent = 2;
  g_log(g_log_info, "Parse tree:\n");
  g_log(g_log_info, "(\n");
  for (int i = 0; i < tree.blocks.len; i++) {
    g_block block = *(g_block *)g_dynarr_get(&tree.blocks, i);
    print_block(block, &indent);
  }
  g_log(g_log_info, ")\n");
}
