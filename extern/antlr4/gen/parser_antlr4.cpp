
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
      "block", "statement", "line", "if_statement", "while_statement", "do_while_statement", 
      "for_statement", "break_statement", "continue_statement", "block_delete", 
      "line_number", "segment", "mid_line_word", "mid_line_letter", "real_value", 
      "real_number", "expression", "logical_or_expression", "logical_xor_expression", 
      "logical_and_expression", "equality_expression", "relational_expression", 
      "additive_expression", "multiplicative_expression", "power_expression", 
      "unary_expression", "primary", "unary_combo", "ordinary_unary_combo", 
      "ordinary_unary_operation", "arc_tangent_combo", "parameter_setting", 
      "parameter_value", "parameter_index", "comment"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'+'", "'-'", 
      "'.'", "'['", "']'", "'**'", "'/'", "", "'*'", "", "", "", "", "", 
      "'<'", "'<='", "'>'", "'>='", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "'#'", "'='"
    },
    std::vector<std::string>{
      "", "IF", "THEN", "DO", "WHILE", "FOR", "FROM", "TO", "ELSE", "END", 
      "BREAK", "CONTINUE", "DIGIT", "LETTER", "PLUS", "MINUS", "DOT", "LEFT_BRACKET", 
      "RIGHT_BRACKET", "POWER", "SLASH", "MODULO", "TIMES", "LOGICAL_AND", 
      "EXCLUSIVE_OR", "NON_EXCLUSIVE_OR", "EQ", "NE", "LT", "LE", "GT", 
      "GE", "ABSOLUTE_VALUE", "ARC_COSINE", "ARC_SINE", "COSINE", "E_RAISED_TO", 
      "FIX_DOWN", "FIX_UP", "NATURAL_LOG_OF", "ROUND_OPERATION", "SINE", 
      "SQUARE_ROOT", "TANGENT", "ARC_TANGENT", "PARAMETER_SIGN", "EQUAL_SIGN", 
      "COMMENT", "EOL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,49,350,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,1,0,5,
  	0,72,8,0,10,0,12,0,75,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,84,8,1,1,2,
  	3,2,87,8,2,1,2,3,2,90,8,2,1,2,5,2,93,8,2,10,2,12,2,96,9,2,1,2,4,2,99,
  	8,2,11,2,12,2,100,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,
  	115,8,3,10,3,12,3,118,9,3,1,3,1,3,1,3,3,3,123,8,3,1,3,1,3,1,4,1,4,1,4,
  	1,4,5,4,131,8,4,10,4,12,4,134,9,4,1,4,1,4,1,4,1,5,1,5,5,5,141,8,5,10,
  	5,12,5,144,9,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,
  	6,159,8,6,10,6,12,6,162,9,6,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,
  	4,10,174,8,10,11,10,12,10,175,1,11,1,11,1,11,3,11,181,8,11,1,12,1,12,
  	1,12,1,13,1,13,1,14,1,14,1,14,1,14,3,14,192,8,14,1,15,3,15,195,8,15,1,
  	15,4,15,198,8,15,11,15,12,15,199,1,15,1,15,5,15,204,8,15,10,15,12,15,
  	207,9,15,3,15,209,8,15,1,15,3,15,212,8,15,1,15,1,15,4,15,216,8,15,11,
  	15,12,15,217,3,15,220,8,15,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,5,
  	17,230,8,17,10,17,12,17,233,9,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,241,
  	8,18,10,18,12,18,244,9,18,1,19,1,19,1,19,1,19,1,19,1,19,5,19,252,8,19,
  	10,19,12,19,255,9,19,1,20,1,20,1,20,1,20,1,20,1,20,5,20,263,8,20,10,20,
  	12,20,266,9,20,1,21,1,21,1,21,1,21,1,21,1,21,5,21,274,8,21,10,21,12,21,
  	277,9,21,1,22,1,22,1,22,1,22,1,22,1,22,5,22,285,8,22,10,22,12,22,288,
  	9,22,1,23,1,23,1,23,1,23,1,23,1,23,5,23,296,8,23,10,23,12,23,299,9,23,
  	1,24,1,24,1,24,1,24,1,24,3,24,306,8,24,1,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,314,8,25,1,26,1,26,1,26,1,26,1,26,1,26,3,26,322,8,26,1,27,1,27,3,
  	27,326,8,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,31,1,
  	31,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,34,0,7,34,36,38,
  	40,42,44,46,35,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,0,5,1,0,14,15,1,0,26,27,
  	1,0,28,31,1,0,20,22,1,0,32,43,357,0,73,1,0,0,0,2,83,1,0,0,0,4,86,1,0,
  	0,0,6,102,1,0,0,0,8,126,1,0,0,0,10,138,1,0,0,0,12,150,1,0,0,0,14,166,
  	1,0,0,0,16,168,1,0,0,0,18,170,1,0,0,0,20,173,1,0,0,0,22,180,1,0,0,0,24,
  	182,1,0,0,0,26,185,1,0,0,0,28,191,1,0,0,0,30,219,1,0,0,0,32,221,1,0,0,
  	0,34,223,1,0,0,0,36,234,1,0,0,0,38,245,1,0,0,0,40,256,1,0,0,0,42,267,
  	1,0,0,0,44,278,1,0,0,0,46,289,1,0,0,0,48,305,1,0,0,0,50,313,1,0,0,0,52,
  	321,1,0,0,0,54,325,1,0,0,0,56,327,1,0,0,0,58,330,1,0,0,0,60,332,1,0,0,
  	0,62,337,1,0,0,0,64,342,1,0,0,0,66,345,1,0,0,0,68,347,1,0,0,0,70,72,3,
  	2,1,0,71,70,1,0,0,0,72,75,1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,1,1,
  	0,0,0,75,73,1,0,0,0,76,84,3,4,2,0,77,84,3,6,3,0,78,84,3,8,4,0,79,84,3,
  	10,5,0,80,84,3,12,6,0,81,84,3,14,7,0,82,84,3,16,8,0,83,76,1,0,0,0,83,
  	77,1,0,0,0,83,78,1,0,0,0,83,79,1,0,0,0,83,80,1,0,0,0,83,81,1,0,0,0,83,
  	82,1,0,0,0,84,3,1,0,0,0,85,87,3,18,9,0,86,85,1,0,0,0,86,87,1,0,0,0,87,
  	89,1,0,0,0,88,90,3,20,10,0,89,88,1,0,0,0,89,90,1,0,0,0,90,94,1,0,0,0,
  	91,93,3,22,11,0,92,91,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,
  	0,95,98,1,0,0,0,96,94,1,0,0,0,97,99,5,48,0,0,98,97,1,0,0,0,99,100,1,0,
  	0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,5,1,0,0,0,102,103,5,1,0,0,103,
  	104,3,32,16,0,104,105,5,2,0,0,105,106,5,48,0,0,106,116,3,0,0,0,107,108,
  	5,8,0,0,108,109,5,1,0,0,109,110,3,32,16,0,110,111,5,2,0,0,111,112,5,48,
  	0,0,112,113,3,0,0,0,113,115,1,0,0,0,114,107,1,0,0,0,115,118,1,0,0,0,116,
  	114,1,0,0,0,116,117,1,0,0,0,117,122,1,0,0,0,118,116,1,0,0,0,119,120,5,
  	8,0,0,120,121,5,48,0,0,121,123,3,0,0,0,122,119,1,0,0,0,122,123,1,0,0,
  	0,123,124,1,0,0,0,124,125,5,9,0,0,125,7,1,0,0,0,126,127,5,4,0,0,127,128,
  	3,32,16,0,128,132,5,3,0,0,129,131,5,48,0,0,130,129,1,0,0,0,131,134,1,
  	0,0,0,132,130,1,0,0,0,132,133,1,0,0,0,133,135,1,0,0,0,134,132,1,0,0,0,
  	135,136,3,0,0,0,136,137,5,9,0,0,137,9,1,0,0,0,138,142,5,3,0,0,139,141,
  	5,48,0,0,140,139,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,142,143,1,0,
  	0,0,143,145,1,0,0,0,144,142,1,0,0,0,145,146,3,0,0,0,146,147,5,4,0,0,147,
  	148,3,32,16,0,148,149,5,9,0,0,149,11,1,0,0,0,150,151,5,5,0,0,151,152,
  	3,64,32,0,152,153,5,6,0,0,153,154,3,32,16,0,154,155,5,7,0,0,155,156,3,
  	32,16,0,156,160,5,3,0,0,157,159,5,48,0,0,158,157,1,0,0,0,159,162,1,0,
  	0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,163,1,0,0,0,162,160,1,0,0,0,163,
  	164,3,0,0,0,164,165,5,9,0,0,165,13,1,0,0,0,166,167,5,10,0,0,167,15,1,
  	0,0,0,168,169,5,11,0,0,169,17,1,0,0,0,170,171,5,20,0,0,171,19,1,0,0,0,
  	172,174,5,12,0,0,173,172,1,0,0,0,174,175,1,0,0,0,175,173,1,0,0,0,175,
  	176,1,0,0,0,176,21,1,0,0,0,177,181,3,24,12,0,178,181,3,62,31,0,179,181,
  	3,68,34,0,180,177,1,0,0,0,180,178,1,0,0,0,180,179,1,0,0,0,181,23,1,0,
  	0,0,182,183,3,26,13,0,183,184,3,28,14,0,184,25,1,0,0,0,185,186,5,13,0,
  	0,186,27,1,0,0,0,187,192,3,54,27,0,188,192,3,64,32,0,189,192,3,32,16,
  	0,190,192,3,30,15,0,191,187,1,0,0,0,191,188,1,0,0,0,191,189,1,0,0,0,191,
  	190,1,0,0,0,192,29,1,0,0,0,193,195,7,0,0,0,194,193,1,0,0,0,194,195,1,
  	0,0,0,195,197,1,0,0,0,196,198,5,12,0,0,197,196,1,0,0,0,198,199,1,0,0,
  	0,199,197,1,0,0,0,199,200,1,0,0,0,200,208,1,0,0,0,201,205,5,16,0,0,202,
  	204,5,12,0,0,203,202,1,0,0,0,204,207,1,0,0,0,205,203,1,0,0,0,205,206,
  	1,0,0,0,206,209,1,0,0,0,207,205,1,0,0,0,208,201,1,0,0,0,208,209,1,0,0,
  	0,209,220,1,0,0,0,210,212,7,0,0,0,211,210,1,0,0,0,211,212,1,0,0,0,212,
  	213,1,0,0,0,213,215,5,16,0,0,214,216,5,12,0,0,215,214,1,0,0,0,216,217,
  	1,0,0,0,217,215,1,0,0,0,217,218,1,0,0,0,218,220,1,0,0,0,219,194,1,0,0,
  	0,219,211,1,0,0,0,220,31,1,0,0,0,221,222,3,34,17,0,222,33,1,0,0,0,223,
  	224,6,17,-1,0,224,225,3,36,18,0,225,231,1,0,0,0,226,227,10,2,0,0,227,
  	228,5,25,0,0,228,230,3,36,18,0,229,226,1,0,0,0,230,233,1,0,0,0,231,229,
  	1,0,0,0,231,232,1,0,0,0,232,35,1,0,0,0,233,231,1,0,0,0,234,235,6,18,-1,
  	0,235,236,3,38,19,0,236,242,1,0,0,0,237,238,10,2,0,0,238,239,5,24,0,0,
  	239,241,3,38,19,0,240,237,1,0,0,0,241,244,1,0,0,0,242,240,1,0,0,0,242,
  	243,1,0,0,0,243,37,1,0,0,0,244,242,1,0,0,0,245,246,6,19,-1,0,246,247,
  	3,40,20,0,247,253,1,0,0,0,248,249,10,2,0,0,249,250,5,23,0,0,250,252,3,
  	40,20,0,251,248,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,
  	0,254,39,1,0,0,0,255,253,1,0,0,0,256,257,6,20,-1,0,257,258,3,42,21,0,
  	258,264,1,0,0,0,259,260,10,2,0,0,260,261,7,1,0,0,261,263,3,42,21,0,262,
  	259,1,0,0,0,263,266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,265,41,1,
  	0,0,0,266,264,1,0,0,0,267,268,6,21,-1,0,268,269,3,44,22,0,269,275,1,0,
  	0,0,270,271,10,2,0,0,271,272,7,2,0,0,272,274,3,44,22,0,273,270,1,0,0,
  	0,274,277,1,0,0,0,275,273,1,0,0,0,275,276,1,0,0,0,276,43,1,0,0,0,277,
  	275,1,0,0,0,278,279,6,22,-1,0,279,280,3,46,23,0,280,286,1,0,0,0,281,282,
  	10,2,0,0,282,283,7,0,0,0,283,285,3,46,23,0,284,281,1,0,0,0,285,288,1,
  	0,0,0,286,284,1,0,0,0,286,287,1,0,0,0,287,45,1,0,0,0,288,286,1,0,0,0,
  	289,290,6,23,-1,0,290,291,3,48,24,0,291,297,1,0,0,0,292,293,10,2,0,0,
  	293,294,7,3,0,0,294,296,3,48,24,0,295,292,1,0,0,0,296,299,1,0,0,0,297,
  	295,1,0,0,0,297,298,1,0,0,0,298,47,1,0,0,0,299,297,1,0,0,0,300,301,3,
  	50,25,0,301,302,5,19,0,0,302,303,3,48,24,0,303,306,1,0,0,0,304,306,3,
  	50,25,0,305,300,1,0,0,0,305,304,1,0,0,0,306,49,1,0,0,0,307,308,5,14,0,
  	0,308,314,3,50,25,0,309,310,5,15,0,0,310,314,3,50,25,0,311,314,3,54,27,
  	0,312,314,3,52,26,0,313,307,1,0,0,0,313,309,1,0,0,0,313,311,1,0,0,0,313,
  	312,1,0,0,0,314,51,1,0,0,0,315,322,3,30,15,0,316,322,3,64,32,0,317,318,
  	5,17,0,0,318,319,3,32,16,0,319,320,5,18,0,0,320,322,1,0,0,0,321,315,1,
  	0,0,0,321,316,1,0,0,0,321,317,1,0,0,0,322,53,1,0,0,0,323,326,3,56,28,
  	0,324,326,3,60,30,0,325,323,1,0,0,0,325,324,1,0,0,0,326,55,1,0,0,0,327,
  	328,3,58,29,0,328,329,3,32,16,0,329,57,1,0,0,0,330,331,7,4,0,0,331,59,
  	1,0,0,0,332,333,5,44,0,0,333,334,3,32,16,0,334,335,5,20,0,0,335,336,3,
  	32,16,0,336,61,1,0,0,0,337,338,5,45,0,0,338,339,3,66,33,0,339,340,5,46,
  	0,0,340,341,3,28,14,0,341,63,1,0,0,0,342,343,5,45,0,0,343,344,3,52,26,
  	0,344,65,1,0,0,0,345,346,3,52,26,0,346,67,1,0,0,0,347,348,5,47,0,0,348,
  	69,1,0,0,0,32,73,83,86,89,94,100,116,122,132,142,160,175,180,191,194,
  	199,205,208,211,217,219,231,242,253,264,275,286,297,305,313,321,325
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
    setState(73);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(70);
        statement(); 
      }
      setState(75);
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
    setState(83);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::DIGIT:
      case parser_antlr4::LETTER:
      case parser_antlr4::SLASH:
      case parser_antlr4::PARAMETER_SIGN:
      case parser_antlr4::COMMENT:
      case parser_antlr4::EOL: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        line();
        break;
      }

      case parser_antlr4::IF: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        if_statement();
        break;
      }

      case parser_antlr4::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(78);
        while_statement();
        break;
      }

      case parser_antlr4::DO: {
        enterOuterAlt(_localctx, 4);
        setState(79);
        do_while_statement();
        break;
      }

      case parser_antlr4::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(80);
        for_statement();
        break;
      }

      case parser_antlr4::BREAK: {
        enterOuterAlt(_localctx, 6);
        setState(81);
        break_statement();
        break;
      }

      case parser_antlr4::CONTINUE: {
        enterOuterAlt(_localctx, 7);
        setState(82);
        continue_statement();
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
  enterRule(_localctx, 4, parser_antlr4::RuleLine);
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
    setState(86);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::SLASH) {
      setState(85);
      block_delete();
    }
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::DIGIT) {
      setState(88);
      line_number();
    }
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 175921860452352) != 0)) {
      setState(91);
      segment();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(97);
              match(parser_antlr4::EOL);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(100); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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

std::vector<tree::TerminalNode *> parser_antlr4::If_statementContext::THEN() {
  return getTokens(parser_antlr4::THEN);
}

tree::TerminalNode* parser_antlr4::If_statementContext::THEN(size_t i) {
  return getToken(parser_antlr4::THEN, i);
}

std::vector<tree::TerminalNode *> parser_antlr4::If_statementContext::EOL() {
  return getTokens(parser_antlr4::EOL);
}

tree::TerminalNode* parser_antlr4::If_statementContext::EOL(size_t i) {
  return getToken(parser_antlr4::EOL, i);
}

std::vector<parser_antlr4::BlockContext *> parser_antlr4::If_statementContext::block() {
  return getRuleContexts<parser_antlr4::BlockContext>();
}

parser_antlr4::BlockContext* parser_antlr4::If_statementContext::block(size_t i) {
  return getRuleContext<parser_antlr4::BlockContext>(i);
}

tree::TerminalNode* parser_antlr4::If_statementContext::END() {
  return getToken(parser_antlr4::END, 0);
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
  enterRule(_localctx, 6, parser_antlr4::RuleIf_statement);
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
    match(parser_antlr4::IF);
    setState(103);
    expression();
    setState(104);
    match(parser_antlr4::THEN);
    setState(105);
    match(parser_antlr4::EOL);
    setState(106);
    block();
    setState(116);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(107);
        match(parser_antlr4::ELSE);
        setState(108);
        match(parser_antlr4::IF);
        setState(109);
        expression();
        setState(110);
        match(parser_antlr4::THEN);
        setState(111);
        match(parser_antlr4::EOL);
        setState(112);
        block(); 
      }
      setState(118);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == parser_antlr4::ELSE) {
      setState(119);
      match(parser_antlr4::ELSE);
      setState(120);
      match(parser_antlr4::EOL);
      setState(121);
      block();
    }
    setState(124);
    match(parser_antlr4::END);
   
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

