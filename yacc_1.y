%{
#include <stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *);
%}

%token a b NL
%start S

%% 
S: A b NL { printf("Valid String\n"); exit(0); }
  | error NL { yyerror("Invalid String"); exit(1); }
;

A: a A
  | /* empty */
; 
%%

void yyerror(const char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main()
{
    yyparse();
    return 0;
}
