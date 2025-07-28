
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
      "block", "statement", "subroutine", "m99", "line", "import_statement", 
      "if_statement", "while_statement", "do_while_statement", "for_statement", 
      "break_statement", "continue_statement", "block_delete", "line_number", 
      "segment", "mid_line_word", "mid_line_letter", "real_value", "real_number", 
      "expression", "logical_or_expression", "logical_xor_expression", "logical_and_expression", 
      "equality_expression", "relational_expression", "additive_expression", 
      "multiplicative_expression", "power_expression", "unary_expression", 
      "primary", "unary_combo", "ordinary_unary_combo", "ordinary_unary_operation", 
      "arc_tangent_combo", "parameter_setting", "parameter_value", "comment"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "'%'", "", "", "'$'", "'+'", "'-'", "'.'", "'['", "']'", "'**'", 
      "'/'", "", "'*'", "", "", "", "", "", "'<'", "'<='", "'>'", "'>='", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "'#'", "'='"
    },
    std::vector<std::string>{
      "", "IF", "THEN", "DO", "WHILE", "FOR", "FROM", "TO", "ELSE", "END", 
      "ENDIF", "ENDWHILE", "ENDFOR", "BREAK", "CONTINUE", "IMPORT", "FILENAME", 
      "SUBROUTINE", "M99", "PERCENT", "DIGIT", "LETTER", "DOLLAR", "PLUS", 
      "MINUS", "DOT", "LEFT_BRACKET", "RIGHT_BRACKET", "POWER", "SLASH", 
      "MODULO", "TIMES", "LOGICAL_AND", "EXCLUSIVE_OR", "NON_EXCLUSIVE_OR", 
      "EQ", "NE", "LT", "LE", "GT", "GE", "ABSOLUTE_VALUE", "ARC_COSINE", 
      "ARC_SINE", "COSINE", "E_RAISED_TO", "FIX_DOWN", "FIX_UP", "NATURAL_LOG_OF", 
      "ROUND_OPERATION", "SINE", "SQUARE_ROOT", "TANGENT", "ARC_TANGENT", 
      "PARAMETER_SIGN", "EQUAL_SIGN", "COMMENT", "NAMED_PARAMETER", "EOL", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,431,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,1,0,1,0,1,0,1,0,5,0,79,8,0,10,0,12,0,82,9,0,1,0,1,0,1,0,
  	5,0,87,8,0,10,0,12,0,90,9,0,1,0,1,0,1,0,1,0,1,0,5,0,97,8,0,10,0,12,0,
  	100,9,0,1,0,1,0,5,0,104,8,0,10,0,12,0,107,9,0,3,0,109,8,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,3,1,120,8,1,1,2,1,2,1,2,5,2,125,8,2,10,2,12,2,
  	128,9,2,1,2,1,2,1,2,1,3,1,3,1,4,3,4,136,8,4,1,4,3,4,139,8,4,1,4,5,4,142,
  	8,4,10,4,12,4,145,9,4,1,4,4,4,148,8,4,11,4,12,4,149,1,5,1,5,1,5,4,5,155,
  	8,5,11,5,12,5,156,1,6,1,6,1,6,5,6,162,8,6,10,6,12,6,165,9,6,1,6,1,6,1,
  	6,1,6,1,6,5,6,172,8,6,10,6,12,6,175,9,6,1,6,1,6,5,6,179,8,6,10,6,12,6,
  	182,9,6,1,6,1,6,1,6,3,6,187,8,6,1,6,1,6,4,6,191,8,6,11,6,12,6,192,1,7,
  	1,7,1,7,5,7,198,8,7,10,7,12,7,201,9,7,1,7,1,7,1,7,4,7,206,8,7,11,7,12,
  	7,207,1,8,1,8,5,8,212,8,8,10,8,12,8,215,9,8,1,8,1,8,1,8,1,8,1,8,4,8,222,
  	8,8,11,8,12,8,223,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,233,8,9,10,9,12,9,236,
  	9,9,1,9,1,9,1,9,4,9,241,8,9,11,9,12,9,242,1,10,1,10,1,11,1,11,1,12,1,
  	12,1,13,4,13,252,8,13,11,13,12,13,253,1,14,1,14,1,14,3,14,259,8,14,1,
  	15,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,17,3,17,270,8,17,1,18,3,18,273,
  	8,18,1,18,4,18,276,8,18,11,18,12,18,277,1,18,1,18,5,18,282,8,18,10,18,
  	12,18,285,9,18,3,18,287,8,18,1,18,3,18,290,8,18,1,18,1,18,4,18,294,8,
  	18,11,18,12,18,295,3,18,298,8,18,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,
  	20,5,20,308,8,20,10,20,12,20,311,9,20,1,21,1,21,1,21,1,21,1,21,1,21,5,
  	21,319,8,21,10,21,12,21,322,9,21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,330,
  	8,22,10,22,12,22,333,9,22,1,23,1,23,1,23,1,23,1,23,1,23,5,23,341,8,23,
  	10,23,12,23,344,9,23,1,24,1,24,1,24,1,24,1,24,1,24,5,24,352,8,24,10,24,
  	12,24,355,9,24,1,25,1,25,1,25,1,25,1,25,1,25,5,25,363,8,25,10,25,12,25,
  	366,9,25,1,26,1,26,1,26,1,26,1,26,1,26,5,26,374,8,26,10,26,12,26,377,
  	9,26,1,27,1,27,1,27,1,27,1,27,3,27,384,8,27,1,28,1,28,1,28,1,28,1,28,
  	1,28,3,28,392,8,28,1,29,1,29,1,29,1,29,1,29,1,29,3,29,400,8,29,1,30,1,
  	30,3,30,404,8,30,1,31,1,31,1,31,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,
  	34,1,34,1,34,3,34,419,8,34,1,34,1,34,1,34,1,35,1,35,1,35,3,35,427,8,35,
  	1,36,1,36,1,36,1,88,7,40,42,44,46,48,50,52,37,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,
  	66,68,70,72,0,9,1,0,9,10,2,0,9,9,11,11,2,0,9,9,12,12,1,0,21,22,1,0,23,
  	24,1,0,35,36,1,0,37,40,1,0,29,31,1,0,41,52,456,0,108,1,0,0,0,2,119,1,
  	0,0,0,4,121,1,0,0,0,6,132,1,0,0,0,8,135,1,0,0,0,10,151,1,0,0,0,12,158,
  	1,0,0,0,14,194,1,0,0,0,16,209,1,0,0,0,18,225,1,0,0,0,20,244,1,0,0,0,22,
  	246,1,0,0,0,24,248,1,0,0,0,26,251,1,0,0,0,28,258,1,0,0,0,30,260,1,0,0,
  	0,32,263,1,0,0,0,34,269,1,0,0,0,36,297,1,0,0,0,38,299,1,0,0,0,40,301,
  	1,0,0,0,42,312,1,0,0,0,44,323,1,0,0,0,46,334,1,0,0,0,48,345,1,0,0,0,50,
  	356,1,0,0,0,52,367,1,0,0,0,54,383,1,0,0,0,56,391,1,0,0,0,58,399,1,0,0,
  	0,60,403,1,0,0,0,62,405,1,0,0,0,64,408,1,0,0,0,66,410,1,0,0,0,68,418,
  	1,0,0,0,70,426,1,0,0,0,72,428,1,0,0,0,74,75,5,19,0,0,75,80,5,58,0,0,76,
  	79,3,2,1,0,77,79,5,58,0,0,78,76,1,0,0,0,78,77,1,0,0,0,79,82,1,0,0,0,80,
  	78,1,0,0,0,80,81,1,0,0,0,81,83,1,0,0,0,82,80,1,0,0,0,83,84,5,19,0,0,84,
  	88,5,58,0,0,85,87,9,0,0,0,86,85,1,0,0,0,87,90,1,0,0,0,88,89,1,0,0,0,88,
  	86,1,0,0,0,89,91,1,0,0,0,90,88,1,0,0,0,91,109,5,58,0,0,92,93,5,19,0,0,
  	93,98,5,58,0,0,94,97,3,2,1,0,95,97,5,58,0,0,96,94,1,0,0,0,96,95,1,0,0,
  	0,97,100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,109,1,0,0,0,100,98,1,
  	0,0,0,101,104,3,2,1,0,102,104,5,58,0,0,103,101,1,0,0,0,103,102,1,0,0,
  	0,104,107,1,0,0,0,105,103,1,0,0,0,105,106,1,0,0,0,106,109,1,0,0,0,107,
  	105,1,0,0,0,108,74,1,0,0,0,108,92,1,0,0,0,108,105,1,0,0,0,109,1,1,0,0,
  	0,110,120,3,8,4,0,111,120,3,10,5,0,112,120,3,12,6,0,113,120,3,14,7,0,
  	114,120,3,16,8,0,115,120,3,18,9,0,116,120,3,20,10,0,117,120,3,22,11,0,
  	118,120,3,4,2,0,119,110,1,0,0,0,119,111,1,0,0,0,119,112,1,0,0,0,119,113,
  	1,0,0,0,119,114,1,0,0,0,119,115,1,0,0,0,119,116,1,0,0,0,119,117,1,0,0,
  	0,119,118,1,0,0,0,120,3,1,0,0,0,121,122,5,17,0,0,122,126,3,34,17,0,123,
  	125,5,58,0,0,124,123,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,126,127,
  	1,0,0,0,127,129,1,0,0,0,128,126,1,0,0,0,129,130,3,0,0,0,130,131,3,6,3,
  	0,131,5,1,0,0,0,132,133,5,18,0,0,133,7,1,0,0,0,134,136,3,24,12,0,135,
  	134,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,139,3,26,13,0,138,137,
  	1,0,0,0,138,139,1,0,0,0,139,143,1,0,0,0,140,142,3,28,14,0,141,140,1,0,
  	0,0,142,145,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,147,1,0,0,0,145,
  	143,1,0,0,0,146,148,5,58,0,0,147,146,1,0,0,0,148,149,1,0,0,0,149,147,
  	1,0,0,0,149,150,1,0,0,0,150,9,1,0,0,0,151,152,5,15,0,0,152,154,5,16,0,
  	0,153,155,5,58,0,0,154,153,1,0,0,0,155,156,1,0,0,0,156,154,1,0,0,0,156,
  	157,1,0,0,0,157,11,1,0,0,0,158,159,5,1,0,0,159,163,3,38,19,0,160,162,
  	5,58,0,0,161,160,1,0,0,0,162,165,1,0,0,0,163,161,1,0,0,0,163,164,1,0,
  	0,0,164,166,1,0,0,0,165,163,1,0,0,0,166,180,3,0,0,0,167,168,5,8,0,0,168,
  	169,5,1,0,0,169,173,3,38,19,0,170,172,5,58,0,0,171,170,1,0,0,0,172,175,
  	1,0,0,0,173,171,1,0,0,0,173,174,1,0,0,0,174,176,1,0,0,0,175,173,1,0,0,
  	0,176,177,3,0,0,0,177,179,1,0,0,0,178,167,1,0,0,0,179,182,1,0,0,0,180,
  	178,1,0,0,0,180,181,1,0,0,0,181,186,1,0,0,0,182,180,1,0,0,0,183,184,5,
  	8,0,0,184,185,5,58,0,0,185,187,3,0,0,0,186,183,1,0,0,0,186,187,1,0,0,
  	0,187,188,1,0,0,0,188,190,7,0,0,0,189,191,5,58,0,0,190,189,1,0,0,0,191,
  	192,1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,13,1,0,0,0,194,195,5,
  	4,0,0,195,199,3,38,19,0,196,198,5,58,0,0,197,196,1,0,0,0,198,201,1,0,
  	0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,202,1,0,0,0,201,199,1,0,0,0,202,
  	203,3,0,0,0,203,205,7,1,0,0,204,206,5,58,0,0,205,204,1,0,0,0,206,207,
  	1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,15,1,0,0,0,209,213,5,3,0,
  	0,210,212,5,58,0,0,211,210,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,
  	214,1,0,0,0,214,216,1,0,0,0,215,213,1,0,0,0,216,217,3,0,0,0,217,218,5,
  	4,0,0,218,219,3,38,19,0,219,221,7,1,0,0,220,222,5,58,0,0,221,220,1,0,
  	0,0,222,223,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,17,1,0,0,0,225,
  	226,5,5,0,0,226,227,3,70,35,0,227,228,5,6,0,0,228,229,3,38,19,0,229,230,
  	5,7,0,0,230,234,3,38,19,0,231,233,5,58,0,0,232,231,1,0,0,0,233,236,1,
  	0,0,0,234,232,1,0,0,0,234,235,1,0,0,0,235,237,1,0,0,0,236,234,1,0,0,0,
  	237,238,3,0,0,0,238,240,7,2,0,0,239,241,5,58,0,0,240,239,1,0,0,0,241,
  	242,1,0,0,0,242,240,1,0,0,0,242,243,1,0,0,0,243,19,1,0,0,0,244,245,5,
  	13,0,0,245,21,1,0,0,0,246,247,5,14,0,0,247,23,1,0,0,0,248,249,5,29,0,
  	0,249,25,1,0,0,0,250,252,5,20,0,0,251,250,1,0,0,0,252,253,1,0,0,0,253,
  	251,1,0,0,0,253,254,1,0,0,0,254,27,1,0,0,0,255,259,3,30,15,0,256,259,
  	3,68,34,0,257,259,3,72,36,0,258,255,1,0,0,0,258,256,1,0,0,0,258,257,1,
  	0,0,0,259,29,1,0,0,0,260,261,3,32,16,0,261,262,3,34,17,0,262,31,1,0,0,
  	0,263,264,7,3,0,0,264,33,1,0,0,0,265,270,3,60,30,0,266,270,3,70,35,0,
  	267,270,3,38,19,0,268,270,3,36,18,0,269,265,1,0,0,0,269,266,1,0,0,0,269,
  	267,1,0,0,0,269,268,1,0,0,0,270,35,1,0,0,0,271,273,7,4,0,0,272,271,1,
  	0,0,0,272,273,1,0,0,0,273,275,1,0,0,0,274,276,5,20,0,0,275,274,1,0,0,
  	0,276,277,1,0,0,0,277,275,1,0,0,0,277,278,1,0,0,0,278,286,1,0,0,0,279,
  	283,5,25,0,0,280,282,5,20,0,0,281,280,1,0,0,0,282,285,1,0,0,0,283,281,
  	1,0,0,0,283,284,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,286,279,1,0,0,
  	0,286,287,1,0,0,0,287,298,1,0,0,0,288,290,7,4,0,0,289,288,1,0,0,0,289,
  	290,1,0,0,0,290,291,1,0,0,0,291,293,5,25,0,0,292,294,5,20,0,0,293,292,
  	1,0,0,0,294,295,1,0,0,0,295,293,1,0,0,0,295,296,1,0,0,0,296,298,1,0,0,
  	0,297,272,1,0,0,0,297,289,1,0,0,0,298,37,1,0,0,0,299,300,3,40,20,0,300,
  	39,1,0,0,0,301,302,6,20,-1,0,302,303,3,42,21,0,303,309,1,0,0,0,304,305,
  	10,2,0,0,305,306,5,34,0,0,306,308,3,42,21,0,307,304,1,0,0,0,308,311,1,
  	0,0,0,309,307,1,0,0,0,309,310,1,0,0,0,310,41,1,0,0,0,311,309,1,0,0,0,
  	312,313,6,21,-1,0,313,314,3,44,22,0,314,320,1,0,0,0,315,316,10,2,0,0,
  	316,317,5,33,0,0,317,319,3,44,22,0,318,315,1,0,0,0,319,322,1,0,0,0,320,
  	318,1,0,0,0,320,321,1,0,0,0,321,43,1,0,0,0,322,320,1,0,0,0,323,324,6,
  	22,-1,0,324,325,3,46,23,0,325,331,1,0,0,0,326,327,10,2,0,0,327,328,5,
  	32,0,0,328,330,3,46,23,0,329,326,1,0,0,0,330,333,1,0,0,0,331,329,1,0,
  	0,0,331,332,1,0,0,0,332,45,1,0,0,0,333,331,1,0,0,0,334,335,6,23,-1,0,
  	335,336,3,48,24,0,336,342,1,0,0,0,337,338,10,2,0,0,338,339,7,5,0,0,339,
  	341,3,48,24,0,340,337,1,0,0,0,341,344,1,0,0,0,342,340,1,0,0,0,342,343,
  	1,0,0,0,343,47,1,0,0,0,344,342,1,0,0,0,345,346,6,24,-1,0,346,347,3,50,
  	25,0,347,353,1,0,0,0,348,349,10,2,0,0,349,350,7,6,0,0,350,352,3,50,25,
  	0,351,348,1,0,0,0,352,355,1,0,0,0,353,351,1,0,0,0,353,354,1,0,0,0,354,
  	49,1,0,0,0,355,353,1,0,0,0,356,357,6,25,-1,0,357,358,3,52,26,0,358,364,
  	1,0,0,0,359,360,10,2,0,0,360,361,7,4,0,0,361,363,3,52,26,0,362,359,1,
  	0,0,0,363,366,1,0,0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,51,1,0,0,0,
  	366,364,1,0,0,0,367,368,6,26,-1,0,368,369,3,54,27,0,369,375,1,0,0,0,370,
  	371,10,2,0,0,371,372,7,7,0,0,372,374,3,54,27,0,373,370,1,0,0,0,374,377,
  	1,0,0,0,375,373,1,0,0,0,375,376,1,0,0,0,376,53,1,0,0,0,377,375,1,0,0,
  	0,378,379,3,56,28,0,379,380,5,28,0,0,380,381,3,54,27,0,381,384,1,0,0,
  	0,382,384,3,56,28,0,383,378,1,0,0,0,383,382,1,0,0,0,384,55,1,0,0,0,385,
  	386,5,23,0,0,386,392,3,56,28,0,387,388,5,24,0,0,388,392,3,56,28,0,389,
  	392,3,60,30,0,390,392,3,58,29,0,391,385,1,0,0,0,391,387,1,0,0,0,391,389,
  	1,0,0,0,391,390,1,0,0,0,392,57,1,0,0,0,393,400,3,36,18,0,394,400,3,70,
  	35,0,395,396,5,26,0,0,396,397,3,38,19,0,397,398,5,27,0,0,398,400,1,0,
  	0,0,399,393,1,0,0,0,399,394,1,0,0,0,399,395,1,0,0,0,400,59,1,0,0,0,401,
  	404,3,62,31,0,402,404,3,66,33,0,403,401,1,0,0,0,403,402,1,0,0,0,404,61,
  	1,0,0,0,405,406,3,64,32,0,406,407,3,38,19,0,407,63,1,0,0,0,408,409,7,
  	8,0,0,409,65,1,0,0,0,410,411,5,53,0,0,411,412,3,38,19,0,412,413,5,29,
  	0,0,413,414,3,38,19,0,414,67,1,0,0,0,415,416,5,54,0,0,416,419,3,58,29,
  	0,417,419,5,57,0,0,418,415,1,0,0,0,418,417,1,0,0,0,419,420,1,0,0,0,420,
  	421,5,55,0,0,421,422,3,34,17,0,422,69,1,0,0,0,423,424,5,54,0,0,424,427,
  	3,58,29,0,425,427,5,57,0,0,426,423,1,0,0,0,426,425,1,0,0,0,427,71,1,0,
  	0,0,428,429,5,56,0,0,429,73,1,0,0,0,49,78,80,88,96,98,103,105,108,119,
  	126,135,138,143,149,156,163,173,180,186,192,199,207,213,223,234,242,253,
  	258,269,272,277,283,286,289,295,297,309,320,331,342,353,364,375,383,391,
  	399,403,418,426
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
    setState(108);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(74);
      match(parser_antlr4::PERCENT);
      setState(75);
      match(parser_antlr4::EOL);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 522417557319376954) != 0)) {
        setState(78);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          setState(76);
          statement();
          break;
        }

        case 2: {
          setState(77);
          match(parser_antlr4::EOL);
          break;
        }

        default:
          break;
        }
        setState(82);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(83);
      match(parser_antlr4::PERCENT);
      setState(84);
      match(parser_antlr4::EOL);
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1 + 1) {
          setState(85);
          matchWildcard(); 
        }
        setState(90);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      }
      setState(91);
      match(parser_antlr4::EOL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      match(parser_antlr4::PERCENT);
      setState(93);
      match(parser_antlr4::EOL);
      setState(98);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(96);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
          case 1: {
            setState(94);
            statement();
            break;
          }

          case 2: {
            setState(95);
            match(parser_antlr4::EOL);
            break;
          }

          default:
            break;
          } 
        }
        setState(100);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(105);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(103);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
          case 1: {
            setState(101);
            statement();
            break;
          }

          case 2: {
            setState(102);
            match(parser_antlr4::EOL);
            break;
          }

          default:
            break;
          } 
        }
        setState(107);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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

