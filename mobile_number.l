%{
#include<stdio.h>
#include<string.h>
%}

%%
([1-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]) {printf("Entered one can be a Mobile Number");return 0;}
(.*) {printf("Entered one is not a mobile number");return 0;}
%%

int yywrap(void){}

int main()
{
	// The function that starts the analysis
	printf("Enter Mobile Number:");
	yylex();

	return 0;
}
