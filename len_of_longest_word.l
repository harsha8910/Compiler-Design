%{
	#include<stdio.h>
	int max=0;
%}

%%
([a-zA-Z]+) {if(max<yyleng){max=yyleng;}}
([.]) {return 0;}
%%
int yywrap(void){}
int main()
{
	printf("Enter the Words:");
	yylex();
	printf("Length of the Longest Word is %d",max);
	return 0;
}