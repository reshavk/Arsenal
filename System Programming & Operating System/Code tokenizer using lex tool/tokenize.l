%{
#include<stdio.h>
%}

%%
[ \t]+		;
import[ \t]+[a-zA-Z0-9_\.]+[\.\*]?[;]		printf("%s is an IMPORT statement\n", yytext);
public|static|void|main|class|System.out.println|if|for|while|do		printf("%s is a KEYWORD\n", yytext);
int|float|double|long		printf("%s is a DATATYPE DECLARATION\n", yytext);
[=]		printf("%s is an ASSIGNMENT OPERATOR\n", yytext);
[\+\-\*/]		printf("%s is an ARITHMETIC OPERATOR\n", yytext);
[&&|!=|==|\|\|]		printf("%s is LOGICAL OPERATOR\n", yytext);
[\<|\>|\>=\<=]		printf("%s is a RELATIONAL OPERATOR\n", yytext);
[\{|\}|\[|\]|\(|\)|,|;]		printf("%s is a SPECIAL SYMBOL\n", yytext);
[0-9]		printf("%s is an INTEGER constant\n", yytext);
["][^\n\t]+["]		printf("%s is a STRING CONSTANT\n", yytext);
[_a-zA-Z][a-zA-Z0-9_]*		printf("%s is an IDENTIFIER\n", yytext);
%%

int yywrap(void) {
	return 1;
}

int main() {
	FILE *fp = fopen("input.java", "r");
	yyin = fp;
	yylex();
}
