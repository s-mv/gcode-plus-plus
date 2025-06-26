
// Generated from parser_antlr4.g4 by ANTLR 4.13.2


#include "parser_antlr4Listener.h"
#include "parser_antlr4Visitor.h"

#include "parser_antlr4.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Parser_antlr4StaticData final {
  Parser_antlr4StaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Parser_antlr4StaticData(const Parser_antlr4StaticData&) = delete;
  Parser_antlr4StaticData(Parser_antlr4StaticData&&) = delete;
  Parser_antlr4StaticData& operator=(const Parser_antlr4StaticData&) = delete;
  Parser_antlr4StaticData& operator=(Parser_antlr4StaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag parser_antlr4ParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Parser_antlr4StaticData> parser_antlr4ParserStaticData = nullptr;

void parser_antlr4ParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (parser_antlr4ParserStaticData != nullptr) {
    return;
  }
#else
  assert(parser_antlr4ParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Parser_antlr4StaticData>(
    std::vector<std::string>{
      "block", "statement", "subroutine", "m99", "line", "if_statement", 
      "while_statement", "do_while_statement", "for_statement", "break_statement", 
      "continue_statement", "block_delete", "line_number", "segment", "mid_line_word", 
      "mid_line_letter", "real_value", "real_number", "expression", "logical_or_expression", 
      "logical_xor_expression", "logical_and_expression", "equality_expression", 
      "relational_expression", "additive_expression", "multiplicative_expression", 
      "power_expression", "unary_expression", "primary", "unary_combo", 
      "ordinary_unary_combo", "ordinary_unary_operation", "arc_tangent_combo", 
      "parameter_setting", "parameter_value", "comment"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "'$'", "'+'", "'-'", "'.'", "'['", "']'", "'**'", "'/'", "", 
      "'*'", "", "", "", "", "", "'<'", "'<='", "'>'", "'>='", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "'#'", "'='"
    },
    std::vector<std::string>{
      "", "IF", "THEN", "DO", "WHILE", "FOR", "FROM", "TO", "ELSE", "END", 
      "ENDIF", "ENDWHILE", "ENDFOR", "BREAK", "CONTINUE", "SUBROUTINE", 
      "M99", "DIGIT", "LETTER", "DOLLAR", "PLUS", "MINUS", "DOT", "LEFT_BRACKET", 
      "RIGHT_BRACKET", "POWER", "SLASH", "MODULO", "TIMES", "LOGICAL_AND", 
      "EXCLUSIVE_OR", "NON_EXCLUSIVE_OR", "EQ", "NE", "LT", "LE", "GT", 
      "GE", "ABSOLUTE_VALUE", "ARC_COSINE", "ARC_SINE", "COSINE", "E_RAISED_TO", 
      "FIX_DOWN", "FIX_UP", "NATURAL_LOG_OF", "ROUND_OPERATION", "SINE", 
      "SQUARE_ROOT", "TANGENT", "ARC_TANGENT", "PARAMETER_SIGN", "EQUAL_SIGN", 
      "COMMENT", "NAMED_PARAMETER", "EOL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,56,376,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,1,0,5,0,74,8,0,10,0,12,0,77,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,
  	1,87,8,1,1,2,1,2,1,2,5,2,92,8,2,10,2,12,2,95,9,2,1,2,1,2,1,2,1,3,1,3,
  	1,4,3,4,103,8,4,1,4,3,4,106,8,4,1,4,5,4,109,8,4,10,4,12,4,112,9,4,1,4,
  	4,4,115,8,4,11,4,12,4,116,1,5,1,5,1,5,5,5,122,8,5,10,5,12,5,125,9,5,1,
  	5,1,5,1,5,1,5,1,5,5,5,132,8,5,10,5,12,5,135,9,5,1,5,1,5,5,5,139,8,5,10,
  	5,12,5,142,9,5,1,5,1,5,1,5,3,5,147,8,5,1,5,1,5,1,6,1,6,1,6,5,6,154,8,
  	6,10,6,12,6,157,9,6,1,6,1,6,1,6,1,7,1,7,5,7,164,8,7,10,7,12,7,167,9,7,
  	1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,181,8,8,10,8,12,8,
  	184,9,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,4,12,196,8,12,11,
  	12,12,12,197,1,13,1,13,1,13,1,13,3,13,204,8,13,1,14,1,14,1,14,1,15,1,
  	15,1,16,1,16,1,16,1,16,3,16,215,8,16,1,17,3,17,218,8,17,1,17,4,17,221,
  	8,17,11,17,12,17,222,1,17,1,17,5,17,227,8,17,10,17,12,17,230,9,17,3,17,
  	232,8,17,1,17,3,17,235,8,17,1,17,1,17,4,17,239,8,17,11,17,12,17,240,3,
  	17,243,8,17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,5,19,253,8,19,10,
  	19,12,19,256,9,19,1,20,1,20,1,20,1,20,1,20,1,20,5,20,264,8,20,10,20,12,
  	20,267,9,20,1,21,1,21,1,21,1,21,1,21,1,21,5,21,275,8,21,10,21,12,21,278,
  	9,21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,286,8,22,10,22,12,22,289,9,22,
  	1,23,1,23,1,23,1,23,1,23,1,23,5,23,297,8,23,10,23,12,23,300,9,23,1,24,
  	1,24,1,24,1,24,1,24,1,24,5,24,308,8,24,10,24,12,24,311,9,24,1,25,1,25,
  	1,25,1,25,1,25,1,25,5,25,319,8,25,10,25,12,25,322,9,25,1,26,1,26,1,26,
  	1,26,1,26,3,26,329,8,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,337,8,27,1,
  	28,1,28,1,28,1,28,1,28,1,28,3,28,345,8,28,1,29,1,29,3,29,349,8,29,1,30,
  	1,30,1,30,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,3,33,364,
  	8,33,1,33,1,33,1,33,1,34,1,34,1,34,3,34,372,8,34,1,35,1,35,1,35,0,7,38,
  	40,42,44,46,48,50,36,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,0,9,1,0,9,10,2,
  	0,9,9,11,11,2,0,9,9,12,12,1,0,18,19,1,0,20,21,1,0,32,33,1,0,34,37,1,0,
  	26,28,1,0,38,49,389,0,75,1,0,0,0,2,86,1,0,0,0,4,88,1,0,0,0,6,99,1,0,0,
  	0,8,102,1,0,0,0,10,118,1,0,0,0,12,150,1,0,0,0,14,161,1,0,0,0,16,172,1,
  	0,0,0,18,188,1,0,0,0,20,190,1,0,0,0,22,192,1,0,0,0,24,195,1,0,0,0,26,
  	203,1,0,0,0,28,205,1,0,0,0,30,208,1,0,0,0,32,214,1,0,0,0,34,242,1,0,0,
  	0,36,244,1,0,0,0,38,246,1,0,0,0,40,257,1,0,0,0,42,268,1,0,0,0,44,279,
  	1,0,0,0,46,290,1,0,0,0,48,301,1,0,0,0,50,312,1,0,0,0,52,328,1,0,0,0,54,
  	336,1,0,0,0,56,344,1,0,0,0,58,348,1,0,0,0,60,350,1,0,0,0,62,353,1,0,0,
  	0,64,355,1,0,0,0,66,363,1,0,0,0,68,371,1,0,0,0,70,373,1,0,0,0,72,74,3,
  	2,1,0,73,72,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,1,1,
  	0,0,0,77,75,1,0,0,0,78,87,3,8,4,0,79,87,3,10,5,0,80,87,3,12,6,0,81,87,
  	3,14,7,0,82,87,3,16,8,0,83,87,3,18,9,0,84,87,3,20,10,0,85,87,3,4,2,0,
  	86,78,1,0,0,0,86,79,1,0,0,0,86,80,1,0,0,0,86,81,1,0,0,0,86,82,1,0,0,0,
  	86,83,1,0,0,0,86,84,1,0,0,0,86,85,1,0,0,0,87,3,1,0,0,0,88,89,5,15,0,0,
  	89,93,3,32,16,0,90,92,5,55,0,0,91,90,1,0,0,0,92,95,1,0,0,0,93,91,1,0,
  	0,0,93,94,1,0,0,0,94,96,1,0,0,0,95,93,1,0,0,0,96,97,3,0,0,0,97,98,3,6,
  	3,0,98,5,1,0,0,0,99,100,5,16,0,0,100,7,1,0,0,0,101,103,3,22,11,0,102,
  	101,1,0,0,0,102,103,1,0,0,0,103,105,1,0,0,0,104,106,3,24,12,0,105,104,
  	1,0,0,0,105,106,1,0,0,0,106,110,1,0,0,0,107,109,3,26,13,0,108,107,1,0,
  	0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,114,1,0,0,0,112,
  	110,1,0,0,0,113,115,5,55,0,0,114,113,1,0,0,0,115,116,1,0,0,0,116,114,
  	1,0,0,0,116,117,1,0,0,0,117,9,1,0,0,0,118,119,5,1,0,0,119,123,3,36,18,
  	0,120,122,5,55,0,0,121,120,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,
  	124,1,0,0,0,124,126,1,0,0,0,125,123,1,0,0,0,126,140,3,0,0,0,127,128,5,
  	8,0,0,128,129,5,1,0,0,129,133,3,36,18,0,130,132,5,55,0,0,131,130,1,0,
  	0,0,132,135,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,136,1,0,0,0,135,
  	133,1,0,0,0,136,137,3,0,0,0,137,139,1,0,0,0,138,127,1,0,0,0,139,142,1,
  	0,0,0,140,138,1,0,0,0,140,141,1,0,0,0,141,146,1,0,0,0,142,140,1,0,0,0,
  	143,144,5,8,0,0,144,145,5,55,0,0,145,147,3,0,0,0,146,143,1,0,0,0,146,
  	147,1,0,0,0,147,148,1,0,0,0,148,149,7,0,0,0,149,11,1,0,0,0,150,151,5,
  	4,0,0,151,155,3,36,18,0,152,154,5,55,0,0,153,152,1,0,0,0,154,157,1,0,
  	0,0,155,153,1,0,0,0,155,156,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,0,158,
  	159,3,0,0,0,159,160,7,1,0,0,160,13,1,0,0,0,161,165,5,3,0,0,162,164,5,
  	55,0,0,163,162,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,
  	0,166,168,1,0,0,0,167,165,1,0,0,0,168,169,3,0,0,0,169,170,5,4,0,0,170,
  	171,3,36,18,0,171,15,1,0,0,0,172,173,5,5,0,0,173,174,3,68,34,0,174,175,
  	5,6,0,0,175,176,3,36,18,0,176,177,5,7,0,0,177,178,3,36,18,0,178,182,5,
  	3,0,0,179,181,5,55,0,0,180,179,1,0,0,0,181,184,1,0,0,0,182,180,1,0,0,
  	0,182,183,1,0,0,0,183,185,1,0,0,0,184,182,1,0,0,0,185,186,3,0,0,0,186,
  	187,7,2,0,0,187,17,1,0,0,0,188,189,5,13,0,0,189,19,1,0,0,0,190,191,5,
  	14,0,0,191,21,1,0,0,0,192,193,5,26,0,0,193,23,1,0,0,0,194,196,5,17,0,
  	0,195,194,1,0,0,0,196,197,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,
  	25,1,0,0,0,199,204,3,28,14,0,200,204,3,66,33,0,201,204,3,70,35,0,202,
  	204,3,6,3,0,203,199,1,0,0,0,203,200,1,0,0,0,203,201,1,0,0,0,203,202,1,
  	0,0,0,204,27,1,0,0,0,205,206,3,30,15,0,206,207,3,32,16,0,207,29,1,0,0,
  	0,208,209,7,3,0,0,209,31,1,0,0,0,210,215,3,58,29,0,211,215,3,68,34,0,
  	212,215,3,36,18,0,213,215,3,34,17,0,214,210,1,0,0,0,214,211,1,0,0,0,214,
  	212,1,0,0,0,214,213,1,0,0,0,215,33,1,0,0,0,216,218,7,4,0,0,217,216,1,
  	0,0,0,217,218,1,0,0,0,218,220,1,0,0,0,219,221,5,17,0,0,220,219,1,0,0,
  	0,221,222,1,0,0,0,222,220,1,0,0,0,222,223,1,0,0,0,223,231,1,0,0,0,224,
  	228,5,22,0,0,225,227,5,17,0,0,226,225,1,0,0,0,227,230,1,0,0,0,228,226,
  	1,0,0,0,228,229,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,231,224,1,0,0,
  	0,231,232,1,0,0,0,232,243,1,0,0,0,233,235,7,4,0,0,234,233,1,0,0,0,234,
  	235,1,0,0,0,235,236,1,0,0,0,236,238,5,22,0,0,237,239,5,17,0,0,238,237,
  	1,0,0,0,239,240,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,243,1,0,0,
  	0,242,217,1,0,0,0,242,234,1,0,0,0,243,35,1,0,0,0,244,245,3,38,19,0,245,
  	37,1,0,0,0,246,247,6,19,-1,0,247,248,3,40,20,0,248,254,1,0,0,0,249,250,
  	10,2,0,0,250,251,5,31,0,0,251,253,3,40,20,0,252,249,1,0,0,0,253,256,1,
  	0,0,0,254,252,1,0,0,0,254,255,1,0,0,0,255,39,1,0,0,0,256,254,1,0,0,0,
  	257,258,6,20,-1,0,258,259,3,42,21,0,259,265,1,0,0,0,260,261,10,2,0,0,
  	261,262,5,30,0,0,262,264,3,42,21,0,263,260,1,0,0,0,264,267,1,0,0,0,265,
  	263,1,0,0,0,265,266,1,0,0,0,266,41,1,0,0,0,267,265,1,0,0,0,268,269,6,
  	21,-1,0,269,270,3,44,22,0,270,276,1,0,0,0,271,272,10,2,0,0,272,273,5,
  	29,0,0,273,275,3,44,22,0,274,271,1,0,0,0,275,278,1,0,0,0,276,274,1,0,
  	0,0,276,277,1,0,0,0,277,43,1,0,0,0,278,276,1,0,0,0,279,280,6,22,-1,0,
  	280,281,3,46,23,0,281,287,1,0,0,0,282,283,10,2,0,0,283,284,7,5,0,0,284,
  	286,3,46,23,0,285,282,1,0,0,0,286,289,1,0,0,0,287,285,1,0,0,0,287,288,
  	1,0,0,0,288,45,1,0,0,0,289,287,1,0,0,0,290,291,6,23,-1,0,291,292,3,48,
  	24,0,292,298,1,0,0,0,293,294,10,2,0,0,294,295,7,6,0,0,295,297,3,48,24,
  	0,296,293,1,0,0,0,297,300,1,0,0,0,298,296,1,0,0,0,298,299,1,0,0,0,299,
  	47,1,0,0,0,300,298,1,0,0,0,301,302,6,24,-1,0,302,303,3,50,25,0,303,309,
  	1,0,0,0,304,305,10,2,0,0,305,306,7,4,0,0,306,308,3,50,25,0,307,304,1,
  	0,0,0,308,311,1,0,0,0,309,307,1,0,0,0,309,310,1,0,0,0,310,49,1,0,0,0,
  	311,309,1,0,0,0,312,313,6,25,-1,0,313,314,3,52,26,0,314,320,1,0,0,0,315,
  	316,10,2,0,0,316,317,7,7,0,0,317,319,3,52,26,0,318,315,1,0,0,0,319,322,
  	1,0,0,0,320,318,1,0,0,0,320,321,1,0,0,0,321,51,1,0,0,0,322,320,1,0,0,
  	0,323,324,3,54,27,0,324,325,5,25,0,0,325,326,3,52,26,0,326,329,1,0,0,
  	0,327,329,3,54,27,0,328,323,1,0,0,0,328,327,1,0,0,0,329,53,1,0,0,0,330,
  	331,5,20,0,0,331,337,3,54,27,0,332,333,5,21,0,0,333,337,3,54,27,0,334,
  	337,3,58,29,0,335,337,3,56,28,0,336,330,1,0,0,0,336,332,1,0,0,0,336,334,
  	1,0,0,0,336,335,1,0,0,0,337,55,1,0,0,0,338,345,3,34,17,0,339,345,3,68,
  	34,0,340,341,5,23,0,0,341,342,3,36,18,0,342,343,5,24,0,0,343,345,1,0,
  	0,0,344,338,1,0,0,0,344,339,1,0,0,0,344,340,1,0,0,0,345,57,1,0,0,0,346,
  	349,3,60,30,0,347,349,3,64,32,0,348,346,1,0,0,0,348,347,1,0,0,0,349,59,
  	1,0,0,0,350,351,3,62,31,0,351,352,3,36,18,0,352,61,1,0,0,0,353,354,7,
  	8,0,0,354,63,1,0,0,0,355,356,5,50,0,0,356,357,3,36,18,0,357,358,5,26,
  	0,0,358,359,3,36,18,0,359,65,1,0,0,0,360,361,5,51,0,0,361,364,3,56,28,
  	0,362,364,5,54,0,0,363,360,1,0,0,0,363,362,1,0,0,0,364,365,1,0,0,0,365,
  	366,5,52,0,0,366,367,3,32,16,0,367,67,1,0,0,0,368,369,5,51,0,0,369,372,
  	3,56,28,0,370,372,5,54,0,0,371,368,1,0,0,0,371,370,1,0,0,0,372,69,1,0,
  	0,0,373,374,5,53,0,0,374,71,1,0,0,0,37,75,86,93,102,105,110,116,123,133,
  	140,146,155,165,182,197,203,214,217,222,228,231,234,240,242,254,265,276,
  	287,298,309,320,328,336,344,348,363,371
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  parser_antlr4ParserStaticData = std::move(staticData);
}

}

parser_antlr4::parser_antlr4(TokenStream *input) : parser_antlr4(input, antlr4::atn::ParserATNSimulatorOptions()) {}

parser_antlr4::parser_antlr4(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  parser_antlr4::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *parser_antlr4ParserStaticData->atn, parser_antlr4ParserStaticData->decisionToDFA, parser_antlr4ParserStaticData->sharedContextCache, options);
}

parser_antlr4::~parser_antlr4() {
  delete _interpreter;
}

const atn::ATN& parser_antlr4::getATN() const {
  return *parser_antlr4ParserStaticData->atn;
}

std::string parser_antlr4::getGrammarFileName() const {
  return "parser_antlr4.g4";
}

const std::vector<std::string>& parser_antlr4::getRuleNames() const {
  return parser_antlr4ParserStaticData->ruleNames;
}

const dfa::Vocabulary& parser_antlr4::getVocabulary() const {
  return parser_antlr4ParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView parser_antlr4::getSerializedATN() const {
  return parser_antlr4ParserStaticData->serializedATN;
}


//----------------- BlockContext ------------------------------------------------------------------

parser_antlr4::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<parser_antlr4::StatementContext *> parser_antlr4::BlockContext::statement() {
  return getRuleContexts<parser_antlr4::StatementContext>();
}

parser_antlr4::StatementContext* parser_antlr4::BlockContext::statement(size_t i) {
  return getRuleContext<parser_antlr4::StatementContext>(i);
}


size_t parser_antlr4::BlockContext::getRuleIndex() const {
  return parser_antlr4::RuleBlock;
}

void parser_antlr4::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void parser_antlr4::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any parser_antlr4::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::BlockContext* parser_antlr4::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 0, parser_antlr4::RuleBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(75);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(72);
        statement(); 
      }
      setState(77);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

parser_antlr4::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::LineContext* parser_antlr4::StatementContext::line() {
  return getRuleContext<parser_antlr4::LineContext>(0);
}

parser_antlr4::If_statementContext* parser_antlr4::StatementContext::if_statement() {
  return getRuleContext<parser_antlr4::If_statementContext>(0);
}

parser_antlr4::While_statementContext* parser_antlr4::StatementContext::while_statement() {
  return getRuleContext<parser_antlr4::While_statementContext>(0);
}

parser_antlr4::Do_while_statementContext* parser_antlr4::StatementContext::do_while_statement() {
  return getRuleContext<parser_antlr4::Do_while_statementContext>(0);
}

parser_antlr4::For_statementContext* parser_antlr4::StatementContext::for_statement() {
  return getRuleContext<parser_antlr4::For_statementContext>(0);
}

parser_antlr4::Break_statementContext* parser_antlr4::StatementContext::break_statement() {
  return getRuleContext<parser_antlr4::Break_statementContext>(0);
}

parser_antlr4::Continue_statementContext* parser_antlr4::StatementContext::continue_statement() {
  return getRuleContext<parser_antlr4::Continue_statementContext>(0);
}

parser_antlr4::SubroutineContext* parser_antlr4::StatementContext::subroutine() {
  return getRuleContext<parser_antlr4::SubroutineContext>(0);
}


size_t parser_antlr4::StatementContext::getRuleIndex() const {
  return parser_antlr4::RuleStatement;
}

void parser_antlr4::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void parser_antlr4::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any parser_antlr4::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::StatementContext* parser_antlr4::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, parser_antlr4::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::M99:
      case parser_antlr4::DIGIT:
      case parser_antlr4::LETTER:
      case parser_antlr4::DOLLAR:
      case parser_antlr4::SLASH:
      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::COMMENT:
      case parser_antlr4::NAMED_PARAMETER:
      case parser_antlr4::EOL: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        line();
        break;
      }

      case parser_antlr4::IF: {
        enterOuterAlt(_localctx, 2);
        setState(79);
        if_statement();
        break;
      }

      case parser_antlr4::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(80);
        while_statement();
        break;
      }

      case parser_antlr4::DO: {
        enterOuterAlt(_localctx, 4);
        setState(81);
        do_while_statement();
        break;
      }

      case parser_antlr4::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(82);
        for_statement();
        break;
      }

      case parser_antlr4::BREAK: {
        enterOuterAlt(_localctx, 6);
        setState(83);
        break_statement();
        break;
      }

      case parser_antlr4::CONTINUE: {
        enterOuterAlt(_localctx, 7);
        setState(84);
        continue_statement();
        break;
      }

      case parser_antlr4::SUBROUTINE: {
        enterOuterAlt(_localctx, 8);
        setState(85);
        subroutine();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineContext ------------------------------------------------------------------

parser_antlr4::SubroutineContext::SubroutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::SubroutineContext::SUBROUTINE() {
  return getToken(parser_antlr4::SUBROUTINE, 0);
}

parser_antlr4::Real_valueContext* parser_antlr4::SubroutineContext::real_value() {
  return getRuleContext<parser_antlr4::Real_valueContext>(0);
}

parser_antlr4::BlockContext* parser_antlr4::SubroutineContext::block() {
  return getRuleContext<parser_antlr4::BlockContext>(0);
}

parser_antlr4::M99Context* parser_antlr4::SubroutineContext::m99() {
  return getRuleContext<parser_antlr4::M99Context>(0);
}

std::vector<tree::TerminalNode *> parser_antlr4::SubroutineContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::SubroutineContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::SubroutineContext::getRuleIndex() const {
  return parser_antlr4::RuleSubroutine;
}

void parser_antlr4::SubroutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubroutine(this);
}

