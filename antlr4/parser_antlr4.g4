// PS: adapted from -
// https://github.com/grwhitehead/rs274ngc-python3/blob/33f63d3dd2d8166a9a9931a76ce3f1c93d6c7078/GCode.g4
//

parser grammar parser_antlr4;

options { tokenVocab=lexer_antlr4; }

// ngcfile
//    : '%' EOL program '%' EOL .*? EOL
//    | '%' EOL program EOL
//    | program EOL
//    ;

program
    : line* EOL*
    ;

line
    : block_delete? line_number? segment* EOL
    | if_statement
    ;

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
    : LETTER
    ;

real_value
    : real_number
    | expression
    | parameter_value
    | unary_combo
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
    : PARAMETER_SIGN parameter_index EQUAL_SIGN real_value
    ;

parameter_value
    : PARAMETER_SIGN parameter_index
    ;

parameter_index
    : real_value
    ;

comment
    : COMMENT
    ;

// >>> extended grammar

if_statement
    : IF expression THEN EOL line* (ELSE EOL line*)? END
    ;

// <<< extended grammar