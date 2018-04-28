%token KEYWORD
%token TYPE
%token ID
%token ASSIGN
%token IC
%token SC
%left ','

%%
S : KEYWORD {keyword();} TYPE {type();} E ';' 
  | TYPE {type();} E ';' 
  ;
E : E ',' E
  | ID {id();} ASSIGN R
  | ID {id();}
  ;
R : IC {ic();}
  | SC {sc();} 
  ;

%%

#include "stdio.h"
#include "lex.yy.c"

int main() {
	printf("Enter the decalartion statement to be validated : ");
	yyparse();
}

void keyword() {
	printf("%s is a KEYWORD\n", yytext);
}

void id() {
	printf("%s is an IDENTIFIER\n", yytext);
}

void type() {
	printf("%s is a DATA TYPE DECLARATION\n", yytext);
}

void ic() {
	printf("%s is a INTEGER CONSTANT\n", yytext);
}

void sc() {
	printf("%s is a STRING CONSTANT\n", yytext);
}

void yyerror() {
	printf("Invalid Declaration\n");
}
