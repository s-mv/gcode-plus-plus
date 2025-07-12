
// Generated from /home/smv/code/accelus/linuxcnc/src/emc/sterp/antlr4/parser_antlr4.g4 by ANTLR 4.13.2


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
      "'%'", "", "", "'$'", "'+'", "'-'", "'.'", "'['", "']'", "'**'", "'/'", 
      "", "'*'", "", "", "", "", "", "'<'", "'<='", "'>'", "'>='", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "'#'", "'='"
    },
    std::vector<std::string>{
      "", "IF", "THEN", "DO", "WHILE", "FOR", "FROM", "TO", "ELSE", "END", 
      "ENDIF", "ENDWHILE", "ENDFOR", "BREAK", "CONTINUE", "SUBROUTINE", 
      "M99", "PERCENT", "DIGIT", "LETTER", "DOLLAR", "PLUS", "MINUS", "DOT", 
      "LEFT_BRACKET", "RIGHT_BRACKET", "POWER", "SLASH", "MODULO", "TIMES", 
      "LOGICAL_AND", "EXCLUSIVE_OR", "NON_EXCLUSIVE_OR", "EQ", "NE", "LT", 
      "LE", "GT", "GE", "ABSOLUTE_VALUE", "ARC_COSINE", "ARC_SINE", "COSINE", 
      "E_RAISED_TO", "FIX_DOWN", "FIX_UP", "NATURAL_LOG_OF", "ROUND_OPERATION", 
      "SINE", "SQUARE_ROOT", "TANGENT", "ARC_TANGENT", "PARAMETER_SIGN", 
      "EQUAL_SIGN", "COMMENT", "NAMED_PARAMETER", "EOL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,57,404,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,1,0,1,0,1,0,5,0,76,8,0,10,0,12,0,79,9,0,1,0,1,0,1,0,5,0,84,8,0,10,
  	0,12,0,87,9,0,1,0,1,0,1,0,1,0,5,0,93,8,0,10,0,12,0,96,9,0,1,0,1,0,5,0,
  	100,8,0,10,0,12,0,103,9,0,3,0,105,8,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	3,1,115,8,1,1,2,1,2,1,2,5,2,120,8,2,10,2,12,2,123,9,2,1,2,1,2,1,2,1,3,
  	1,3,1,4,3,4,131,8,4,1,4,3,4,134,8,4,1,4,5,4,137,8,4,10,4,12,4,140,9,4,
  	1,4,4,4,143,8,4,11,4,12,4,144,1,5,1,5,1,5,5,5,150,8,5,10,5,12,5,153,9,
  	5,1,5,1,5,1,5,1,5,1,5,5,5,160,8,5,10,5,12,5,163,9,5,1,5,1,5,5,5,167,8,
  	5,10,5,12,5,170,9,5,1,5,1,5,1,5,3,5,175,8,5,1,5,1,5,1,6,1,6,1,6,5,6,182,
  	8,6,10,6,12,6,185,9,6,1,6,1,6,1,6,1,7,1,7,5,7,192,8,7,10,7,12,7,195,9,
  	7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,209,8,8,10,8,12,
  	8,212,9,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,4,12,224,8,12,
  	11,12,12,12,225,1,13,1,13,1,13,1,13,3,13,232,8,13,1,14,1,14,1,14,1,15,
  	1,15,1,16,1,16,1,16,1,16,3,16,243,8,16,1,17,3,17,246,8,17,1,17,4,17,249,
  	8,17,11,17,12,17,250,1,17,1,17,5,17,255,8,17,10,17,12,17,258,9,17,3,17,
  	260,8,17,1,17,3,17,263,8,17,1,17,1,17,4,17,267,8,17,11,17,12,17,268,3,
  	17,271,8,17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,5,19,281,8,19,10,
  	19,12,19,284,9,19,1,20,1,20,1,20,1,20,1,20,1,20,5,20,292,8,20,10,20,12,
  	20,295,9,20,1,21,1,21,1,21,1,21,1,21,1,21,5,21,303,8,21,10,21,12,21,306,
  	9,21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,314,8,22,10,22,12,22,317,9,22,
  	1,23,1,23,1,23,1,23,1,23,1,23,5,23,325,8,23,10,23,12,23,328,9,23,1,24,
  	1,24,1,24,1,24,1,24,1,24,5,24,336,8,24,10,24,12,24,339,9,24,1,25,1,25,
  	1,25,1,25,1,25,1,25,5,25,347,8,25,10,25,12,25,350,9,25,1,26,1,26,1,26,
  	1,26,1,26,3,26,357,8,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,365,8,27,1,
  	28,1,28,1,28,1,28,1,28,1,28,3,28,373,8,28,1,29,1,29,3,29,377,8,29,1,30,
  	1,30,1,30,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,3,33,392,
  	8,33,1,33,1,33,1,33,1,34,1,34,1,34,3,34,400,8,34,1,35,1,35,1,35,1,85,
  	7,38,40,42,44,46,48,50,36,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,0,9,1,0,9,
  	10,2,0,9,9,11,11,2,0,9,9,12,12,1,0,19,20,1,0,21,22,1,0,33,34,1,0,35,38,
  	1,0,27,29,1,0,39,50,422,0,104,1,0,0,0,2,114,1,0,0,0,4,116,1,0,0,0,6,127,
  	1,0,0,0,8,130,1,0,0,0,10,146,1,0,0,0,12,178,1,0,0,0,14,189,1,0,0,0,16,
  	200,1,0,0,0,18,216,1,0,0,0,20,218,1,0,0,0,22,220,1,0,0,0,24,223,1,0,0,
  	0,26,231,1,0,0,0,28,233,1,0,0,0,30,236,1,0,0,0,32,242,1,0,0,0,34,270,
  	1,0,0,0,36,272,1,0,0,0,38,274,1,0,0,0,40,285,1,0,0,0,42,296,1,0,0,0,44,
  	307,1,0,0,0,46,318,1,0,0,0,48,329,1,0,0,0,50,340,1,0,0,0,52,356,1,0,0,
  	0,54,364,1,0,0,0,56,372,1,0,0,0,58,376,1,0,0,0,60,378,1,0,0,0,62,381,
  	1,0,0,0,64,383,1,0,0,0,66,391,1,0,0,0,68,399,1,0,0,0,70,401,1,0,0,0,72,
  	73,5,17,0,0,73,77,5,56,0,0,74,76,3,2,1,0,75,74,1,0,0,0,76,79,1,0,0,0,
  	77,75,1,0,0,0,77,78,1,0,0,0,78,80,1,0,0,0,79,77,1,0,0,0,80,81,5,17,0,
  	0,81,85,5,56,0,0,82,84,9,0,0,0,83,82,1,0,0,0,84,87,1,0,0,0,85,86,1,0,
  	0,0,85,83,1,0,0,0,86,88,1,0,0,0,87,85,1,0,0,0,88,105,5,56,0,0,89,90,5,
  	17,0,0,90,94,5,56,0,0,91,93,3,2,1,0,92,91,1,0,0,0,93,96,1,0,0,0,94,92,
  	1,0,0,0,94,95,1,0,0,0,95,97,1,0,0,0,96,94,1,0,0,0,97,105,5,56,0,0,98,
  	100,3,2,1,0,99,98,1,0,0,0,100,103,1,0,0,0,101,99,1,0,0,0,101,102,1,0,
  	0,0,102,105,1,0,0,0,103,101,1,0,0,0,104,72,1,0,0,0,104,89,1,0,0,0,104,
  	101,1,0,0,0,105,1,1,0,0,0,106,115,3,8,4,0,107,115,3,10,5,0,108,115,3,
  	12,6,0,109,115,3,14,7,0,110,115,3,16,8,0,111,115,3,18,9,0,112,115,3,20,
  	10,0,113,115,3,4,2,0,114,106,1,0,0,0,114,107,1,0,0,0,114,108,1,0,0,0,
  	114,109,1,0,0,0,114,110,1,0,0,0,114,111,1,0,0,0,114,112,1,0,0,0,114,113,
  	1,0,0,0,115,3,1,0,0,0,116,117,5,15,0,0,117,121,3,32,16,0,118,120,5,56,
  	0,0,119,118,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,
  	124,1,0,0,0,123,121,1,0,0,0,124,125,3,0,0,0,125,126,3,6,3,0,126,5,1,0,
  	0,0,127,128,5,16,0,0,128,7,1,0,0,0,129,131,3,22,11,0,130,129,1,0,0,0,
  	130,131,1,0,0,0,131,133,1,0,0,0,132,134,3,24,12,0,133,132,1,0,0,0,133,
  	134,1,0,0,0,134,138,1,0,0,0,135,137,3,26,13,0,136,135,1,0,0,0,137,140,
  	1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,
  	0,141,143,5,56,0,0,142,141,1,0,0,0,143,144,1,0,0,0,144,142,1,0,0,0,144,
  	145,1,0,0,0,145,9,1,0,0,0,146,147,5,1,0,0,147,151,3,36,18,0,148,150,5,
  	56,0,0,149,148,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,0,151,152,1,0,0,
  	0,152,154,1,0,0,0,153,151,1,0,0,0,154,168,3,0,0,0,155,156,5,8,0,0,156,
  	157,5,1,0,0,157,161,3,36,18,0,158,160,5,56,0,0,159,158,1,0,0,0,160,163,
  	1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,161,1,0,0,
  	0,164,165,3,0,0,0,165,167,1,0,0,0,166,155,1,0,0,0,167,170,1,0,0,0,168,
  	166,1,0,0,0,168,169,1,0,0,0,169,174,1,0,0,0,170,168,1,0,0,0,171,172,5,
  	8,0,0,172,173,5,56,0,0,173,175,3,0,0,0,174,171,1,0,0,0,174,175,1,0,0,
  	0,175,176,1,0,0,0,176,177,7,0,0,0,177,11,1,0,0,0,178,179,5,4,0,0,179,
  	183,3,36,18,0,180,182,5,56,0,0,181,180,1,0,0,0,182,185,1,0,0,0,183,181,
  	1,0,0,0,183,184,1,0,0,0,184,186,1,0,0,0,185,183,1,0,0,0,186,187,3,0,0,
  	0,187,188,7,1,0,0,188,13,1,0,0,0,189,193,5,3,0,0,190,192,5,56,0,0,191,
  	190,1,0,0,0,192,195,1,0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,196,1,
  	0,0,0,195,193,1,0,0,0,196,197,3,0,0,0,197,198,5,4,0,0,198,199,3,36,18,
  	0,199,15,1,0,0,0,200,201,5,5,0,0,201,202,3,68,34,0,202,203,5,6,0,0,203,
  	204,3,36,18,0,204,205,5,7,0,0,205,206,3,36,18,0,206,210,5,3,0,0,207,209,
  	5,56,0,0,208,207,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,
  	0,0,211,213,1,0,0,0,212,210,1,0,0,0,213,214,3,0,0,0,214,215,7,2,0,0,215,
  	17,1,0,0,0,216,217,5,13,0,0,217,19,1,0,0,0,218,219,5,14,0,0,219,21,1,
  	0,0,0,220,221,5,27,0,0,221,23,1,0,0,0,222,224,5,18,0,0,223,222,1,0,0,
  	0,224,225,1,0,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,25,1,0,0,0,227,
  	232,3,28,14,0,228,232,3,66,33,0,229,232,3,70,35,0,230,232,3,6,3,0,231,
  	227,1,0,0,0,231,228,1,0,0,0,231,229,1,0,0,0,231,230,1,0,0,0,232,27,1,
  	0,0,0,233,234,3,30,15,0,234,235,3,32,16,0,235,29,1,0,0,0,236,237,7,3,
  	0,0,237,31,1,0,0,0,238,243,3,58,29,0,239,243,3,68,34,0,240,243,3,36,18,
  	0,241,243,3,34,17,0,242,238,1,0,0,0,242,239,1,0,0,0,242,240,1,0,0,0,242,
  	241,1,0,0,0,243,33,1,0,0,0,244,246,7,4,0,0,245,244,1,0,0,0,245,246,1,
  	0,0,0,246,248,1,0,0,0,247,249,5,18,0,0,248,247,1,0,0,0,249,250,1,0,0,
  	0,250,248,1,0,0,0,250,251,1,0,0,0,251,259,1,0,0,0,252,256,5,23,0,0,253,
  	255,5,18,0,0,254,253,1,0,0,0,255,258,1,0,0,0,256,254,1,0,0,0,256,257,
  	1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,259,252,1,0,0,0,259,260,1,0,0,
  	0,260,271,1,0,0,0,261,263,7,4,0,0,262,261,1,0,0,0,262,263,1,0,0,0,263,
  	264,1,0,0,0,264,266,5,23,0,0,265,267,5,18,0,0,266,265,1,0,0,0,267,268,
  	1,0,0,0,268,266,1,0,0,0,268,269,1,0,0,0,269,271,1,0,0,0,270,245,1,0,0,
  	0,270,262,1,0,0,0,271,35,1,0,0,0,272,273,3,38,19,0,273,37,1,0,0,0,274,
  	275,6,19,-1,0,275,276,3,40,20,0,276,282,1,0,0,0,277,278,10,2,0,0,278,
  	279,5,32,0,0,279,281,3,40,20,0,280,277,1,0,0,0,281,284,1,0,0,0,282,280,
  	1,0,0,0,282,283,1,0,0,0,283,39,1,0,0,0,284,282,1,0,0,0,285,286,6,20,-1,
  	0,286,287,3,42,21,0,287,293,1,0,0,0,288,289,10,2,0,0,289,290,5,31,0,0,
  	290,292,3,42,21,0,291,288,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,293,
  	294,1,0,0,0,294,41,1,0,0,0,295,293,1,0,0,0,296,297,6,21,-1,0,297,298,
  	3,44,22,0,298,304,1,0,0,0,299,300,10,2,0,0,300,301,5,30,0,0,301,303,3,
  	44,22,0,302,299,1,0,0,0,303,306,1,0,0,0,304,302,1,0,0,0,304,305,1,0,0,
  	0,305,43,1,0,0,0,306,304,1,0,0,0,307,308,6,22,-1,0,308,309,3,46,23,0,
  	309,315,1,0,0,0,310,311,10,2,0,0,311,312,7,5,0,0,312,314,3,46,23,0,313,
  	310,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,0,315,316,1,0,0,0,316,45,1,
  	0,0,0,317,315,1,0,0,0,318,319,6,23,-1,0,319,320,3,48,24,0,320,326,1,0,
  	0,0,321,322,10,2,0,0,322,323,7,6,0,0,323,325,3,48,24,0,324,321,1,0,0,
  	0,325,328,1,0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,47,1,0,0,0,328,
  	326,1,0,0,0,329,330,6,24,-1,0,330,331,3,50,25,0,331,337,1,0,0,0,332,333,
  	10,2,0,0,333,334,7,4,0,0,334,336,3,50,25,0,335,332,1,0,0,0,336,339,1,
  	0,0,0,337,335,1,0,0,0,337,338,1,0,0,0,338,49,1,0,0,0,339,337,1,0,0,0,
  	340,341,6,25,-1,0,341,342,3,52,26,0,342,348,1,0,0,0,343,344,10,2,0,0,
  	344,345,7,7,0,0,345,347,3,52,26,0,346,343,1,0,0,0,347,350,1,0,0,0,348,
  	346,1,0,0,0,348,349,1,0,0,0,349,51,1,0,0,0,350,348,1,0,0,0,351,352,3,
  	54,27,0,352,353,5,26,0,0,353,354,3,52,26,0,354,357,1,0,0,0,355,357,3,
  	54,27,0,356,351,1,0,0,0,356,355,1,0,0,0,357,53,1,0,0,0,358,359,5,21,0,
  	0,359,365,3,54,27,0,360,361,5,22,0,0,361,365,3,54,27,0,362,365,3,58,29,
  	0,363,365,3,56,28,0,364,358,1,0,0,0,364,360,1,0,0,0,364,362,1,0,0,0,364,
  	363,1,0,0,0,365,55,1,0,0,0,366,373,3,34,17,0,367,373,3,68,34,0,368,369,
  	5,24,0,0,369,370,3,36,18,0,370,371,5,25,0,0,371,373,1,0,0,0,372,366,1,
  	0,0,0,372,367,1,0,0,0,372,368,1,0,0,0,373,57,1,0,0,0,374,377,3,60,30,
  	0,375,377,3,64,32,0,376,374,1,0,0,0,376,375,1,0,0,0,377,59,1,0,0,0,378,
  	379,3,62,31,0,379,380,3,36,18,0,380,61,1,0,0,0,381,382,7,8,0,0,382,63,
  	1,0,0,0,383,384,5,51,0,0,384,385,3,36,18,0,385,386,5,27,0,0,386,387,3,
  	36,18,0,387,65,1,0,0,0,388,389,5,52,0,0,389,392,3,56,28,0,390,392,5,55,
  	0,0,391,388,1,0,0,0,391,390,1,0,0,0,392,393,1,0,0,0,393,394,5,53,0,0,
  	394,395,3,32,16,0,395,67,1,0,0,0,396,397,5,52,0,0,397,400,3,56,28,0,398,
  	400,5,55,0,0,399,396,1,0,0,0,399,398,1,0,0,0,400,69,1,0,0,0,401,402,5,
  	54,0,0,402,71,1,0,0,0,41,77,85,94,101,104,114,121,130,133,138,144,151,
  	161,168,174,183,193,210,225,231,242,245,250,256,259,262,268,270,282,293,
  	304,315,326,337,348,356,364,372,376,391,399
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

std::vector<tree::TerminalNode *> parser_antlr4::BlockContext::PERCENT() {
  return getTokens(parser_antlr4::PERCENT);
}

tree::TerminalNode* parser_antlr4::BlockContext::PERCENT(size_t i) {
  return getToken(parser_antlr4::PERCENT, i);
}

std::vector<tree::TerminalNode *> parser_antlr4::BlockContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::BlockContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
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
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      match(parser_antlr4::PERCENT);
      setState(73);
      match(parser_antlr4::EOL);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 130604389329920058) != 0)) {
        setState(74);
        statement();
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
      match(parser_antlr4::PERCENT);
      setState(81);
      match(parser_antlr4::EOL);
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(82);
          matchWildcard(); 
        }
        setState(87);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(88);
      match(parser_antlr4::EOL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(parser_antlr4::PERCENT);
      setState(90);
      match(parser_antlr4::EOL);
      setState(94);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(91);
          statement(); 
        }
        setState(96);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      }
      setState(97);
      match(parser_antlr4::EOL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(101);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(98);
          statement(); 
        }
        setState(103);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      }
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
    setState(114);
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
        setState(106);
        line();
        break;
      }

      case parser_antlr4::IF: {
        enterOuterAlt(_localctx, 2);
        setState(107);
        if_statement();
        break;
      }

      case parser_antlr4::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(108);
        while_statement();
        break;
      }

      case parser_antlr4::DO: {
        enterOuterAlt(_localctx, 4);
        setState(109);
        do_while_statement();
        break;
      }

      case parser_antlr4::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(110);
        for_statement();
        break;
      }

      case parser_antlr4::BREAK: {
        enterOuterAlt(_localctx, 6);
        setState(111);
        break_statement();
        break;
      }

      case parser_antlr4::CONTINUE: {
        enterOuterAlt(_localctx, 7);
        setState(112);
        continue_statement();
        break;
      }

      case parser_antlr4::SUBROUTINE: {
        enterOuterAlt(_localctx, 8);
        setState(113);
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
    setState(116);
    match(parser_antlr4::SUBROUTINE);
    setState(117);
    real_value();
    setState(121);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(118);
        match(parser_antlr4::EOL); 
      }
      setState(123);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(124);
    block();
    setState(125);
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
    setState(127);
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
    setState(130);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::SLASH) {
      setState(129);
      block_delete();
    }
    setState(133);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::DIGIT) {
      setState(132);
      line_number();
    }
    setState(138);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 58546795157454848) != 0)) {
      setState(135);
      segment();
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(141);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(144); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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
    setState(146);
    match(parser_antlr4::IF);
    setState(147);
    expression();
    setState(151);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(148);
        match(parser_antlr4::EOL); 
      }
      setState(153);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(154);
    block();
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(155);
        match(parser_antlr4::ELSE);
        setState(156);
        match(parser_antlr4::IF);
        setState(157);
        expression();
        setState(161);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(158);
            match(parser_antlr4::EOL); 
          }
          setState(163);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
        }
        setState(164);
        block(); 
      }
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::ELSE) {
      setState(171);
      match(parser_antlr4::ELSE);
      setState(172);
      match(parser_antlr4::EOL);
      setState(173);
      block();
    }
    setState(176);
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
    setState(178);
    match(parser_antlr4::WHILE);
    setState(179);
    expression();
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(180);
        match(parser_antlr4::EOL); 
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(186);
    block();
    setState(187);
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
    setState(189);
    match(parser_antlr4::DO);
    setState(193);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(190);
        match(parser_antlr4::EOL); 
      }
      setState(195);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(196);
    block();
    setState(197);
    match(parser_antlr4::WHILE);
    setState(198);
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
    setState(200);
    match(parser_antlr4::FOR);
    setState(201);
    parameter_value();
    setState(202);
    match(parser_antlr4::FROM);
    setState(203);
    expression();
    setState(204);
    match(parser_antlr4::TO);
    setState(205);
    expression();
    setState(206);
    match(parser_antlr4::DO);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(207);
        match(parser_antlr4::EOL); 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(213);
    block();
    setState(214);
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
    setState(216);
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
    setState(218);
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
    setState(220);
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
    setState(223); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(222);
      match(parser_antlr4::DIGIT);
      setState(225); 
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
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::LETTER:
      case parser_antlr4::DOLLAR: {
        enterOuterAlt(_localctx, 1);
        setState(227);
        mid_line_word();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(228);
        parameter_setting();
        break;
      }

      case parser_antlr4::COMMENT: {
        enterOuterAlt(_localctx, 3);
        setState(229);
        comment();
        break;
      }

      case parser_antlr4::M99: {
        enterOuterAlt(_localctx, 4);
        setState(230);
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
    setState(233);
    mid_line_letter();
    setState(234);
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
    setState(236);
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
    setState(242);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(238);
      unary_combo();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(239);
      parameter_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(240);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(241);
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
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(245);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(244);
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
      setState(248); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(247);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(250); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(259);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        setState(252);
        match(parser_antlr4::DOT);
        setState(256);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(253);
            match(parser_antlr4::DIGIT); 
          }
          setState(258);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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
      setState(262);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(261);
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
      setState(264);
      match(parser_antlr4::DOT);
      setState(266); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(265);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(268); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
    setState(272);
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
    setState(275);
    logical_xor_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(282);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_or_expression);
        setState(277);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(278);
        match(parser_antlr4::NON_EXCLUSIVE_OR);
        setState(279);
        logical_xor_expression(0); 
      }
      setState(284);
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
    setState(286);
    logical_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(293);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_xor_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_xor_expression);
        setState(288);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(289);
        match(parser_antlr4::EXCLUSIVE_OR);
        setState(290);
        logical_and_expression(0); 
      }
      setState(295);
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
    setState(297);
    equality_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(304);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_and_expression);
        setState(299);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(300);
        match(parser_antlr4::LOGICAL_AND);
        setState(301);
        equality_expression(0); 
      }
      setState(306);
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
    setState(308);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(315);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
        setState(310);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(311);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::EQ

        || _la == parser_antlr4::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(312);
        relational_expression(0); 
      }
      setState(317);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
    setState(319);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
        setState(321);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(322);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 515396075520) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(323);
        additive_expression(0); 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
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
    setState(330);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(337);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
        setState(332);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(333);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(334);
        multiplicative_expression(0); 
      }
      setState(339);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
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
    setState(341);
    power_expression();
    _ctx->stop = _input->LT(-1);
    setState(348);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
        setState(343);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(344);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 939524096) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(345);
        power_expression(); 
      }
      setState(350);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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
    setState(356);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(351);
      unary_expression();
      setState(352);
      match(parser_antlr4::POWER);
      setState(353);
      power_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(355);
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
    setState(364);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(358);
      match(parser_antlr4::PLUS);
      setState(359);
      unary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(360);
      match(parser_antlr4::MINUS);
      setState(361);
      unary_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(362);
      unary_combo();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(363);
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
    setState(372);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::DIGIT:
      case parser_antlr4::PLUS:
      case parser_antlr4::MINUS:
      case parser_antlr4::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(366);
        real_number();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(367);
        parameter_value();
        break;
      }

      case parser_antlr4::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(368);
        match(parser_antlr4::LEFT_BRACKET);
        setState(369);
        expression();
        setState(370);
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
    setState(376);
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
        setState(374);
        ordinary_unary_combo();
        break;
      }

      case parser_antlr4::ARC_TANGENT: {
        enterOuterAlt(_localctx, 2);
        setState(375);
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
    setState(378);
    ordinary_unary_operation();
    setState(379);
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
    setState(381);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2251250057871360) != 0))) {
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
    setState(383);
    match(parser_antlr4::ARC_TANGENT);
    setState(384);
    expression();
    setState(385);
    match(parser_antlr4::SLASH);
    setState(386);
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
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        setState(388);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(389);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        setState(390);
        match(parser_antlr4::NAMED_PARAMETER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(393);
    match(parser_antlr4::EQUAL_SIGN);
    setState(394);
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
    setState(399);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        enterOuterAlt(_localctx, 1);
        setState(396);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(397);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(398);
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
    setState(401);
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
