%token LE UN LA UNE CANARI CHAT SOURIS 
%token TITI GROSMINET COURT VOLE MANGE DETESTE
%token POINT ERREUR
%start S 
%{
  int errSem = 0;
  int yyerror(char *s);
  int yylex();
  // marche sans les prototypes avec ou sans warnings
%}
%%
PH : GN VI | GN VT GN {if ($1!=$2) errSem=1;} ;
S : PH POINT;
GN : NP | AR NC;
NP : TITI | GROSMINET;
AR : LE {$$=1;} | UN {$$=1;} | LA {$$=2;} |UNE {$$=2;};
NC : CANARI {$$=1;} | CHAT {$$=1;} | SOURIS {$$=2;};
VI : COURT | VOLE;
VT : MANGE | DETESTE;
%%
#include "lex.yy.c"
#include <stdio.h>

int main(){
   if (yyparse() != 0) printf("Chaine syntaxiquement incorrecte\n");
                 else {printf("Chaine syntaxiquement correcte\n");
				       if (errSem) printf("Chaine semaniquement incorrecte\n");
					          else printf("Chaine semaniquement correcte\n");
					  }
   return 0;
}

int yyerror(char *s) {
   printf("%s pres de %s\n", s, yytext);
   return 0;
}