tree::TerminalNode* parser_antlr4::While_statementContext::DO() {
  return getToken(parser_antlr4::DO, 0);
}

parser_antlr4::BlockContext* parser_antlr4::While_statementContext::block() {
  return getRuleContext<parser_antlr4::BlockContext>(0);
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
  enterRule(_localctx, 8, parser_antlr4::RuleWhile_statement);

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
    setState(126);
    match(parser_antlr4::WHILE);
    setState(127);
    expression();
    setState(128);
    match(parser_antlr4::DO);
    setState(132);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(129);
        match(parser_antlr4::EOL); 
      }
      setState(134);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(135);
    block();
    setState(136);
    match(parser_antlr4::END);
   
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
  enterRule(_localctx, 10, parser_antlr4::RuleDo_while_statement);

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
    setState(138);
    match(parser_antlr4::DO);
    setState(142);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(139);
        match(parser_antlr4::EOL); 
      }
      setState(144);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(145);
    block();
    setState(146);
    match(parser_antlr4::WHILE);
    setState(147);
    expression();
    setState(148);
    match(parser_antlr4::END);
   
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
  enterRule(_localctx, 12, parser_antlr4::RuleFor_statement);

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
    match(parser_antlr4::FOR);
    setState(151);
    parameter_value();
    setState(152);
    match(parser_antlr4::FROM);
    setState(153);
    expression();
    setState(154);
    match(parser_antlr4::TO);
    setState(155);
    expression();
    setState(156);
    match(parser_antlr4::DO);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(157);
        match(parser_antlr4::EOL); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(163);
    block();
    setState(164);
    match(parser_antlr4::END);
   
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
  enterRule(_localctx, 14, parser_antlr4::RuleBreak_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
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
  enterRule(_localctx, 16, parser_antlr4::RuleContinue_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
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
  enterRule(_localctx, 18, parser_antlr4::RuleBlock_delete);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
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
  enterRule(_localctx, 20, parser_antlr4::RuleLine_number);
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
    setState(173); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(172);
      match(parser_antlr4::DIGIT);
      setState(175); 
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
  enterRule(_localctx, 22, parser_antlr4::RuleSegment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::LETTER: {
        enterOuterAlt(_localctx, 1);
        setState(177);
        mid_line_word();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN: {
        enterOuterAlt(_localctx, 2);
        setState(178);
        parameter_setting();
        break;
      }

      case parser_antlr4::COMMENT: {
        enterOuterAlt(_localctx, 3);
        setState(179);
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
  enterRule(_localctx, 24, parser_antlr4::RuleMid_line_word);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    mid_line_letter();
    setState(183);
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
  enterRule(_localctx, 26, parser_antlr4::RuleMid_line_letter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(parser_antlr4::LETTER);
   
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
  enterRule(_localctx, 28, parser_antlr4::RuleReal_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(187);
      unary_combo();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(188);
      parameter_value();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(189);
      expression();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(190);
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
  enterRule(_localctx, 30, parser_antlr4::RuleReal_number);
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
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(194);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(193);
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
      setState(197); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(196);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(199); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(208);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(201);
        match(parser_antlr4::DOT);
        setState(205);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(202);
            match(parser_antlr4::DIGIT); 
          }
          setState(207);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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
      setState(211);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == parser_antlr4::PLUS

      || _la == parser_antlr4::MINUS) {
        setState(210);
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
      setState(213);
      match(parser_antlr4::DOT);
      setState(215); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(214);
                match(parser_antlr4::DIGIT);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(217); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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
  enterRule(_localctx, 32, parser_antlr4::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, parser_antlr4::RuleLogical_or_expression, precedence);

    

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
    setState(224);
    logical_xor_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(231);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_or_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_or_expression);
        setState(226);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(227);
        match(parser_antlr4::NON_EXCLUSIVE_OR);
        setState(228);
        logical_xor_expression(0); 
      }
      setState(233);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, parser_antlr4::RuleLogical_xor_expression, precedence);

    

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
    setState(235);
    logical_and_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_xor_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_xor_expression);
        setState(237);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(238);
        match(parser_antlr4::EXCLUSIVE_OR);
        setState(239);
        logical_and_expression(0); 
      }
      setState(244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, parser_antlr4::RuleLogical_and_expression, precedence);

    

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
    setState(246);
    equality_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(253);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Logical_and_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogical_and_expression);
        setState(248);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(249);
        match(parser_antlr4::LOGICAL_AND);
        setState(250);
        equality_expression(0); 
      }
      setState(255);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, parser_antlr4::RuleEquality_expression, precedence);

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
    setState(257);
    relational_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(264);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Equality_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEquality_expression);
        setState(259);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(260);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::EQ

        || _la == parser_antlr4::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(261);
        relational_expression(0); 
      }
      setState(266);
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
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, parser_antlr4::RuleRelational_expression, precedence);

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
    setState(268);
    additive_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(275);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Relational_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelational_expression);
        setState(270);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(271);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 4026531840) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(272);
        additive_expression(0); 
      }
      setState(277);
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
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, parser_antlr4::RuleAdditive_expression, precedence);

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
    setState(279);
    multiplicative_expression(0);
    _ctx->stop = _input->LT(-1);
    setState(286);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Additive_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditive_expression);
        setState(281);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(282);
        _la = _input->LA(1);
        if (!(_la == parser_antlr4::PLUS

        || _la == parser_antlr4::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(283);
        multiplicative_expression(0); 
      }
      setState(288);
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
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, parser_antlr4::RuleMultiplicative_expression, precedence);

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
    setState(290);
    power_expression();
    _ctx->stop = _input->LT(-1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Multiplicative_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicative_expression);
        setState(292);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(293);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 7340032) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(294);
        power_expression(); 
      }
      setState(299);
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
  enterRule(_localctx, 48, parser_antlr4::RulePower_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(300);
      unary_expression();
      setState(301);
      match(parser_antlr4::POWER);
      setState(302);
      power_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(304);
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
  enterRule(_localctx, 50, parser_antlr4::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(307);
      match(parser_antlr4::PLUS);
      setState(308);
      unary_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(309);
      match(parser_antlr4::MINUS);
      setState(310);
      unary_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(311);
      unary_combo();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(312);
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
  enterRule(_localctx, 52, parser_antlr4::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case parser_antlr4::DIGIT:
      case parser_antlr4::PLUS:
      case parser_antlr4::MINUS:
      case parser_antlr4::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(315);
        real_number();
        break;
      }

      case parser_antlr4::PARAMETER_SIGN: {
        enterOuterAlt(_localctx, 2);
        setState(316);
        parameter_value();
        break;
      }

      case parser_antlr4::LEFT_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(317);
        match(parser_antlr4::LEFT_BRACKET);
        setState(318);
        expression();
        setState(319);
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
  enterRule(_localctx, 54, parser_antlr4::RuleUnary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
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
        setState(323);
        ordinary_unary_combo();
        break;
      }

      case parser_antlr4::ARC_TANGENT: {
        enterOuterAlt(_localctx, 2);
        setState(324);
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
  enterRule(_localctx, 56, parser_antlr4::RuleOrdinary_unary_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    ordinary_unary_operation();
    setState(328);
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
  enterRule(_localctx, 58, parser_antlr4::RuleOrdinary_unary_operation);
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
    setState(330);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17587891077120) != 0))) {
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
  enterRule(_localctx, 60, parser_antlr4::RuleArc_tangent_combo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(parser_antlr4::ARC_TANGENT);
    setState(333);
    expression();
    setState(334);
    match(parser_antlr4::SLASH);
    setState(335);
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

tree::TerminalNode* parser_antlr4::Parameter_settingContext::PARAMETER_SIGN() {
  return getToken(parser_antlr4::PARAMETER_SIGN, 0);
}

parser_antlr4::Parameter_indexContext* parser_antlr4::Parameter_settingContext::parameter_index() {
  return getRuleContext<parser_antlr4::Parameter_indexContext>(0);
}

tree::TerminalNode* parser_antlr4::Parameter_settingContext::EQUAL_SIGN() {
  return getToken(parser_antlr4::EQUAL_SIGN, 0);
}

parser_antlr4::Real_valueContext* parser_antlr4::Parameter_settingContext::real_value() {
  return getRuleContext<parser_antlr4::Real_valueContext>(0);
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
  enterRule(_localctx, 62, parser_antlr4::RuleParameter_setting);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    match(parser_antlr4::PARAMETER_SIGN);
    setState(338);
    parameter_index();
    setState(339);
    match(parser_antlr4::EQUAL_SIGN);
    setState(340);
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
  enterRule(_localctx, 64, parser_antlr4::RuleParameter_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(parser_antlr4::PARAMETER_SIGN);
    setState(343);
    primary();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_indexContext ------------------------------------------------------------------

parser_antlr4::Parameter_indexContext::Parameter_indexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

parser_antlr4::PrimaryContext* parser_antlr4::Parameter_indexContext::primary() {
  return getRuleContext<parser_antlr4::PrimaryContext>(0);
}


size_t parser_antlr4::Parameter_indexContext::getRuleIndex() const {
  return parser_antlr4::RuleParameter_index;
}

void parser_antlr4::Parameter_indexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_index(this);
}

void parser_antlr4::Parameter_indexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<parser_antlr4Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_index(this);
}


std::any parser_antlr4::Parameter_indexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<parser_antlr4Visitor*>(visitor))
    return parserVisitor->visitParameter_index(this);
  else
    return visitor->visitChildren(this);
}

