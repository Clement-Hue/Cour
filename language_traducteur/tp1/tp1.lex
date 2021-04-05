%{
    int nbMot = 0, nbCar=0, nblig=0, nbNb=0, nbSILR = 0;
%}


%%
[A-Za-z]+ {nbMot ++; nbCar+=yyleng; }
[0-9]+(\.[0-9]+)?(E(\+|\-)?[0-9]+)?      {nbNb++; nbCar+=yyleng;}
.   {nbCar++;}
\n  {nblig++; nbCar++;}
.*S.*I.*L.*R {nbSILR ++;}

%%
#include <stdio.h>
int main() {
    yylex();
    printf("mot %d car %d, lig %d silr %d", nbMot, nbCar, nblig, nbSILR);
    return 0;
}