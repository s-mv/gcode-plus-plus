
// Generated from lexer_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  lexer_antlr4 : public antlr4::Lexer {
public:
  enum {
    IF = 1, THEN = 2, DO = 3, WHILE = 4, FOR = 5, FROM = 6, TO = 7, ELSE = 8, 
    END = 9, ENDIF = 10, ENDWHILE = 11, ENDFOR = 12, BREAK = 13, CONTINUE = 14, 
    SUBROUTINE = 15, M99 = 16, DIGIT = 17, LETTER = 18, DOLLAR = 19, PLUS = 20, 
    MINUS = 21, DOT = 22, LEFT_BRACKET = 23, RIGHT_BRACKET = 24, POWER = 25, 
    SLASH = 26, MODULO = 27, TIMES = 28, LOGICAL_AND = 29, EXCLUSIVE_OR = 30, 
    NON_EXCLUSIVE_OR = 31, EQ = 32, NE = 33, LT = 34, LE = 35, GT = 36, 
    GE = 37, ABSOLUTE_VALUE = 38, ARC_COSINE = 39, ARC_SINE = 40, COSINE = 41, 
    E_RAISED_TO = 42, FIX_DOWN = 43, FIX_UP = 44, NATURAL_LOG_OF = 45, ROUND_OPERATION = 46, 
    SINE = 47, SQUARE_ROOT = 48, TANGENT = 49, ARC_TANGENT = 50, PARAMETER_SIGN = 51, 
    EQUAL_SIGN = 52, COMMENT = 53, NAMED_PARAMETER = 54, EOL = 55, WS = 56
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

