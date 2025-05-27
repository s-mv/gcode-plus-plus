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
    ;

block_delete
    : SLASH
    ;

line_number
    : DIGIT+
    ;

segment
    : mid_line_word
    | if_statement
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
    : LEFT_BRACKET real_value (binary_operation real_value)* RIGHT_BRACKET
    ;

binary_operation
    : binary_operation1
    | binary_operation2
    | binary_operation3
    | binary_operation4
    ;

binary_operation1
    : POWER
    ;

binary_operation2
    : SLASH
    | MODULO
    | TIMES
    ;

binary_operation3
    : LOGICAL_AND
    | EXCLUSIVE_OR
    | MINUS
    | NON_EXCLUSIVE_OR
    | PLUS
    ;

binary_operation4
    : EQ
    | NE
    | LT
    | LE
    | GT
    | GE
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