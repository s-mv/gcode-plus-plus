#ifndef smv_gcodepp_frontend_hpp
#define smv_gcodepp_frontend_hpp

#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include "Parser.h"
#include "antlr4-runtime.h"
#include "tree/Trees.h"

#include "lexer_antlr4.h"
#include "parser_antlr4.h"

std::unique_ptr<parser_antlr4> g_frontend_parse(const std::string &code);
void g_print_tree(const std::unique_ptr<parser_antlr4>& parser);

#endif