parser_antlr4::Parameter_indexContext* parser_antlr4::parameter_index() {
  Parameter_indexContext *_localctx = _tracker.createInstance<Parameter_indexContext>(_ctx, getState());
  enterRule(_localctx, 66, parser_antlr4::RuleParameter_index);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    primary();
   
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
  enterRule(_localctx, 68, parser_antlr4::RuleComment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
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
    case 17: return logical_or_expressionSempred(antlrcpp::downCast<Logical_or_expressionContext *>(context), predicateIndex);
    case 18: return logical_xor_expressionSempred(antlrcpp::downCast<Logical_xor_expressionContext *>(context), predicateIndex);
    case 19: return logical_and_expressionSempred(antlrcpp::downCast<Logical_and_expressionContext *>(context), predicateIndex);
    case 20: return equality_expressionSempred(antlrcpp::downCast<Equality_expressionContext *>(context), predicateIndex);
    case 21: return relational_expressionSempred(antlrcpp::downCast<Relational_expressionContext *>(context), predicateIndex);
    case 22: return additive_expressionSempred(antlrcpp::downCast<Additive_expressionContext *>(context), predicateIndex);
    case 23: return multiplicative_expressionSempred(antlrcpp::downCast<Multiplicative_expressionContext *>(context), predicateIndex);

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
