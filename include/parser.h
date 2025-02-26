#ifndef smv_gcodepp_parser_h
#define smv_gcodepp_parser_h

// #include "lexer.h"
#include "util.h"

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
 * block         -> command_block ; // | if_block | for_block (TODO);
 * command_block -> word* '\n' ;
 * word          -> LETTER expression ;
 *
 * (expressions are parsed separately)
 */

typedef g_dynarr(g_token) g_token_stream;

struct g_block;

typedef struct g_parse_tree {
  g_dynarr(struct g_block) blocks;
} g_parse_tree;

// unlike the lexer, the parser must hold more information
// so we need a proper data structure for it
// this will probably have even more information soon
typedef struct g_parser {
  g_token_stream tokens;
  u64 token_pointer;
  i8 current_modal_group;
} g_parser;

void g_parser_init(g_parser *parser, g_token_stream tokens);
g_parse_tree g_parse(g_parser *parser);
void g_parse_tree_free(g_parse_tree tree);

void g_print_parse_tree(g_parse_tree tree);

#endif