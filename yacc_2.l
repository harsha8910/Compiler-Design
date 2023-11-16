%{
#include "yacc_2.tab.h"
void yyerror(const char *);
%}

%%
[a] { return a; }
[b] { return b; }
\n { return NL; }
.  { 
    yyerror("Invalid character encountered");
    exit(1);
}

%%

int yywrap() {
    return 1;
}
