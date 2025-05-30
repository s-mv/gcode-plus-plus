// PS: adapted from -
// https://github.com/grwhitehead/rs274ngc-python3/blob/33f63d3dd2d8166a9a9931a76ce3f1c93d6c7078/GCode.g4
//

lexer grammar lexer_antlr4;

// >>> language extensions

IF : I F ;
THEN : T H E N ;
DO : D O ;
WHILE : W H I L E ;
FOR : F O R ;
FROM : F R O M ;
TO : T O ;
ELSE : E L S E ;
END : E N D ;
BREAK : B R E A K ;
CONTINUE : C O N T I N U E ;

// <<< language extensions

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

MODULO : M O D ;

TIMES : '*' ;

LOGICAL_AND : A N D ;
EXCLUSIVE_OR : X O R ;
NON_EXCLUSIVE_OR : O R ;

EQ  : E Q ;
NE  : N E ;
LT  : '<' ;
LE  : '<=' ;
GT  : '>' ;
GE  : '>=' ;

ABSOLUTE_VALUE  : A B S ;
ARC_COSINE      : A C O S ;
ARC_SINE        : A S I N ;
COSINE          : C O S ;
E_RAISED_TO     : E X P ;
FIX_DOWN        : F I X ;
FIX_UP          : F U P ;
NATURAL_LOG_OF  : L N ;
ROUND_OPERATION : R O U N D ;
SINE            : S I N ;
SQUARE_ROOT     : S Q R T ;
TANGENT         : T A N ;
ARC_TANGENT     : A T A N ;

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

fragment A : [Aa] ;
fragment B : [Bb] ;
fragment C : [Cc] ;
fragment D : [Dd] ;
fragment E : [Ee] ;
fragment F : [Ff] ;
fragment G : [Gg] ;
fragment H : [Hh] ;
fragment I : [Ii] ;
fragment J : [Jj] ;
fragment K : [Kk] ;
fragment L : [Ll] ;
fragment M : [Mm] ;
fragment N : [Nn] ;
fragment O : [Oo] ;
fragment P : [Pp] ;
fragment Q : [Qq] ;
fragment R : [Rr] ;
fragment S : [Ss] ;
fragment T : [Tt] ;
fragment U : [Uu] ;
fragment V : [Vv] ;
fragment W : [Ww] ;
fragment X : [Xx] ;
fragment Y : [Yy] ;
fragment Z : [Zz] ;
