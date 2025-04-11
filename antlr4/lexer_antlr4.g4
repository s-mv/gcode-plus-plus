// PS: adapted from -
// https://github.com/grwhitehead/rs274ngc-python3/blob/33f63d3dd2d8166a9a9931a76ce3f1c93d6c7078/GCode.g4
//

lexer grammar lexer_antlr4;

DIGIT : '0' .. '9' ;
LETTER
    : 'A' .. 'Z'
    | 'a' .. 'z'
    ;

PLUS  : '+' ;
MINUS : '-' ;
DOT   : '.' ;

LEFT_BRACKET  : '[' ;
RIGHT_BRACKET : ']' ;

POWER : '**' ;
SLASH : '/' ;

MODULO : [Mm][Oo][Dd] ;

TIMES : '*' ;

LOGICAL_AND : [Aa][Nn][Dd] ;

EXCLUSIVE_OR : [Xx][Oo][Rr] ;

NON_EXCLUSIVE_OR : [Oo][Rr] ;

ABSOLUTE_VALUE  : [Aa][Bb][Ss] ;
ARC_COSINE      : [Aa][Cc][Oo][Ss] ;
ARC_SINE        : [Aa][Ss][Ii][Nn] ;
COSINE          : [Cc][Oo][Ss] ;
E_RAISED_TO     : [Ee][Xx][Pp] ;
FIX_DOWN        : [Ff][Ii][Xx] ;
FIX_UP          : [Ff][Uu][Pp] ;
NATURAL_LOG_OF  : [Ll][Nn] ;
ROUND_OPERATION : [Rr][Oo][Uu][Nn][Dd] ;
SINE            : [Ss][Ii][Nn] ;
SQUARE_ROOT     : [Ss][Qq][Rr][Tt] ;
TANGENT         : [Tt][Aa][Nn] ;
ARC_TANGENT     : [Aa][Tt][Aa][Nn] ;

PARAMETER_SIGN : '#' ;
EQUAL_SIGN     : '=' ;

COMMENT
    : '(' ~(')')* ')'
    | ';' ~[\r\n]*
    ;

EOL
    : '\r'
    | '\n'
    | '\r\n'
    ;

WS
    : [ \t]+ -> skip
    ;