void parser_antlr4::SubroutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubroutine(this);
}


std::any parser_antlr4::SubroutineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitSubroutine(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::SubroutineContext* parser_antlr4::subroutine() {
  SubroutineContext *_localctx = _tracker.createInstance<SubroutineContext>(_ctx, getState());
  enterRule(_localctx, 4, parser_antlr4::RuleSubroutine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(parser_antlr4::SUBROUTINE);
    setState(89);
    real_value();
    setState(93);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(90);
        match(parser_antlr4::EOL); 
      }
      setState(95);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(96);
    block();
    setState(97);
    m99();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- M99Context ------------------------------------------------------------------

parser_antlr4::M99Context::M99Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::M99Context::M99() {
  return getToken(parser_antlr4::M99, 0);
}


size_t parser_antlr4::M99Context::getRuleIndex() const {
  return parser_antlr4::RuleM99;
}

void parser_antlr4::M99Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterM99(this);
}

void parser_antlr4::M99Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitM99(this);
}


std::any parser_antlr4::M99Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitM99(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::M99Context* parser_antlr4::m99() {
  M99Context *_localctx = _tracker.createInstance<M99Context>(_ctx, getState());
  enterRule(_localctx, 6, parser_antlr4::RuleM99);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(parser_antlr4::M99);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

parser_antlr4::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Block_deleteContext* parser_antlr4::LineContext::block_delete() {
  return getRuleContext<parser_antlr4::Block_deleteContext>(0);
}

parser_antlr4::Line_numberContext* parser_antlr4::LineContext::line_number() {
  return getRuleContext<parser_antlr4::Line_numberContext>(0);
}

std::vector<parser_antlr4::SegmentContext *> parser_antlr4::LineContext::segment() {
  return getRuleContexts<parser_antlr4::SegmentContext>();
}

parser_antlr4::SegmentContext* parser_antlr4::LineContext::segment(size_t i) {
  return getRuleContext<parser_antlr4::SegmentContext>(i);
}

std::vector<tree::TerminalNode *> parser_antlr4::LineContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::LineContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::LineContext::getRuleIndex() const {
  return parser_antlr4::RuleLine;
}

void parser_antlr4::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void parser_antlr4::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


std::any parser_antlr4::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::LineContext* parser_antlr4::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 8, parser_antlr4::RuleLine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::SLASH) {
      setState(101);
      block_delete();
    }
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::DIGIT) {
      setState(104);
      line_number();
    }
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29273397578760192) != 0)) {
      setState(107);
      segment();
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(114); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(113);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(116); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

parser_antlr4::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> parser_antlr4::If_statementContext::IF() {
  return getTokens(parser_antlr4::IF);
}

tree::TerminalNode* parser_antlr4::If_statementContext::IF(size_t i) {
  return getToken(parser_antlr4::IF, i);
}

std::vector<parser_antlr4::ExpressionContext *> parser_antlr4::If_statementContext::expression() {
  return getRuleContexts<parser_antlr4::ExpressionContext>();
}

parser_antlr4::ExpressionContext* parser_antlr4::If_statementContext::expression(size_t i) {
  return getRuleContext<parser_antlr4::ExpressionContext>(i);
}

std::vector<parser_antlr4::BlockContext *> parser_antlr4::If_statementContext::block() {
  return getRuleContexts<parser_antlr4::BlockContext>();
}

parser_antlr4::BlockContext* parser_antlr4::If_statementContext::block(size_t i) {
  return getRuleContext<parser_antlr4::BlockContext>(i);
}

tree::TerminalNode* parser_antlr4::If_statementContext::ENDIF() {
  return getToken(parser_antlr4::ENDIF, 0);
}

tree::TerminalNode* parser_antlr4::If_statementContext::END() {
  return getToken(parser_antlr4::END, 0);
}

std::vector<tree::TerminalNode *> parser_antlr4::If_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::If_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}

