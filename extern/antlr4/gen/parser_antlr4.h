
// Generated from parser_antlr4.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  parser_antlr4 : public antlr4::Parser {
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
    EQUAL_SIGN = 46, COMMENT = 47, NAMED_PARAMETER = 48, EOL = 49, WS = 50
  };

  enum {
    RuleBlock = 0, RuleStatement = 1, RuleLine = 2, RuleIf_statement = 3, 
    RuleWhile_statement = 4, RuleDo_while_statement = 5, RuleFor_statement = 6, 
    RuleBreak_statement = 7, RuleContinue_statement = 8, RuleBlock_delete = 9, 
    RuleLine_number = 10, RuleSegment = 11, RuleMid_line_word = 12, RuleMid_line_letter = 13, 
    RuleReal_value = 14, RuleReal_number = 15, RuleExpression = 16, RuleLogical_or_expression = 17, 
    RuleLogical_xor_expression = 18, RuleLogical_and_expression = 19, RuleEquality_expression = 20, 
    RuleRelational_expression = 21, RuleAdditive_expression = 22, RuleMultiplicative_expression = 23, 
    RulePower_expression = 24, RuleUnary_expression = 25, RulePrimary = 26, 
    RuleUnary_combo = 27, RuleOrdinary_unary_combo = 28, RuleOrdinary_unary_operation = 29, 
    RuleArc_tangent_combo = 30, RuleParameter_setting = 31, RuleParameter_value = 32, 
    RuleComment = 33
  };

  explicit parser_antlr4(antlr4::TokenStream *input);

  parser_antlr4(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~parser_antlr4() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class BlockContext;
  class StatementContext;
  class LineContext;
  class If_statementContext;
  class While_statementContext;
  class Do_while_statementContext;
  class For_statementContext;
  class Break_statementContext;
  class Continue_statementContext;
  class Block_deleteContext;
  class Line_numberContext;
  class SegmentContext;
  class Mid_line_wordContext;
  class Mid_line_letterContext;
  class Real_valueContext;
  class Real_numberContext;
  class ExpressionContext;
  class Logical_or_expressionContext;
  class Logical_xor_expressionContext;
  class Logical_and_expressionContext;
  class Equality_expressionContext;
  class Relational_expressionContext;
  class Additive_expressionContext;
  class Multiplicative_expressionContext;
  class Power_expressionContext;
  class Unary_expressionContext;
  class PrimaryContext;
  class Unary_comboContext;
  class Ordinary_unary_comboContext;
  class Ordinary_unary_operationContext;
  class Arc_tangent_comboContext;
  class Parameter_settingContext;
  class Parameter_valueContext;
  class CommentContext; 

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LineContext *line();
    If_statementContext *if_statement();
    While_statementContext *while_statement();
    Do_while_statementContext *do_while_statement();
    For_statementContext *for_statement();
    Break_statementContext *break_statement();
    Continue_statementContext *continue_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_deleteContext *block_delete();
    Line_numberContext *line_number();
    std::vector<SegmentContext *> segment();
    SegmentContext* segment(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IF();
    antlr4::tree::TerminalNode* IF(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> THEN();
    antlr4::tree::TerminalNode* THEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> ELSE();
    antlr4::tree::TerminalNode* ELSE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  While_statementContext : public antlr4::ParserRuleContext {
  public:
    While_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statementContext* while_statement();

  class  Do_while_statementContext : public antlr4::ParserRuleContext {
  public:
    Do_while_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Do_while_statementContext* do_while_statement();

  class  For_statementContext : public antlr4::ParserRuleContext {
  public:
    For_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Parameter_valueContext *parameter_value();
    antlr4::tree::TerminalNode *FROM();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_statementContext* for_statement();

  class  Break_statementContext : public antlr4::ParserRuleContext {
  public:
    Break_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_statementContext* break_statement();

  class  Continue_statementContext : public antlr4::ParserRuleContext {
  public:
    Continue_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continue_statementContext* continue_statement();

  class  Block_deleteContext : public antlr4::ParserRuleContext {
  public:
    Block_deleteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_deleteContext* block_delete();

  class  Line_numberContext : public antlr4::ParserRuleContext {
  public:
    Line_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DIGIT();
    antlr4::tree::TerminalNode* DIGIT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Line_numberContext* line_number();

  class  SegmentContext : public antlr4::ParserRuleContext {
  public:
    SegmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mid_line_wordContext *mid_line_word();
    Parameter_settingContext *parameter_setting();
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SegmentContext* segment();

  class  Mid_line_wordContext : public antlr4::ParserRuleContext {
  public:
    Mid_line_wordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mid_line_letterContext *mid_line_letter();
    Real_valueContext *real_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mid_line_wordContext* mid_line_word();

  class  Mid_line_letterContext : public antlr4::ParserRuleContext {
  public:
    Mid_line_letterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LETTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mid_line_letterContext* mid_line_letter();

  class  Real_valueContext : public antlr4::ParserRuleContext {
  public:
    Real_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_comboContext *unary_combo();
    Parameter_valueContext *parameter_value();
    ExpressionContext *expression();
    Real_numberContext *real_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Real_valueContext* real_value();

  class  Real_numberContext : public antlr4::ParserRuleContext {
  public:
    Real_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DIGIT();
    antlr4::tree::TerminalNode* DIGIT(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Real_numberContext* real_number();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_or_expressionContext *logical_or_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Logical_or_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_or_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_xor_expressionContext *logical_xor_expression();
    Logical_or_expressionContext *logical_or_expression();
    antlr4::tree::TerminalNode *NON_EXCLUSIVE_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_or_expressionContext* logical_or_expression();
  Logical_or_expressionContext* logical_or_expression(int precedence);
  class  Logical_xor_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_xor_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logical_and_expressionContext *logical_and_expression();
    Logical_xor_expressionContext *logical_xor_expression();
    antlr4::tree::TerminalNode *EXCLUSIVE_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_xor_expressionContext* logical_xor_expression();
  Logical_xor_expressionContext* logical_xor_expression(int precedence);
  class  Logical_and_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logical_and_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Equality_expressionContext *equality_expression();
    Logical_and_expressionContext *logical_and_expression();
    antlr4::tree::TerminalNode *LOGICAL_AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Logical_and_expressionContext* logical_and_expression();
  Logical_and_expressionContext* logical_and_expression(int precedence);
  class  Equality_expressionContext : public antlr4::ParserRuleContext {
  public:
    Equality_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Relational_expressionContext *relational_expression();
    Equality_expressionContext *equality_expression();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Equality_expressionContext* equality_expression();
  Equality_expressionContext* equality_expression(int precedence);
  class  Relational_expressionContext : public antlr4::ParserRuleContext {
  public:
    Relational_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Additive_expressionContext *additive_expression();
    Relational_expressionContext *relational_expression();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Relational_expressionContext* relational_expression();
  Relational_expressionContext* relational_expression(int precedence);
  class  Additive_expressionContext : public antlr4::ParserRuleContext {
  public:
    Additive_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Multiplicative_expressionContext *multiplicative_expression();
    Additive_expressionContext *additive_expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Additive_expressionContext* additive_expression();
  Additive_expressionContext* additive_expression(int precedence);
  class  Multiplicative_expressionContext : public antlr4::ParserRuleContext {
  public:
    Multiplicative_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Power_expressionContext *power_expression();
    Multiplicative_expressionContext *multiplicative_expression();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MODULO();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiplicative_expressionContext* multiplicative_expression();
  Multiplicative_expressionContext* multiplicative_expression(int precedence);
  class  Power_expressionContext : public antlr4::ParserRuleContext {
  public:
    Power_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *POWER();
    Power_expressionContext *power_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Power_expressionContext* power_expression();

  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MINUS();
    Unary_comboContext *unary_combo();
    PrimaryContext *primary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Real_numberContext *real_number();
    Parameter_valueContext *parameter_value();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  Unary_comboContext : public antlr4::ParserRuleContext {
  public:
    Unary_comboContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ordinary_unary_comboContext *ordinary_unary_combo();
    Arc_tangent_comboContext *arc_tangent_combo();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_comboContext* unary_combo();

  class  Ordinary_unary_comboContext : public antlr4::ParserRuleContext {
  public:
    Ordinary_unary_comboContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ordinary_unary_operationContext *ordinary_unary_operation();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordinary_unary_comboContext* ordinary_unary_combo();

  class  Ordinary_unary_operationContext : public antlr4::ParserRuleContext {
  public:
    Ordinary_unary_operationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABSOLUTE_VALUE();
    antlr4::tree::TerminalNode *ARC_COSINE();
    antlr4::tree::TerminalNode *ARC_SINE();
    antlr4::tree::TerminalNode *COSINE();
    antlr4::tree::TerminalNode *E_RAISED_TO();
    antlr4::tree::TerminalNode *FIX_DOWN();
    antlr4::tree::TerminalNode *FIX_UP();
    antlr4::tree::TerminalNode *NATURAL_LOG_OF();
    antlr4::tree::TerminalNode *ROUND_OPERATION();
    antlr4::tree::TerminalNode *SINE();
    antlr4::tree::TerminalNode *SQUARE_ROOT();
    antlr4::tree::TerminalNode *TANGENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordinary_unary_operationContext* ordinary_unary_operation();

  class  Arc_tangent_comboContext : public antlr4::ParserRuleContext {
  public:
    Arc_tangent_comboContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARC_TANGENT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *SLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arc_tangent_comboContext* arc_tangent_combo();

  class  Parameter_settingContext : public antlr4::ParserRuleContext {
  public:
    Parameter_settingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUAL_SIGN();
    Real_valueContext *real_value();
    antlr4::tree::TerminalNode *PARAMETER_SIGN();
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *NAMED_PARAMETER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_settingContext* parameter_setting();

  class  Parameter_valueContext : public antlr4::ParserRuleContext {
  public:
    Parameter_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PARAMETER_SIGN();
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *NAMED_PARAMETER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_valueContext* parameter_value();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentContext* comment();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool logical_or_expressionSempred(Logical_or_expressionContext *_localctx, size_t predicateIndex);
  bool logical_xor_expressionSempred(Logical_xor_expressionContext *_localctx, size_t predicateIndex);
  bool logical_and_expressionSempred(Logical_and_expressionContext *_localctx, size_t predicateIndex);
  bool equality_expressionSempred(Equality_expressionContext *_localctx, size_t predicateIndex);
  bool relational_expressionSempred(Relational_expressionContext *_localctx, size_t predicateIndex);
  bool additive_expressionSempred(Additive_expressionContext *_localctx, size_t predicateIndex);
  bool multiplicative_expressionSempred(Multiplicative_expressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

