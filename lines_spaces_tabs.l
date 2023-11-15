%{
	#include<stdio.h>
	#include<stdlib.h>
	int li=1;
	int sp=0;
	int tb=0;
%}
%%
([\n]) {li++;}
([ ]) {sp++;}
([\t]) {tb++;}
([.]) {return 0;}
([^ \n\t.]) {}
%%
int yywrap(void){}
int main()
{	printf("Enter the Sentence:");
	yylex();
	printf("Number of lines, spaces, tabs are %d %d %d",li,sp,tb);
	return 0;
}