std::vector<tree::TerminalNode *> parser_antlr4::If_statementContext::ELSE() {
  return getTokens(parser_antlr4::ELSE);
}

tree::TerminalNode* parser_antlr4::If_statementContext::ELSE(size_t i) {
  return getToken(parser_antlr4::ELSE, i);
}


size_t parser_antlr4::If_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleIf_statement;
}

void parser_antlr4::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void parser_antlr4::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


std::any parser_antlr4::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::If_statementContext* parser_antlr4::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 10, parser_antlr4::RuleIf_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(parser_antlr4::IF);
    setState(119);
    expression();
    setState(123);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(120);
        match(parser_antlr4::EOL); 
      }
      setState(125);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(126);
    block();
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(127);
        match(parser_antlr4::ELSE);
        setState(128);
        match(parser_antlr4::IF);
        setState(129);
        expression();
        setState(133);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(130);
            match(parser_antlr4::EOL); 
          }
          setState(135);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
        }
        setState(136);
        block(); 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::ELSE) {
      setState(143);
      match(parser_antlr4::ELSE);
      setState(144);
      match(parser_antlr4::EOL);
      setState(145);
      block();
    }
    setState(148);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDIF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statementContext ------------------------------------------------------------------

parser_antlr4::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::While_statementContext::WHILE() {
  return getToken(parser_antlr4::WHILE, 0);
}

