#ifndef smv_gcodepp_parser_hpp
#define smv_gcodepp_parser_hpp

// #include "lexer.hpp"
#include "util.hpp"

/* DISCLAIMER
 *
 * G-Code doesn't really NEED a parser.
 * However, for the sake of abstraction and readability, the parser is a
 * separate component. My initial plan was making a single, monolithic parser
 * that also generates the lexemes, in a single phase instead of two. But we can
 * always just do that later if optimization is needed.
 *
 */

/* ROUGH GRAMMAR
 * TODO: Proper documentation, but for now this comment would suffice.
 *
 * program       -> block* ;
 * block         -> command_block | if_block ; // | for_block (TODO);
 * command_block -> word* '\n' ;
 * if_block      -> `if` expression `then` block `end` ;
 * if_block      -> `if` expression `then` block `else` block `end` ;
 * word          -> LETTER expression ;
 *
 * (expressions are parsed separately)
 */

typedef g_dynarr(g_token) g_token_stream;

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

typedef struct g_block g_block;
struct g_block {
  union {
    struct {
      g_expression expression;
      g_dynarr(g_block) then_blocks;
      g_dynarr(g_block) else_blocks;
    };
    g_dynarr(g_word) words;
  };

  enum g_block_type {
    command_block,
    if_block,
    else_block,
    // TODO: for block
  } type;
};

typedef struct g_parse_tree {
  g_dynarr(struct g_block) blocks;
} g_parse_tree;

// unlike the lexer, the parser must hold more information
// so we need a proper data structure for it
// this will probably have even more information soon
typedef struct g_parser {
  g_token_stream tokens;
  u64 token_pointer;
  i8 current_modal_groups[];
} g_parser;

#define g_modal_groups_num 16

void g_parser_init(g_parser *parser, g_token_stream tokens);
g_parse_tree g_parse(g_parser *parser);
void g_parse_tree_free(g_parse_tree tree);

void g_print_parse_tree(g_parse_tree tree);

#endif