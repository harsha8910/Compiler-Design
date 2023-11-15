%{
	#include<stdio.h>
	#include<stdlib.h>
	int n = 0;
%}

%%
("while"|"if"|"else") {n++;}
("int"|"float") {n++;}
([a-zA-Z_][a-zA-Z0-9_]*) {n++;}
("<="|"=="|"="|"++"|"-"|"*"|"+") {n++;}
([ () {}|, ;.]) {n++;}
([0-9]*"."[0-9]+) {n++;}
([0-9]+) {n++;}
([\n]) {return 0;}
%%

int yywrap(void) {}
int main()
{
    printf("Enter the String:");
    yylex();
    printf("\nTotal number of tokens = %d", n);
    return 0;
}