parser_antlr4::ExpressionContext* parser_antlr4::While_statementContext::expression() {
  return getRuleContext<parser_antlr4::ExpressionContext>(0);
}

parser_antlr4::BlockContext* parser_antlr4::While_statementContext::block() {
  return getRuleContext<parser_antlr4::BlockContext>(0);
}

tree::TerminalNode* parser_antlr4::While_statementContext::ENDWHILE() {
  return getToken(parser_antlr4::ENDWHILE, 0);
}

tree::TerminalNode* parser_antlr4::While_statementContext::END() {
  return getToken(parser_antlr4::END, 0);
}

std::vector<tree::TerminalNode *> parser_antlr4::While_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::While_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::While_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleWhile_statement;
}

void parser_antlr4::While_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_statement(this);
}

void parser_antlr4::While_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_statement(this);
}


std::any parser_antlr4::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::While_statementContext* parser_antlr4::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, parser_antlr4::RuleWhile_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(parser_antlr4::WHILE);
    setState(151);
    expression();
    setState(155);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(152);
        match(parser_antlr4::EOL); 
      }
      setState(157);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(158);
    block();
    setState(159);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDWHILE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Do_while_statementContext ------------------------------------------------------------------

parser_antlr4::Do_while_statementContext::Do_while_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Do_while_statementContext::DO() {
  return getToken(parser_antlr4::DO, 0);
}

parser_antlr4::BlockContext* parser_antlr4::Do_while_statementContext::block() {
  return getRuleContext<parser_antlr4::BlockContext>(0);
}

tree::TerminalNode* parser_antlr4::Do_while_statementContext::WHILE() {
  return getToken(parser_antlr4::WHILE, 0);
}

parser_antlr4::ExpressionContext* parser_antlr4::Do_while_statementContext::expression() {
  return getRuleContext<parser_antlr4::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> parser_antlr4::Do_while_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::Do_while_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::Do_while_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleDo_while_statement;
}

void parser_antlr4::Do_while_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDo_while_statement(this);
}

void parser_antlr4::Do_while_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDo_while_statement(this);
}


std::any parser_antlr4::Do_while_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitDo_while_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Do_while_statementContext* parser_antlr4::do_while_statement() {
  Do_while_statementContext *_localctx = _tracker.createInstance<Do_while_statementContext>(_ctx, getState());
  enterRule(_localctx, 14, parser_antlr4::RuleDo_while_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(parser_antlr4::DO);
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(162);
        match(parser_antlr4::EOL); 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(168);
    block();
    setState(169);
    match(parser_antlr4::WHILE);
    setState(170);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statementContext ------------------------------------------------------------------

parser_antlr4::For_statementContext::For_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::For_statementContext::FOR() {
  return getToken(parser_antlr4::FOR, 0);
}

parser_antlr4::Parameter_valueContext* parser_antlr4::For_statementContext::parameter_value() {
  return getRuleContext<parser_antlr4::Parameter_valueContext>(0);
}

tree::TerminalNode* parser_antlr4::For_statementContext::FROM() {
  return getToken(parser_antlr4::FROM, 0);
}

std::vector<parser_antlr4::ExpressionContext *> parser_antlr4::For_statementContext::expression() {
  return getRuleContexts<parser_antlr4::ExpressionContext>();
}

parser_antlr4::ExpressionContext* parser_antlr4::For_statementContext::expression(size_t i) {
  return getRuleContext<parser_antlr4::ExpressionContext>(i);
}

tree::TerminalNode* parser_antlr4::For_statementContext::TO() {
  return getToken(parser_antlr4::TO, 0);
}

tree::TerminalNode* parser_antlr4::For_statementContext::DO() {
  return getToken(parser_antlr4::DO, 0);
}

parser_antlr4::BlockContext* parser_antlr4::For_statementContext::block() {
  return getRuleContext<parser_antlr4::BlockContext>(0);
}

tree::TerminalNode* parser_antlr4::For_statementContext::ENDFOR() {
  return getToken(parser_antlr4::ENDFOR, 0);
}

tree::TerminalNode* parser_antlr4::For_statementContext::END() {
  return getToken(parser_antlr4::END, 0);
}

std::vector<tree::TerminalNode *> parser_antlr4::For_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::For_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::For_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleFor_statement;
}

void parser_antlr4::For_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_statement(this);
}

void parser_antlr4::For_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_statement(this);
}


std::any parser_antlr4::For_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitFor_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::For_statementContext* parser_antlr4::for_statement() {
  For_statementContext *_localctx = _tracker.createInstance<For_statementContext>(_ctx, getState());
  enterRule(_localctx, 16, parser_antlr4::RuleFor_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(parser_antlr4::FOR);
    setState(173);
    parameter_value();
    setState(174);
    match(parser_antlr4::FROM);
    setState(175);
    expression();
    setState(176);
    match(parser_antlr4::TO);
    setState(177);
    expression();
    setState(178);
    match(parser_antlr4::DO);
    setState(182);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(179);
        match(parser_antlr4::EOL); 
      }
      setState(184);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(185);
    block();
    setState(186);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDFOR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_statementContext ------------------------------------------------------------------

parser_antlr4::Break_statementContext::Break_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Break_statementContext::BREAK() {
  return getToken(parser_antlr4::BREAK, 0);
}


size_t parser_antlr4::Break_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleBreak_statement;
}

void parser_antlr4::Break_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreak_statement(this);
}

void parser_antlr4::Break_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreak_statement(this);
}


std::any parser_antlr4::Break_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitBreak_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Break_statementContext* parser_antlr4::break_statement() {
  Break_statementContext *_localctx = _tracker.createInstance<Break_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, parser_antlr4::RuleBreak_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(parser_antlr4::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_statementContext ------------------------------------------------------------------

parser_antlr4::Continue_statementContext::Continue_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Continue_statementContext::CONTINUE() {
  return getToken(parser_antlr4::CONTINUE, 0);
}


size_t parser_antlr4::Continue_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleContinue_statement;
}

void parser_antlr4::Continue_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinue_statement(this);
}

void parser_antlr4::Continue_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinue_statement(this);
}


std::any parser_antlr4::Continue_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitContinue_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Continue_statementContext* parser_antlr4::continue_statement() {
  Continue_statementContext *_localctx = _tracker.createInstance<Continue_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, parser_antlr4::RuleContinue_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(parser_antlr4::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_deleteContext ------------------------------------------------------------------

parser_antlr4::Block_deleteContext::Block_deleteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Block_deleteContext::SLASH() {
  return getToken(parser_antlr4::SLASH, 0);
}


size_t parser_antlr4::Block_deleteContext::getRuleIndex() const {
  return parser_antlr4::RuleBlock_delete;
}

void parser_antlr4::Block_deleteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_delete(this);
}

void parser_antlr4::Block_deleteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_delete(this);
}


