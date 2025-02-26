#include "parser.h"

#include "ctype.h"

#include "lexer.h"
#include "util.h"

typedef u64 token_pointer;

// this is to be extended later
typedef struct g_expression {
  union {
    i64 num;
    f64 fnum;
  } data;
  bool is_float;
} g_expression;

typedef struct g_word {
  char letter;
  g_expression expression;
} g_word;

typedef struct g_block {
  g_dynarr(g_word) words;
  enum g_block_type {
    g_block_command_block,
    // TODO: if block, for block, etc.
  } type;
} g_block;

static g_token current(g_parser *parser);
static void skip(g_parser *parser);
static g_token peek(g_parser *parser);
static g_token peek2(g_parser *parser);
static g_token next(g_parser *parser);

g_expression parse_expression(g_parser *parser) {
  g_token current_token = current(parser);

  if (current_token.type != g_token_number) {
    return (g_expression){}; // TODO, error handling
  }

  return (g_expression){
      .is_float = current_token.is_float,
      .data.num = current_token.data.num, // adjusts for fnum
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

  // TODO, analyze modal group, etc.

  return (g_word){
      .expression = expression,
      .letter = current_token.type,
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
  // skip(parser);

  return (g_block){
      .type = g_block_command_block, // TODO other block types
      .words = words,
  };
}

g_block parse_block(g_parser *parser) { return parse_command_block(parser); }

void g_parser_init(g_parser *parser, g_token_stream tokens) {
  parser->token_pointer = 0;
  parser->current_modal_group = -1;
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

void print_block(g_block block, int *indent) {
  switch (block.type) {
  case g_block_command_block:
    g_log(g_log_info, "%*s(block\n", *indent, " ");
    *indent += 2;
    for (int i = 0; i < block.words.len; i++) {
      g_word *word = (g_word *)g_dynarr_get(&block.words, i);
      print_word(word, indent);
    }
    *indent -= 2;
    g_log(g_log_info, "%*s)\n", *indent, " ");
    break;
  default:
    g_log(g_log_info, "Unknown block type!\n");
    break;
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