parser_antlr4::Import_statementContext* parser_antlr4::StatementContext::import_statement() {
  return getRuleContext<parser_antlr4::Import_statementContext>(0);
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
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::DIGIT:
      case parser_antlr4::LETTER:
      case parser_antlr4::DOLLAR:
      case parser_antlr4::SLASH:
      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::COMMENT:
      case parser_antlr4::NAMED_PARAMETER:
      case parser_antlr4::EOL: {
        enterOuterAlt(_localctx, 1);
        setState(110);
        line();
        break;
      }

      case parser_antlr4::IMPORT: {
        enterOuterAlt(_localctx, 2);
        setState(111);
        import_statement();
        break;
      }

      case parser_antlr4::IF: {
        enterOuterAlt(_localctx, 3);
        setState(112);
        if_statement();
        break;
      }

      case parser_antlr4::WHILE: {
        enterOuterAlt(_localctx, 4);
        setState(113);
        while_statement();
        break;
      }

      case parser_antlr4::DO: {
        enterOuterAlt(_localctx, 5);
        setState(114);
        do_while_statement();
        break;
      }

      case parser_antlr4::FOR: {
        enterOuterAlt(_localctx, 6);
        setState(115);
        for_statement();
        break;
      }

      case parser_antlr4::BREAK: {
        enterOuterAlt(_localctx, 7);
        setState(116);
        break_statement();
        break;
      }

      case parser_antlr4::CONTINUE: {
        enterOuterAlt(_localctx, 8);
        setState(117);
        continue_statement();
        break;
      }

      case parser_antlr4::SUBROUTINE: {
        enterOuterAlt(_localctx, 9);
        setState(118);
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
    setState(121);
    match(parser_antlr4::SUBROUTINE);
    setState(122);
    real_value();
    setState(126);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(123);
        match(parser_antlr4::EOL); 
      }
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(129);
    block();
    setState(130);
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
    setState(132);
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
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::SLASH) {
      setState(134);
      block_delete();
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::DIGIT) {
      setState(137);
      line_number();
    }
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 234187180629557248) != 0)) {
      setState(140);
      segment();
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(146);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(149); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_statementContext ------------------------------------------------------------------

parser_antlr4::Import_statementContext::Import_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* parser_antlr4::Import_statementContext::IMPORT() {
  return getToken(parser_antlr4::IMPORT, 0);
}

tree::TerminalNode* parser_antlr4::Import_statementContext::FILENAME() {
  return getToken(parser_antlr4::FILENAME, 0);
}

std::vector<tree::TerminalNode *> parser_antlr4::Import_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::Import_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}


