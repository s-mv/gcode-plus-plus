
// Generated from lexer_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  lexer_antlr4 : public antlr4::Lexer {
public:
  enum {
    IF = 1, THEN = 2, DO = 3, WHILE = 4, FOR = 5, FROM = 6, TO = 7, ELSE = 8, 
    END = 9, BREAK = 10, CONTINUE = 11, DIGIT = 12, LETTER = 13, PLUS = 14, 
    MINUS = 15, DOT = 16, LEFT_BRACKET = 17, RIGHT_BRACKET = 18, POWER = 19, 
    SLASH = 20, MODULO = 21, TIMES = 22, LOGICAL_AND = 23, EXCLUSIVE_OR = 24, 
    NON_EXCLUSIVE_OR = 25, EQ = 26, NE = 27, LT = 28, LE = 29, GT = 30, 
    GE = 31, ABSOLUTE_VALUE = 32, ARC_COSINE = 33, ARC_SINE = 34, COSINE = 35, 
    E_RAISED_TO = 36, FIX_DOWN = 37, FIX_UP = 38, NATURAL_LOG_OF = 39, ROUND_OPERATION = 40, 
    SINE = 41, SQUARE_ROOT = 42, TANGENT = 43, ARC_TANGENT = 44, PARAMETER_SIGN = 45, 
    EQUAL_SIGN = 46, COMMENT = 47, EOL = 48, WS = 49
  };

  explicit lexer_antlr4(antlr4::CharStream *input);

  ~lexer_antlr4() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