std::any parser_antlr4::Block_deleteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitBlock_delete(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Block_deleteContext* parser_antlr4::block_delete() {
  Block_deleteContext *_localctx = _tracker.createInstance<Block_deleteContext>(_ctx, getState());
  enterRule(_localctx, 22, parser_antlr4::RuleBlock_delete);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(parser_antlr4::SLASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Line_numberContext ------------------------------------------------------------------

parser_antlr4::Line_numberContext::Line_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> parser_antlr4::Line_numberContext::DIGIT() {
  return getTokens(parser_antlr4::DIGIT);
}

tree::TerminalNode* parser_antlr4::Line_numberContext::DIGIT(size_t i) {
  return getToken(parser_antlr4::DIGIT, i);
}


size_t parser_antlr4::Line_numberContext::getRuleIndex() const {
  return parser_antlr4::RuleLine_number;
}

void parser_antlr4::Line_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine_number(this);
}

void parser_antlr4::Line_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine_number(this);
}


std::any parser_antlr4::Line_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitLine_number(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Line_numberContext* parser_antlr4::line_number() {
  Line_numberContext *_localctx = _tracker.createInstance<Line_numberContext>(_ctx, getState());
  enterRule(_localctx, 24, parser_antlr4::RuleLine_number);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(194);
      match(parser_antlr4::DIGIT);
      setState(197); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == parser_antlr4::DIGIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SegmentContext ------------------------------------------------------------------

parser_antlr4::SegmentContext::SegmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Mid_line_wordContext* parser_antlr4::SegmentContext::mid_line_word() {
  return getRuleContext<parser_antlr4::Mid_line_wordContext>(0);
}

parser_antlr4::Parameter_settingContext* parser_antlr4::SegmentContext::parameter_setting() {
  return getRuleContext<parser_antlr4::Parameter_settingContext>(0);
}

parser_antlr4::CommentContext* parser_antlr4::SegmentContext::comment() {
  return getRuleContext<parser_antlr4::CommentContext>(0);
}

parser_antlr4::M99Context* parser_antlr4::SegmentContext::m99() {
  return getRuleContext<parser_antlr4::M99Context>(0);
}


size_t parser_antlr4::SegmentContext::getRuleIndex() const {
  return parser_antlr4::RuleSegment;
}

void parser_antlr4::SegmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSegment(this);
}

void parser_antlr4::SegmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSegment(this);
}


std::any parser_antlr4::SegmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitSegment(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::SegmentContext* parser_antlr4::segment() {
  SegmentContext *_localctx = _tracker.createInstance<SegmentContext>(_ctx, getState());
  enterRule(_localctx, 26, parser_antlr4::RuleSegment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::LETTER:
      case parser_antlr4::DOLLAR: {
        enterOuterAlt(_localctx, 1);
        setState(199);
        mid_line_word();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(200);
        parameter_setting();
        break;
      }

      case parser_antlr4::COMMENT: {
        enterOuterAlt(_localctx, 3);
        setState(201);
        comment();
        break;
      }

      case parser_antlr4::M99: {
        enterOuterAlt(_localctx, 4);
        setState(202);
        m99();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mid_line_wordContext ------------------------------------------------------------------

parser_antlr4::Mid_line_wordContext::Mid_line_wordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Mid_line_letterContext* parser_antlr4::Mid_line_wordContext::mid_line_letter() {
  return getRuleContext<parser_antlr4::Mid_line_letterContext>(0);
}

parser_antlr4::Real_valueContext* parser_antlr4::Mid_line_wordContext::real_value() {
  return getRuleContext<parser_antlr4::Real_valueContext>(0);
}


size_t parser_antlr4::Mid_line_wordContext::getRuleIndex() const {
  return parser_antlr4::RuleMid_line_word;
}

void parser_antlr4::Mid_line_wordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMid_line_word(this);
}

void parser_antlr4::Mid_line_wordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMid_line_word(this);
}


std::any parser_antlr4::Mid_line_wordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitMid_line_word(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Mid_line_wordContext* parser_antlr4::mid_line_word() {
  Mid_line_wordContext *_localctx = _tracker.createInstance<Mid_line_wordContext>(_ctx, getState());
  enterRule(_localctx, 28, parser_antlr4::RuleMid_line_word);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    mid_line_letter();
    setState(206);
    real_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mid_line_letterContext ------------------------------------------------------------------

parser_antlr4::Mid_line_letterContext::Mid_line_letterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Mid_line_letterContext::LETTER() {
  return getToken(parser_antlr4::LETTER, 0);
}

tree::TerminalNode* parser_antlr4::Mid_line_letterContext::DOLLAR() {
  return getToken(parser_antlr4::DOLLAR, 0);
}


size_t parser_antlr4::Mid_line_letterContext::getRuleIndex() const {
  return parser_antlr4::RuleMid_line_letter;
}

void parser_antlr4::Mid_line_letterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMid_line_letter(this);
}

void parser_antlr4::Mid_line_letterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMid_line_letter(this);
}


std::any parser_antlr4::Mid_line_letterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitMid_line_letter(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Mid_line_letterContext* parser_antlr4::mid_line_letter() {
  Mid_line_letterContext *_localctx = _tracker.createInstance<Mid_line_letterContext>(_ctx, getState());
  enterRule(_localctx, 30, parser_antlr4::RuleMid_line_letter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::LETTER

    || _la == parser_antlr4::DOLLAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Real_valueContext ------------------------------------------------------------------

parser_antlr4::Real_valueContext::Real_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Unary_comboContext* parser_antlr4::Real_valueContext::unary_combo() {
  return getRuleContext<parser_antlr4::Unary_comboContext>(0);
}

parser_antlr4::Parameter_valueContext* parser_antlr4::Real_valueContext::parameter_value() {
  return getRuleContext<parser_antlr4::Parameter_valueContext>(0);
}

parser_antlr4::ExpressionContext* parser_antlr4::Real_valueContext::expression() {
  return getRuleContext<parser_antlr4::ExpressionContext>(0);
}

parser_antlr4::Real_numberContext* parser_antlr4::Real_valueContext::real_number() {
  return getRuleContext<parser_antlr4::Real_numberContext>(0);
}


size_t parser_antlr4::Real_valueContext::getRuleIndex() const {
  return parser_antlr4::RuleReal_value;
}

void parser_antlr4::Real_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_value(this);
}

void parser_antlr4::Real_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_value(this);
}


std::any parser_antlr4::Real_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitReal_value(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Real_valueContext* parser_antlr4::real_value() {
  Real_valueContext *_localctx = _tracker.createInstance<Real_valueContext>(_ctx, getState());
  enterRule(_localctx, 32, parser_antlr4::RuleReal_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(214);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(210);
      unary_combo();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      parameter_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(212);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(213);
      real_number();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Real_numberContext ------------------------------------------------------------------

parser_antlr4::Real_numberContext::Real_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> parser_antlr4::Real_numberContext::DIGIT() {
  return getTokens(parser_antlr4::DIGIT);
}

tree::TerminalNode* parser_antlr4::Real_numberContext::DIGIT(size_t i) {
  return getToken(parser_antlr4::DIGIT, i);
}

tree::TerminalNode* parser_antlr4::Real_numberContext::DOT() {
  return getToken(parser_antlr4::DOT, 0);
}

tree::TerminalNode* parser_antlr4::Real_numberContext::PLUS() {
  return getToken(parser_antlr4::PLUS, 0);
}

tree::TerminalNode* parser_antlr4::Real_numberContext::MINUS() {
  return getToken(parser_antlr4::MINUS, 0);
}


size_t parser_antlr4::Real_numberContext::getRuleIndex() const {
  return parser_antlr4::RuleReal_number;
}

void parser_antlr4::Real_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal_number(this);
}

void parser_antlr4::Real_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal_number(this);
}


std::any parser_antlr4::Real_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitReal_number(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Real_numberContext* parser_antlr4::real_number() {
  Real_numberContext *_localctx = _tracker.createInstance<Real_numberContext>(_ctx, getState());
  enterRule(_localctx, 34, parser_antlr4::RuleReal_number);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(216);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(220); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(219);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(222); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(231);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(224);
        match(parser_antlr4::DOT);
        setState(228);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(225);
            match(parser_antlr4::DIGIT); 
          }
          setState(230);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        }
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(234);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(233);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(236);
      match(parser_antlr4::DOT);
      setState(238); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(237);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(240); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

parser_antlr4::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Logical_or_expressionContext* parser_antlr4::ExpressionContext::logical_or_expression() {
  return getRuleContext<parser_antlr4::Logical_or_expressionContext>(0);
}


size_t parser_antlr4::ExpressionContext::getRuleIndex() const {
  return parser_antlr4::RuleExpression;
}

void parser_antlr4::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void parser_antlr4::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any parser_antlr4::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::ExpressionContext* parser_antlr4::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 36, parser_antlr4::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    logical_or_expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logical_or_expressionContext ------------------------------------------------------------------

parser_antlr4::Logical_or_expressionContext::Logical_or_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Logical_xor_expressionContext* parser_antlr4::Logical_or_expressionContext::logical_xor_expression() {
  return getRuleContext<parser_antlr4::Logical_xor_expressionContext>(0);
}

parser_antlr4::Logical_or_expressionContext* parser_antlr4::Logical_or_expressionContext::logical_or_expression() {
  return getRuleContext<parser_antlr4::Logical_or_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Logical_or_expressionContext::NON_EXCLUSIVE_OR() {
  return getToken(parser_antlr4::NON_EXCLUSIVE_OR, 0);
}


size_t parser_antlr4::Logical_or_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleLogical_or_expression;
}

void parser_antlr4::Logical_or_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_or_expression(this);
}

void parser_antlr4::Logical_or_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_or_expression(this);
}


std::any parser_antlr4::Logical_or_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitLogical_or_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Logical_or_expressionContext* parser_antlr4::logical_or_expression() {
   return logical_or_expression(0);
}

parser_antlr4::Logical_or_expressionContext* parser_antlr4::logical_or_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Logical_or_expressionContext *_localctx = _tracker.createInstance<Logical_or_expressionContext>(_ctx, parentState);
  parser_antlr4::Logical_or_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, parser_antlr4::RuleLogical_or_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(247);
    logical_xor_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(254);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_or_expression);
        setState(249);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(250);
        match(parser_antlr4::NON_EXCLUSIVE_OR);
        setState(251);
        logical_xor_expression(0); 
      }
      setState(256);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Logical_xor_expressionContext ------------------------------------------------------------------

parser_antlr4::Logical_xor_expressionContext::Logical_xor_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Logical_and_expressionContext* parser_antlr4::Logical_xor_expressionContext::logical_and_expression() {
  return getRuleContext<parser_antlr4::Logical_and_expressionContext>(0);
}

parser_antlr4::Logical_xor_expressionContext* parser_antlr4::Logical_xor_expressionContext::logical_xor_expression() {
  return getRuleContext<parser_antlr4::Logical_xor_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Logical_xor_expressionContext::EXCLUSIVE_OR() {
  return getToken(parser_antlr4::EXCLUSIVE_OR, 0);
}


size_t parser_antlr4::Logical_xor_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleLogical_xor_expression;
}

void parser_antlr4::Logical_xor_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_xor_expression(this);
}

