
// Generated from /home/smv/temp/linuxcnc-2.9.4/src/emc/sterp/antlr4/lexer_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  lexer_antlr4 : public antlr4::Lexer {
public:
  enum {
    IF = 1, THEN = 2, DO = 3, WHILE = 4, FOR = 5, FROM = 6, TO = 7, ELSE = 8, 
    END = 9, ENDIF = 10, ENDWHILE = 11, ENDFOR = 12, BREAK = 13, CONTINUE = 14, 
    SUBROUTINE = 15, M99 = 16, PERCENT = 17, DIGIT = 18, LETTER = 19, DOLLAR = 20, 
    PLUS = 21, MINUS = 22, DOT = 23, LEFT_BRACKET = 24, RIGHT_BRACKET = 25, 
    POWER = 26, SLASH = 27, MODULO = 28, TIMES = 29, LOGICAL_AND = 30, EXCLUSIVE_OR = 31, 
    NON_EXCLUSIVE_OR = 32, EQ = 33, NE = 34, LT = 35, LE = 36, GT = 37, 
    GE = 38, ABSOLUTE_VALUE = 39, ARC_COSINE = 40, ARC_SINE = 41, COSINE = 42, 
    E_RAISED_TO = 43, FIX_DOWN = 44, FIX_UP = 45, NATURAL_LOG_OF = 46, ROUND_OPERATION = 47, 
    SINE = 48, SQUARE_ROOT = 49, TANGENT = 50, ARC_TANGENT = 51, PARAMETER_SIGN = 52, 
    EQUAL_SIGN = 53, COMMENT = 54, NAMED_PARAMETER = 55, EOL = 56, WS = 57
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

