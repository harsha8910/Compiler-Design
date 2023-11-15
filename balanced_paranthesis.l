%{
	#include<stdio.h>
	int l=0;
	int r=0;
	int k=0;
%}

%%
([(]) {l++;}
([)]) {if(l-r>0){r++;}else{k=1;}} 
([ \n\t]) {return 0;}
%%
int yywrap(void) {}
int main()
{
	printf("Enter the String:");
	yylex();
	if(l==r && k==0)
	{
		printf("Balanced");
	}
	else
	{
		printf("Not Balanced");
	}
	return 0;
}
