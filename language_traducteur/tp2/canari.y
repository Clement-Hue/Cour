%token CANARI POINT GN VI VT

%%
S: PH POINT;
PH: GN VI | GN VT GN;
%%

#include <stdio.h>
#include "lex.yy.c"

int main() {
    if (yyparse() == 0) printf("Chaine OK\n");
    else prinf("Chaine KO\n");
    return 0;
}

int yyerror(char *s) {
    printf("%s\n",s);
    return 0;
}