void parser_antlr4::Logical_xor_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_xor_expression(this);
}


std::any parser_antlr4::Logical_xor_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitLogical_xor_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Logical_xor_expressionContext* parser_antlr4::logical_xor_expression() {
   return logical_xor_expression(0);
}

parser_antlr4::Logical_xor_expressionContext* parser_antlr4::logical_xor_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Logical_xor_expressionContext *_localctx = _tracker.createInstance<Logical_xor_expressionContext>(_ctx, parentState);
  parser_antlr4::Logical_xor_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, parser_antlr4::RuleLogical_xor_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(258);
    logical_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(265);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_xor_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_xor_expression);
        setState(260);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(261);
        match(parser_antlr4::EXCLUSIVE_OR);
        setState(262);
        logical_and_expression(0); 
      }
      setState(267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Logical_and_expressionContext ------------------------------------------------------------------

parser_antlr4::Logical_and_expressionContext::Logical_and_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Equality_expressionContext* parser_antlr4::Logical_and_expressionContext::equality_expression() {
  return getRuleContext<parser_antlr4::Equality_expressionContext>(0);
}

parser_antlr4::Logical_and_expressionContext* parser_antlr4::Logical_and_expressionContext::logical_and_expression() {
  return getRuleContext<parser_antlr4::Logical_and_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Logical_and_expressionContext::LOGICAL_AND() {
  return getToken(parser_antlr4::LOGICAL_AND, 0);
}


size_t parser_antlr4::Logical_and_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleLogical_and_expression;
}

void parser_antlr4::Logical_and_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical_and_expression(this);
}

void parser_antlr4::Logical_and_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical_and_expression(this);
}


std::any parser_antlr4::Logical_and_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitLogical_and_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Logical_and_expressionContext* parser_antlr4::logical_and_expression() {
   return logical_and_expression(0);
}

parser_antlr4::Logical_and_expressionContext* parser_antlr4::logical_and_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Logical_and_expressionContext *_localctx = _tracker.createInstance<Logical_and_expressionContext>(_ctx, parentState);
  parser_antlr4::Logical_and_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, parser_antlr4::RuleLogical_and_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(269);
    equality_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(276);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_and_expression);
        setState(271);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(272);
        match(parser_antlr4::LOGICAL_AND);
        setState(273);
        equality_expression(0); 
      }
      setState(278);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Equality_expressionContext ------------------------------------------------------------------

parser_antlr4::Equality_expressionContext::Equality_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Relational_expressionContext* parser_antlr4::Equality_expressionContext::relational_expression() {
  return getRuleContext<parser_antlr4::Relational_expressionContext>(0);
}

parser_antlr4::Equality_expressionContext* parser_antlr4::Equality_expressionContext::equality_expression() {
  return getRuleContext<parser_antlr4::Equality_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Equality_expressionContext::EQ() {
  return getToken(parser_antlr4::EQ, 0);
}

tree::TerminalNode* parser_antlr4::Equality_expressionContext::NE() {
  return getToken(parser_antlr4::NE, 0);
}


size_t parser_antlr4::Equality_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleEquality_expression;
}

void parser_antlr4::Equality_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEquality_expression(this);
}

void parser_antlr4::Equality_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEquality_expression(this);
}


std::any parser_antlr4::Equality_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitEquality_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Equality_expressionContext* parser_antlr4::equality_expression() {
   return equality_expression(0);
}

parser_antlr4::Equality_expressionContext* parser_antlr4::equality_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Equality_expressionContext *_localctx = _tracker.createInstance<Equality_expressionContext>(_ctx, parentState);
  parser_antlr4::Equality_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, parser_antlr4::RuleEquality_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(280);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(287);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
        setState(282);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(283);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::EQ

        || _la == parser_antlr4::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(284);
        relational_expression(0); 
      }
      setState(289);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Relational_expressionContext ------------------------------------------------------------------

parser_antlr4::Relational_expressionContext::Relational_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Additive_expressionContext* parser_antlr4::Relational_expressionContext::additive_expression() {
  return getRuleContext<parser_antlr4::Additive_expressionContext>(0);
}

parser_antlr4::Relational_expressionContext* parser_antlr4::Relational_expressionContext::relational_expression() {
  return getRuleContext<parser_antlr4::Relational_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Relational_expressionContext::LT() {
  return getToken(parser_antlr4::LT, 0);
}

tree::TerminalNode* parser_antlr4::Relational_expressionContext::LE() {
  return getToken(parser_antlr4::LE, 0);
}

tree::TerminalNode* parser_antlr4::Relational_expressionContext::GT() {
  return getToken(parser_antlr4::GT, 0);
}

tree::TerminalNode* parser_antlr4::Relational_expressionContext::GE() {
  return getToken(parser_antlr4::GE, 0);
}


size_t parser_antlr4::Relational_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleRelational_expression;
}

void parser_antlr4::Relational_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational_expression(this);
}

void parser_antlr4::Relational_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational_expression(this);
}


std::any parser_antlr4::Relational_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitRelational_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Relational_expressionContext* parser_antlr4::relational_expression() {
   return relational_expression(0);
}

parser_antlr4::Relational_expressionContext* parser_antlr4::relational_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Relational_expressionContext *_localctx = _tracker.createInstance<Relational_expressionContext>(_ctx, parentState);
  parser_antlr4::Relational_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, parser_antlr4::RuleRelational_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(291);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
        setState(293);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(294);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 257698037760) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(295);
        additive_expression(0); 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Additive_expressionContext ------------------------------------------------------------------

parser_antlr4::Additive_expressionContext::Additive_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Multiplicative_expressionContext* parser_antlr4::Additive_expressionContext::multiplicative_expression() {
  return getRuleContext<parser_antlr4::Multiplicative_expressionContext>(0);
}

parser_antlr4::Additive_expressionContext* parser_antlr4::Additive_expressionContext::additive_expression() {
  return getRuleContext<parser_antlr4::Additive_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Additive_expressionContext::PLUS() {
  return getToken(parser_antlr4::PLUS, 0);
}

tree::TerminalNode* parser_antlr4::Additive_expressionContext::MINUS() {
  return getToken(parser_antlr4::MINUS, 0);
}


size_t parser_antlr4::Additive_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleAdditive_expression;
}

void parser_antlr4::Additive_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditive_expression(this);
}

void parser_antlr4::Additive_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditive_expression(this);
}


std::any parser_antlr4::Additive_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitAdditive_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Additive_expressionContext* parser_antlr4::additive_expression() {
   return additive_expression(0);
}

parser_antlr4::Additive_expressionContext* parser_antlr4::additive_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Additive_expressionContext *_localctx = _tracker.createInstance<Additive_expressionContext>(_ctx, parentState);
  parser_antlr4::Additive_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, parser_antlr4::RuleAdditive_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(302);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
        setState(304);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(305);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(306);
        multiplicative_expression(0); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Multiplicative_expressionContext ------------------------------------------------------------------