size_t parser_antlr4::Import_statementContext::getRuleIndex() const {
  return parser_antlr4::RuleImport_statement;
}

void parser_antlr4::Import_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_statement(this);
}

void parser_antlr4::Import_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_statement(this);
}


std::any parser_antlr4::Import_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitImport_statement(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Import_statementContext* parser_antlr4::import_statement() {
  Import_statementContext *_localctx = _tracker.createInstance<Import_statementContext>(_ctx, getState());
  enterRule(_localctx, 10, parser_antlr4::RuleImport_statement);

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
    setState(151);
    match(parser_antlr4::IMPORT);
    setState(152);
    match(parser_antlr4::FILENAME);
    setState(154); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(153);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(156); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
  enterRule(_localctx, 12, parser_antlr4::RuleIf_statement);
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
    setState(158);
    match(parser_antlr4::IF);
    setState(159);
    expression();
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        match(parser_antlr4::EOL); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(166);
    block();
    setState(180);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(167);
        match(parser_antlr4::ELSE);
        setState(168);
        match(parser_antlr4::IF);
        setState(169);
        expression();
        setState(173);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(170);
            match(parser_antlr4::EOL); 
          }
          setState(175);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        }
        setState(176);
        block(); 
      }
      setState(182);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::ELSE) {
      setState(183);
      match(parser_antlr4::ELSE);
      setState(184);
      match(parser_antlr4::EOL);
      setState(185);
      block();
    }
    setState(188);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDIF)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(190); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(189);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(192); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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
  enterRule(_localctx, 14, parser_antlr4::RuleWhile_statement);
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
    setState(194);
    match(parser_antlr4::WHILE);
    setState(195);
    expression();
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(196);
        match(parser_antlr4::EOL); 
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(202);
    block();
    setState(203);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDWHILE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(205); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(204);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(207); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

