// PS: adapted from -
// https://github.com/grwhitehead/rs274ngc-python3/blob/33f63d3dd2d8166a9a9931a76ce3f1c93d6c7078/GCode.g4
//

parser grammar parser_antlr4;

options { tokenVocab=lexer_antlr4; }

block
    : PERCENT EOL (statement | EOL)* PERCENT EOL .*? EOL
    | PERCENT EOL (statement | EOL)*
    | (statement | EOL)*
    ;

statement
    : line
    | import_statement
    | if_statement
    | while_statement
    | do_while_statement
    | for_statement
    | break_statement
    | continue_statement
    | subroutine
    ;

subroutine
    : SUBROUTINE real_value EOL* block m99
    ;

m99 : M99 ;

line
    : block_delete? line_number? segment* EOL+
    ;

// >>> extended grammar

import_statement
    : IMPORT FILENAME EOL+
    ;

if_statement
    : IF expression EOL* block
      (ELSE IF expression EOL* block)*
      (ELSE EOL block)? (ENDIF | END) EOL+
    ;

while_statement
    : WHILE expression EOL* block (ENDWHILE | END) EOL+
    ;

do_while_statement
    : DO EOL* block WHILE expression (END | ENDWHILE) EOL+
    ;

for_statement
    : FOR parameter_value
      FROM expression TO expression EOL*
      block (ENDFOR | END) EOL+
    ; 

break_statement: BREAK;
continue_statement: CONTINUE;

// <<< extended grammar

block_delete
    : SLASH
    ;

line_number
    : DIGIT+
    ;

segment
    : mid_line_word
    | parameter_setting
    | comment
    ;

mid_line_word
    : mid_line_letter real_value
    ;

mid_line_letter
    : LETTER | DOLLAR
    ;

real_value
    : unary_combo
    | parameter_value
    | expression
    | real_number
    ;

real_number
    : (PLUS | MINUS)? DIGIT+ (DOT DIGIT*)?
    | (PLUS | MINUS)? DOT DIGIT+
    ;

expression
    : logical_or_expression
    ;

logical_or_expression
    : logical_or_expression NON_EXCLUSIVE_OR logical_xor_expression
    | logical_xor_expression
    ;

logical_xor_expression
    : logical_xor_expression EXCLUSIVE_OR logical_and_expression
    | logical_and_expression
    ;

logical_and_expression
    : logical_and_expression LOGICAL_AND equality_expression
    | equality_expression
    ;

equality_expression
    : equality_expression (EQ | NE) relational_expression
    | relational_expression
    ;

relational_expression
    : relational_expression (LT | LE | GT | GE) additive_expression
    | additive_expression
    ;

additive_expression
    : additive_expression (PLUS | MINUS) multiplicative_expression
    | multiplicative_expression
    ;

multiplicative_expression
    : multiplicative_expression (TIMES | SLASH | MODULO) power_expression
    | power_expression
    ;

power_expression
    : unary_expression POWER power_expression
    | unary_expression
    ;

unary_expression
    : PLUS unary_expression
    | MINUS unary_expression
    | unary_combo
    | primary
    ;

primary
    : real_number
    | parameter_value
    | LEFT_BRACKET expression RIGHT_BRACKET
    ;

unary_combo
    : ordinary_unary_combo
    | arc_tangent_combo
    ;

ordinary_unary_combo
    : ordinary_unary_operation expression
    ;

ordinary_unary_operation
    : ABSOLUTE_VALUE
    | ARC_COSINE
    | ARC_SINE
    | COSINE
    | E_RAISED_TO
    | FIX_DOWN
    | FIX_UP
    | NATURAL_LOG_OF
    | ROUND_OPERATION
    | SINE
    | SQUARE_ROOT
    | TANGENT
    ;

arc_tangent_combo
    : ARC_TANGENT expression SLASH expression
    ;

parameter_setting
    : (PARAMETER_SIGN primary | NAMED_PARAMETER) EQUAL_SIGN real_value
    ;

parameter_value
    : PARAMETER_SIGN primary | NAMED_PARAMETER
    ;

comment
    : COMMENT
    ;