parser_antlr4::Multiplicative_expressionContext::Multiplicative_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Power_expressionContext* parser_antlr4::Multiplicative_expressionContext::power_expression() {
  return getRuleContext<parser_antlr4::Power_expressionContext>(0);
}

parser_antlr4::Multiplicative_expressionContext* parser_antlr4::Multiplicative_expressionContext::multiplicative_expression() {
  return getRuleContext<parser_antlr4::Multiplicative_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Multiplicative_expressionContext::TIMES() {
  return getToken(parser_antlr4::TIMES, 0);
}

tree::TerminalNode* parser_antlr4::Multiplicative_expressionContext::SLASH() {
  return getToken(parser_antlr4::SLASH, 0);
}

tree::TerminalNode* parser_antlr4::Multiplicative_expressionContext::MODULO() {
  return getToken(parser_antlr4::MODULO, 0);
}


size_t parser_antlr4::Multiplicative_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleMultiplicative_expression;
}

void parser_antlr4::Multiplicative_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicative_expression(this);
}

void parser_antlr4::Multiplicative_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicative_expression(this);
}


std::any parser_antlr4::Multiplicative_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitMultiplicative_expression(this);
  else
    return visitor->visitChildren(this);
}


parser_antlr4::Multiplicative_expressionContext* parser_antlr4::multiplicative_expression() {
   return multiplicative_expression(0);
}

parser_antlr4::Multiplicative_expressionContext* parser_antlr4::multiplicative_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  parser_antlr4::Multiplicative_expressionContext *_localctx = _tracker.createInstance<Multiplicative_expressionContext>(_ctx, parentState);
  parser_antlr4::Multiplicative_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, parser_antlr4::RuleMultiplicative_expression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(313);
    power_expression();
    _ctx->stop = _input->LT(-1);
    setState(320);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
        setState(315);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(316);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 469762048) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(317);
        power_expression(); 
      }
      setState(322);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Power_expressionContext ------------------------------------------------------------------

parser_antlr4::Power_expressionContext::Power_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Unary_expressionContext* parser_antlr4::Power_expressionContext::unary_expression() {
  return getRuleContext<parser_antlr4::Unary_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Power_expressionContext::POWER() {
  return getToken(parser_antlr4::POWER, 0);
}

parser_antlr4::Power_expressionContext* parser_antlr4::Power_expressionContext::power_expression() {
  return getRuleContext<parser_antlr4::Power_expressionContext>(0);
}


size_t parser_antlr4::Power_expressionContext::getRuleIndex() const {
  return parser_antlr4::RulePower_expression;
}

void parser_antlr4::Power_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPower_expression(this);
}

void parser_antlr4::Power_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPower_expression(this);
}


