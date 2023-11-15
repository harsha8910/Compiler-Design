%{
	#include<stdio.h>
%}
%%
([0-9]+[02468]) {printf("Entered Number is Even Number");return 0;}
([0-9]+[13579]) {printf("Entered Number is Odd Number");return 0;}
%%
int yywrap(void) {}
int main()
{
	printf("Enter a number:");
	yylex();
	return 0;
}