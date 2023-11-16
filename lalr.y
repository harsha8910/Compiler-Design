%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex(void);
	void yyerror(const char *s);
%}

%token DIGIT
%token PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN EOL
%token UMINUS  // Add this line to declare UMINUS

%start S

%left PLUS MINUS
%left MULTIPLY DIVIDE
%left UMINUS

%%


S: E EOL   { printf("Result: %d\n", $1);return 0; }
    ;

E: E PLUS E   { $$ = $1 + $3; }
 | E MINUS E  { $$ = $1 - $3; }
 | E MULTIPLY E { $$ = $1 * $3; }
 | E DIVIDE E  { $$ = $1 / $3; }
 | MINUS E %prec UMINUS { $$ = -$2; }
 | LPAREN E RPAREN { $$ = $2; }
 | DIGIT       { $$ = $1; }
 ;

%%

void yyerror(const const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

int main() {
    printf("Enter input : ");
    yyparse();
    return 0;
}