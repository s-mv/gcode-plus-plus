
// Generated from /home/smv/code/accelus/linuxcnc/src/emc/sterp/antlr4/lexer_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  lexer_antlr4 : public antlr4::Lexer {
public:
  enum {
    IF = 1, THEN = 2, DO = 3, WHILE = 4, FOR = 5, FROM = 6, TO = 7, ELSE = 8, 
    END = 9, ENDIF = 10, ENDWHILE = 11, ENDFOR = 12, BREAK = 13, CONTINUE = 14, 
    IMPORT = 15, FILENAME = 16, SUBROUTINE = 17, M99 = 18, PERCENT = 19, 
    DIGIT = 20, LETTER = 21, DOLLAR = 22, PLUS = 23, MINUS = 24, DOT = 25, 
    LEFT_BRACKET = 26, RIGHT_BRACKET = 27, POWER = 28, SLASH = 29, MODULO = 30, 
    TIMES = 31, LOGICAL_AND = 32, EXCLUSIVE_OR = 33, NON_EXCLUSIVE_OR = 34, 
    EQ = 35, NE = 36, LT = 37, LE = 38, GT = 39, GE = 40, ABSOLUTE_VALUE = 41, 
    ARC_COSINE = 42, ARC_SINE = 43, COSINE = 44, E_RAISED_TO = 45, FIX_DOWN = 46, 
    FIX_UP = 47, NATURAL_LOG_OF = 48, ROUND_OPERATION = 49, SINE = 50, SQUARE_ROOT = 51, 
    TANGENT = 52, ARC_TANGENT = 53, PARAMETER_SIGN = 54, EQUAL_SIGN = 55, 
    COMMENT = 56, NAMED_PARAMETER = 57, EOL = 58, WS = 59
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

