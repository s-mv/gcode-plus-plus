
// Generated from lexer_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  lexer_antlr4 : public antlr4::Lexer {
public:
  enum {
    IF = 1, THEN = 2, DO = 3, WHILE = 4, FOR = 5, FROM = 6, TO = 7, ELSE = 8, 
    END = 9, ENDIF = 10, ENDWHILE = 11, ENDFOR = 12, BREAK = 13, CONTINUE = 14, 
    SUBROUTINE = 15, M99 = 16, DIGIT = 17, LETTER = 18, PLUS = 19, MINUS = 20, 
    DOT = 21, LEFT_BRACKET = 22, RIGHT_BRACKET = 23, POWER = 24, SLASH = 25, 
    MODULO = 26, TIMES = 27, LOGICAL_AND = 28, EXCLUSIVE_OR = 29, NON_EXCLUSIVE_OR = 30, 
    EQ = 31, NE = 32, LT = 33, LE = 34, GT = 35, GE = 36, ABSOLUTE_VALUE = 37, 
    ARC_COSINE = 38, ARC_SINE = 39, COSINE = 40, E_RAISED_TO = 41, FIX_DOWN = 42, 
    FIX_UP = 43, NATURAL_LOG_OF = 44, ROUND_OPERATION = 45, SINE = 46, SQUARE_ROOT = 47, 
    TANGENT = 48, ARC_TANGENT = 49, PARAMETER_SIGN = 50, EQUAL_SIGN = 51, 
    COMMENT = 52, NAMED_PARAMETER = 53, EOL = 54, WS = 55
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

