%start axiome

%%
axiome: phrase POINT {$$=$1; genre=$$};;
phrase : gnominal vtrance gnominal vtrance
        {if (($1==OK) && ($3==OK))  $$=OK; else $$=KO;} |
        gnominal vintrans ($$=$1;);
gnominal: npropre {$$=OK;} |
        article ncommun {if ($1==$2)}
%%

#include <stdio.h>
#include "lex.yy.c"

main() {
    if (yyparse() == 0) {

    }
}