%{
#include "lalr.tab.h"
%}

%%

[0-9]+              { yylval = atoi(yytext); return DIGIT; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULTIPLY; }
"/"                 { return DIVIDE; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
\n                  { return EOL; }
"UMINUS"            { return UMINUS; }  // Add this line to define UMINUS
[ \t]               ;  // Skip whitespace

.                   { fprintf(stderr, "Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}