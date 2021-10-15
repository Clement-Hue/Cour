%{
#include <stdio.h>
#include <stdlib.h>
int res;
%}

%token AFFICH PLUS MOINS MULT DIV NB PO PF

%%
S: AFFICH PO E PF {printf("Resultat: %d\n", $3);};
E: T PLUS E {$$=$1+$3;} | T MOINS E {$$=$1-$3;} | T {$$=$1;};
T: F MULT T {$$=$1*$3;} | F DIV T {$$=$1/$3;} | F {$$=$1;};
F: PO E PF {$$=$2;} | 
    NB {$$ = atoi(yytext);};
%%

#include <lex.yy.c>

int main() {

}