std::any parser_antlr4::Power_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitPower_expression(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Power_expressionContext* parser_antlr4::power_expression() {
  Power_expressionContext *_localctx = _tracker.createInstance<Power_expressionContext>(_ctx, getState());
  enterRule(_localctx, 52, parser_antlr4::RulePower_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(328);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(323);
      unary_expression();
      setState(324);
      match(parser_antlr4::POWER);
      setState(325);
      power_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(327);
      unary_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

parser_antlr4::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Unary_expressionContext::PLUS() {
  return getToken(parser_antlr4::PLUS, 0);
}

parser_antlr4::Unary_expressionContext* parser_antlr4::Unary_expressionContext::unary_expression() {
  return getRuleContext<parser_antlr4::Unary_expressionContext>(0);
}

tree::TerminalNode* parser_antlr4::Unary_expressionContext::MINUS() {
  return getToken(parser_antlr4::MINUS, 0);
}

parser_antlr4::Unary_comboContext* parser_antlr4::Unary_expressionContext::unary_combo() {
  return getRuleContext<parser_antlr4::Unary_comboContext>(0);
}

parser_antlr4::PrimaryContext* parser_antlr4::Unary_expressionContext::primary() {
  return getRuleContext<parser_antlr4::PrimaryContext>(0);
}


size_t parser_antlr4::Unary_expressionContext::getRuleIndex() const {
  return parser_antlr4::RuleUnary_expression;
}

void parser_antlr4::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void parser_antlr4::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}


std::any parser_antlr4::Unary_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitUnary_expression(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Unary_expressionContext* parser_antlr4::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 54, parser_antlr4::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(330);
      match(parser_antlr4::PLUS);
      setState(331);
      unary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      match(parser_antlr4::MINUS);
      setState(333);
      unary_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(334);
      unary_combo();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(335);
      primary();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

parser_antlr4::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Real_numberContext* parser_antlr4::PrimaryContext::real_number() {
  return getRuleContext<parser_antlr4::Real_numberContext>(0);
}

parser_antlr4::Parameter_valueContext* parser_antlr4::PrimaryContext::parameter_value() {
  return getRuleContext<parser_antlr4::Parameter_valueContext>(0);
}

tree::TerminalNode* parser_antlr4::PrimaryContext::LEFT_BRACKET() {
  return getToken(parser_antlr4::LEFT_BRACKET, 0);
}

parser_antlr4::ExpressionContext* parser_antlr4::PrimaryContext::expression() {
  return getRuleContext<parser_antlr4::ExpressionContext>(0);
}

tree::TerminalNode* parser_antlr4::PrimaryContext::RIGHT_BRACKET() {
  return getToken(parser_antlr4::RIGHT_BRACKET, 0);
}


size_t parser_antlr4::PrimaryContext::getRuleIndex() const {
  return parser_antlr4::RulePrimary;
}

void parser_antlr4::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void parser_antlr4::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any parser_antlr4::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::PrimaryContext* parser_antlr4::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 56, parser_antlr4::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::DIGIT:
      case parser_antlr4::PLUS:
      case parser_antlr4::MINUS:
      case parser_antlr4::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(338);
        real_number();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(339);
        parameter_value();
        break;
      }

      case parser_antlr4::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(340);
        match(parser_antlr4::LEFT_BRACKET);
        setState(341);
        expression();
        setState(342);
        match(parser_antlr4::RIGHT_BRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_comboContext ------------------------------------------------------------------

parser_antlr4::Unary_comboContext::Unary_comboContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Ordinary_unary_comboContext* parser_antlr4::Unary_comboContext::ordinary_unary_combo() {
  return getRuleContext<parser_antlr4::Ordinary_unary_comboContext>(0);
}

parser_antlr4::Arc_tangent_comboContext* parser_antlr4::Unary_comboContext::arc_tangent_combo() {
  return getRuleContext<parser_antlr4::Arc_tangent_comboContext>(0);
}


size_t parser_antlr4::Unary_comboContext::getRuleIndex() const {
  return parser_antlr4::RuleUnary_combo;
}

void parser_antlr4::Unary_comboContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_combo(this);
}

void parser_antlr4::Unary_comboContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_combo(this);
}


std::any parser_antlr4::Unary_comboContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitUnary_combo(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Unary_comboContext* parser_antlr4::unary_combo() {
  Unary_comboContext *_localctx = _tracker.createInstance<Unary_comboContext>(_ctx, getState());
  enterRule(_localctx, 58, parser_antlr4::RuleUnary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::ABSOLUTE_VALUE:
      case parser_antlr4::ARC_COSINE:
      case parser_antlr4::ARC_SINE:
      case parser_antlr4::COSINE:
      case parser_antlr4::E_RAISED_TO:
      case parser_antlr4::FIX_DOWN:
      case parser_antlr4::FIX_UP:
      case parser_antlr4::NATURAL_LOG_OF:
      case parser_antlr4::ROUND_OPERATION:
      case parser_antlr4::SINE:
      case parser_antlr4::SQUARE_ROOT:
      case parser_antlr4::TANGENT: {
        enterOuterAlt(_localctx, 1);
        setState(346);
        ordinary_unary_combo();
        break;
      }

      case parser_antlr4::ARC_TANGENT: {
        enterOuterAlt(_localctx, 2);
        setState(347);
        arc_tangent_combo();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ordinary_unary_comboContext ------------------------------------------------------------------

parser_antlr4::Ordinary_unary_comboContext::Ordinary_unary_comboContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::Ordinary_unary_operationContext* parser_antlr4::Ordinary_unary_comboContext::ordinary_unary_operation() {
  return getRuleContext<parser_antlr4::Ordinary_unary_operationContext>(0);
}

parser_antlr4::ExpressionContext* parser_antlr4::Ordinary_unary_comboContext::expression() {
  return getRuleContext<parser_antlr4::ExpressionContext>(0);
}


size_t parser_antlr4::Ordinary_unary_comboContext::getRuleIndex() const {
  return parser_antlr4::RuleOrdinary_unary_combo;
}

void parser_antlr4::Ordinary_unary_comboContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdinary_unary_combo(this);
}

void parser_antlr4::Ordinary_unary_comboContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdinary_unary_combo(this);
}


std::any parser_antlr4::Ordinary_unary_comboContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitOrdinary_unary_combo(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Ordinary_unary_comboContext* parser_antlr4::ordinary_unary_combo() {
  Ordinary_unary_comboContext *_localctx = _tracker.createInstance<Ordinary_unary_comboContext>(_ctx, getState());
  enterRule(_localctx, 60, parser_antlr4::RuleOrdinary_unary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    ordinary_unary_operation();
    setState(351);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ordinary_unary_operationContext ------------------------------------------------------------------

parser_antlr4::Ordinary_unary_operationContext::Ordinary_unary_operationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::ABSOLUTE_VALUE() {
  return getToken(parser_antlr4::ABSOLUTE_VALUE, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::ARC_COSINE() {
  return getToken(parser_antlr4::ARC_COSINE, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::ARC_SINE() {
  return getToken(parser_antlr4::ARC_SINE, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::COSINE() {
  return getToken(parser_antlr4::COSINE, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::E_RAISED_TO() {
  return getToken(parser_antlr4::E_RAISED_TO, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::FIX_DOWN() {
  return getToken(parser_antlr4::FIX_DOWN, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::FIX_UP() {
  return getToken(parser_antlr4::FIX_UP, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::NATURAL_LOG_OF() {
  return getToken(parser_antlr4::NATURAL_LOG_OF, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::ROUND_OPERATION() {
  return getToken(parser_antlr4::ROUND_OPERATION, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::SINE() {
  return getToken(parser_antlr4::SINE, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::SQUARE_ROOT() {
  return getToken(parser_antlr4::SQUARE_ROOT, 0);
}

tree::TerminalNode* parser_antlr4::Ordinary_unary_operationContext::TANGENT() {
  return getToken(parser_antlr4::TANGENT, 0);
}


size_t parser_antlr4::Ordinary_unary_operationContext::getRuleIndex() const {
  return parser_antlr4::RuleOrdinary_unary_operation;
}

void parser_antlr4::Ordinary_unary_operationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdinary_unary_operation(this);
}

void parser_antlr4::Ordinary_unary_operationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdinary_unary_operation(this);
}


std::any parser_antlr4::Ordinary_unary_operationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitOrdinary_unary_operation(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Ordinary_unary_operationContext* parser_antlr4::ordinary_unary_operation() {
  Ordinary_unary_operationContext *_localctx = _tracker.createInstance<Ordinary_unary_operationContext>(_ctx, getState());
  enterRule(_localctx, 62, parser_antlr4::RuleOrdinary_unary_operation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1125625028935680) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arc_tangent_comboContext ------------------------------------------------------------------

parser_antlr4::Arc_tangent_comboContext::Arc_tangent_comboContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Arc_tangent_comboContext::ARC_TANGENT() {
  return getToken(parser_antlr4::ARC_TANGENT, 0);
}

std::vector<parser_antlr4::ExpressionContext *> parser_antlr4::Arc_tangent_comboContext::expression() {
  return getRuleContexts<parser_antlr4::ExpressionContext>();
}

parser_antlr4::ExpressionContext* parser_antlr4::Arc_tangent_comboContext::expression(size_t i) {
  return getRuleContext<parser_antlr4::ExpressionContext>(i);
}

tree::TerminalNode* parser_antlr4::Arc_tangent_comboContext::SLASH() {
  return getToken(parser_antlr4::SLASH, 0);
}


size_t parser_antlr4::Arc_tangent_comboContext::getRuleIndex() const {
  return parser_antlr4::RuleArc_tangent_combo;
}

void parser_antlr4::Arc_tangent_comboContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArc_tangent_combo(this);
}

void parser_antlr4::Arc_tangent_comboContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArc_tangent_combo(this);
}


std::any parser_antlr4::Arc_tangent_comboContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitArc_tangent_combo(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Arc_tangent_comboContext* parser_antlr4::arc_tangent_combo() {
  Arc_tangent_comboContext *_localctx = _tracker.createInstance<Arc_tangent_comboContext>(_ctx, getState());
  enterRule(_localctx, 64, parser_antlr4::RuleArc_tangent_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(parser_antlr4::ARC_TANGENT);
    setState(356);
    expression();
    setState(357);
    match(parser_antlr4::SLASH);
    setState(358);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_settingContext ------------------------------------------------------------------

parser_antlr4::Parameter_settingContext::Parameter_settingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Parameter_settingContext::EQUAL_SIGN() {
  return getToken(parser_antlr4::EQUAL_SIGN, 0);
}

parser_antlr4::Real_valueContext* parser_antlr4::Parameter_settingContext::real_value() {
  return getRuleContext<parser_antlr4::Real_valueContext>(0);
}

tree::TerminalNode* parser_antlr4::Parameter_settingContext::PARAMETER_SIGN() {
  return getToken(parser_antlr4::PARAMETER_SIGN, 0);
}

parser_antlr4::PrimaryContext* parser_antlr4::Parameter_settingContext::primary() {
  return getRuleContext<parser_antlr4::PrimaryContext>(0);
}

tree::TerminalNode* parser_antlr4::Parameter_settingContext::NAMED_PARAMETER() {
  return getToken(parser_antlr4::NAMED_PARAMETER, 0);
}


size_t parser_antlr4::Parameter_settingContext::getRuleIndex() const {
  return parser_antlr4::RuleParameter_setting;
}

void parser_antlr4::Parameter_settingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_setting(this);
}

void parser_antlr4::Parameter_settingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_setting(this);
}


std::any parser_antlr4::Parameter_settingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitParameter_setting(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Parameter_settingContext* parser_antlr4::parameter_setting() {
  Parameter_settingContext *_localctx = _tracker.createInstance<Parameter_settingContext>(_ctx, getState());
  enterRule(_localctx, 66, parser_antlr4::RuleParameter_setting);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        setState(360);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(361);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        setState(362);
        match(parser_antlr4::NAMED_PARAMETER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(365);
    match(parser_antlr4::EQUAL_SIGN);
    setState(366);
    real_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_valueContext ------------------------------------------------------------------

parser_antlr4::Parameter_valueContext::Parameter_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Parameter_valueContext::PARAMETER_SIGN() {
  return getToken(parser_antlr4::PARAMETER_SIGN, 0);
}

parser_antlr4::PrimaryContext* parser_antlr4::Parameter_valueContext::primary() {
  return getRuleContext<parser_antlr4::PrimaryContext>(0);
}

tree::TerminalNode* parser_antlr4::Parameter_valueContext::NAMED_PARAMETER() {
  return getToken(parser_antlr4::NAMED_PARAMETER, 0);
}


size_t parser_antlr4::Parameter_valueContext::getRuleIndex() const {
  return parser_antlr4::RuleParameter_value;
}

void parser_antlr4::Parameter_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_value(this);
}

void parser_antlr4::Parameter_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_value(this);
}


std::any parser_antlr4::Parameter_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitParameter_value(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Parameter_valueContext* parser_antlr4::parameter_value() {
  Parameter_valueContext *_localctx = _tracker.createInstance<Parameter_valueContext>(_ctx, getState());
  enterRule(_localctx, 68, parser_antlr4::RuleParameter_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(371);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        enterOuterAlt(_localctx, 1);
        setState(368);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(369);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(370);
        match(parser_antlr4::NAMED_PARAMETER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

parser_antlr4::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::CommentContext::COMMENT() {
  return getToken(parser_antlr4::COMMENT, 0);
}


size_t parser_antlr4::CommentContext::getRuleIndex() const {
  return parser_antlr4::RuleComment;
}

void parser_antlr4::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void parser_antlr4::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}


std::any parser_antlr4::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::CommentContext* parser_antlr4::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 70, parser_antlr4::RuleComment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    match(parser_antlr4::COMMENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool parser_antlr4::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return logical_or_expressionSempred(antlrcpp::downCast<Logical_or_expressionContext *>(context), predicateIndex);
    case 20: return logical_xor_expressionSempred(antlrcpp::downCast<Logical_xor_expressionContext *>(context), predicateIndex);
    case 21: return logical_and_expressionSempred(antlrcpp::downCast<Logical_and_expressionContext *>(context), predicateIndex);
    case 22: return equality_expressionSempred(antlrcpp::downCast<Equality_expressionContext *>(context), predicateIndex);
    case 23: return relational_expressionSempred(antlrcpp::downCast<Relational_expressionContext *>(context), predicateIndex);
    case 24: return additive_expressionSempred(antlrcpp::downCast<Additive_expressionContext *>(context), predicateIndex);
    case 25: return multiplicative_expressionSempred(antlrcpp::downCast<Multiplicative_expressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::logical_or_expressionSempred(Logical_or_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::logical_xor_expressionSempred(Logical_xor_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::logical_and_expressionSempred(Logical_and_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::equality_expressionSempred(Equality_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool parser_antlr4::multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void parser_antlr4::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  parser_antlr4ParserInitialize();
#else
  ::antlr4::internal::call_once(parser_antlr4ParserOnceFlag, parser_antlr4ParserInitialize);
#endif
}
