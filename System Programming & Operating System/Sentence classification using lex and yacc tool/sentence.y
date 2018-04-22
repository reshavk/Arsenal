%token COMP
%token SIMP

%%
S : COMP {compound();}
  | SIMP {simple();}
  ;
%%


#include "stdio.h"
#include "lex.yy.c"

int main() {
	printf("Enter the sentence to be evaluated : ");
	yyparse();
}

void compound() {
	printf("COMPOUND STATEMENT\n");
}

void simple() {
	printf("SIMPLE STATEMENT\n");
}