tree::TerminalNode* parser_antlr4::Do_while_statementContext::END() {
  return getToken(parser_antlr4::END, 0);
}

tree::TerminalNode* parser_antlr4::Do_while_statementContext::ENDWHILE() {
  return getToken(parser_antlr4::ENDWHILE, 0);
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
  enterRule(_localctx, 16, parser_antlr4::RuleDo_while_statement);
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
    setState(209);
    match(parser_antlr4::DO);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(210);
        match(parser_antlr4::EOL); 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(216);
    block();
    setState(217);
    match(parser_antlr4::WHILE);
    setState(218);
    expression();
    setState(219);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDWHILE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(221); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(220);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(223); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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
  enterRule(_localctx, 18, parser_antlr4::RuleFor_statement);
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
    setState(225);
    match(parser_antlr4::FOR);
    setState(226);
    parameter_value();
    setState(227);
    match(parser_antlr4::FROM);
    setState(228);
    expression();
    setState(229);
    match(parser_antlr4::TO);
    setState(230);
    expression();
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(231);
        match(parser_antlr4::EOL); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
    setState(237);
    block();
    setState(238);
    _la = _input->LA(1);
    if (!(_la == parser_antlr4::END

    || _la == parser_antlr4::ENDFOR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(240); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(239);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(242); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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
  enterRule(_localctx, 20, parser_antlr4::RuleBreak_statement);

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
  enterRule(_localctx, 22, parser_antlr4::RuleContinue_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
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
  enterRule(_localctx, 24, parser_antlr4::RuleBlock_delete);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
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
  enterRule(_localctx, 26, parser_antlr4::RuleLine_number);
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
    setState(251); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(250);
      match(parser_antlr4::DIGIT);
      setState(253); 
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
  enterRule(_localctx, 28, parser_antlr4::RuleSegment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(258);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::LETTER:
      case parser_antlr4::DOLLAR: {
        enterOuterAlt(_localctx, 1);
        setState(255);
        mid_line_word();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(256);
        parameter_setting();
        break;
      }

      case parser_antlr4::COMMENT: {
        enterOuterAlt(_localctx, 3);
        setState(257);
        comment();
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
  enterRule(_localctx, 30, parser_antlr4::RuleMid_line_word);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    mid_line_letter();
    setState(261);
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
  enterRule(_localctx, 32, parser_antlr4::RuleMid_line_letter);
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
    setState(263);
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
  enterRule(_localctx, 34, parser_antlr4::RuleReal_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(265);
      unary_combo();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(266);
      parameter_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(267);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(268);
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
  enterRule(_localctx, 36, parser_antlr4::RuleReal_number);
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
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(271);
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
      setState(275); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(274);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(277); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(286);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
      case 1: {
        setState(279);
        match(parser_antlr4::DOT);
        setState(283);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(280);
            match(parser_antlr4::DIGIT); 
          }
          setState(285);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
      setState(289);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(288);
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
      setState(291);
      match(parser_antlr4::DOT);
      setState(293); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(292);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(295); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
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
  enterRule(_localctx, 38, parser_antlr4::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, parser_antlr4::RuleLogical_or_expression, precedence);

    

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
    logical_xor_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_or_expression);
        setState(304);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(305);
        match(parser_antlr4::NON_EXCLUSIVE_OR);
        setState(306);
        logical_xor_expression(0); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
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
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, parser_antlr4::RuleLogical_xor_expression, precedence);

    

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
    logical_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(320);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_xor_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_xor_expression);
        setState(315);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(316);
        match(parser_antlr4::EXCLUSIVE_OR);
        setState(317);
        logical_and_expression(0); 
      }
      setState(322);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, parser_antlr4::RuleLogical_and_expression, precedence);

    

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
    setState(324);
    equality_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(331);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_and_expression);
        setState(326);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(327);
        match(parser_antlr4::LOGICAL_AND);
        setState(328);
        equality_expression(0); 
      }
      setState(333);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, parser_antlr4::RuleEquality_expression, precedence);

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
    setState(335);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(342);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
        setState(337);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(338);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::EQ

        || _la == parser_antlr4::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(339);
        relational_expression(0); 
      }
      setState(344);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
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
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, parser_antlr4::RuleRelational_expression, precedence);

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
    setState(346);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(353);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
        setState(348);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(349);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2061584302080) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(350);
        additive_expression(0); 
      }
      setState(355);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
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
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, parser_antlr4::RuleAdditive_expression, precedence);

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
    setState(357);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
        setState(359);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(360);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(361);
        multiplicative_expression(0); 
      }
      setState(366);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
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
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, parser_antlr4::RuleMultiplicative_expression, precedence);

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
    setState(368);
    power_expression();
    _ctx->stop = _input->LT(-1);
    setState(375);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
        setState(370);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(371);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 3758096384) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(372);
        power_expression(); 
      }
      setState(377);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
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
  enterRule(_localctx, 54, parser_antlr4::RulePower_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(383);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(378);
      unary_expression();
      setState(379);
      match(parser_antlr4::POWER);
      setState(380);
      power_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(382);
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
  enterRule(_localctx, 56, parser_antlr4::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(391);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(385);
      match(parser_antlr4::PLUS);
      setState(386);
      unary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(387);
      match(parser_antlr4::MINUS);
      setState(388);
      unary_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(389);
      unary_combo();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(390);
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
  enterRule(_localctx, 58, parser_antlr4::RulePrimary);

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
      case parser_antlr4::DIGIT:
      case parser_antlr4::PLUS:
      case parser_antlr4::MINUS:
      case parser_antlr4::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(393);
        real_number();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(394);
        parameter_value();
        break;
      }

      case parser_antlr4::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(395);
        match(parser_antlr4::LEFT_BRACKET);
        setState(396);
        expression();
        setState(397);
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
  enterRule(_localctx, 60, parser_antlr4::RuleUnary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
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
        setState(401);
        ordinary_unary_combo();
        break;
      }

      case parser_antlr4::ARC_TANGENT: {
        enterOuterAlt(_localctx, 2);
        setState(402);
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
  enterRule(_localctx, 62, parser_antlr4::RuleOrdinary_unary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    ordinary_unary_operation();
    setState(406);
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
  enterRule(_localctx, 64, parser_antlr4::RuleOrdinary_unary_operation);
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
    setState(408);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9005000231485440) != 0))) {
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
  enterRule(_localctx, 66, parser_antlr4::RuleArc_tangent_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    match(parser_antlr4::ARC_TANGENT);
    setState(411);
    expression();
    setState(412);
    match(parser_antlr4::SLASH);
    setState(413);
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
  enterRule(_localctx, 68, parser_antlr4::RuleParameter_setting);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        setState(415);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(416);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        setState(417);
        match(parser_antlr4::NAMED_PARAMETER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(420);
    match(parser_antlr4::EQUAL_SIGN);
    setState(421);
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
  enterRule(_localctx, 70, parser_antlr4::RuleParameter_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::PARAMETER_SIGN: {
        enterOuterAlt(_localctx, 1);
        setState(423);
        match(parser_antlr4::PARAMETER_SIGN);
        setState(424);
        primary();
        break;
      }

      case parser_antlr4::NAMED_PARAMETER: {
        enterOuterAlt(_localctx, 2);
        setState(425);
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
  enterRule(_localctx, 72, parser_antlr4::RuleComment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
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
    case 20: return logical_or_expressionSempred(antlrcpp::downCast<Logical_or_expressionContext *>(context), predicateIndex);
    case 21: return logical_xor_expressionSempred(antlrcpp::downCast<Logical_xor_expressionContext *>(context), predicateIndex);
    case 22: return logical_and_expressionSempred(antlrcpp::downCast<Logical_and_expressionContext *>(context), predicateIndex);
    case 23: return equality_expressionSempred(antlrcpp::downCast<Equality_expressionContext *>(context), predicateIndex);
    case 24: return relational_expressionSempred(antlrcpp::downCast<Relational_expressionContext *>(context), predicateIndex);
    case 25: return additive_expressionSempred(antlrcpp::downCast<Additive_expressionContext *>(context), predicateIndex);
    case 26: return multiplicative_expressionSempred(antlrcpp::downCast<Multiplicative_expressionContext *>(context), predicateIndex);

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
