%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%%
([0|1]*00) {printf("String accepted");return 0;}
. {printf("String not accepted");return 0;}
%%
int yywrap(void) {}
int main()
{
	printf("Enter the binary String:");
	yylex();
	return 0;
}