%{
#include <stdio.h>
%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return" {
    printf("\nKeyword: %s", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("\nIdentifier: %s", yytext);
}

[0-9]+ {
    printf("\nInteger: %s", yytext);
}

"=="|"<"|">"|"<="|">="|"!=" {
    printf("\nRelational Operator: %s", yytext);
}

"/*" {
    while (1) {
        char c = input();
        if (c == EOF) {
            fprintf(stderr, "Unmatched multi-line comment.\n");
            break;
        }
        if (c == '*' && input() == '/') {
            break;
        }
    }
}

. ; // Ignore other characters

%%
int yywrap(void) {
}

int main() {
    yylex();
    return 0;
}

