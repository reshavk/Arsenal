%{
#include<stdio.h>
int l = 0, w = 0, c = 0; 
%}

%%
[\n]		{l++;}
[^\n\t ]+	{w++; c += yyleng;}

%%

int yywrap(void) {
	return 1;
}

int main() {
	FILE *fp = fopen("input.java", "r");
	yyin = fp;
	yylex();
	
	printf("\n");
	printf("Total Lines : %d\n", l);
	printf("Total words : %d\n", w);
	printf("Total charachters : %d\n", c);
	
	return 0;
}
