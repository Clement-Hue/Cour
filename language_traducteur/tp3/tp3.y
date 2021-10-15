%token SI ALORS PROGRAMME DECLARE NATUREL CARACTERE BOOLEEN 
%token DEBUT FIN SINON FSI TANTQUE FAIRE FTQ OBTENIR AFFICHER
%token AFFICHAINE ALALIGNE OU ET NON VRAI FAUX NOMBRE IDENT CAR CHAINE
%token PF PO PLUS MINUS MULT DIVIDE EQUAL LESS LESS_EQUAL MORE MORE_EQUAL
%token EQUAL_EQUAL NOT_EQUAL PV POINT
%start PROG
%{
  #include <stdio.h>
  FILE * FC;
  int errSem = 0;
  int yyerror(char *s);
  int yylex();
  int nid = 0;
  char * nomid[100];
  int typeid[100];
  int present(int nid, char * nomid[], char * nom);
  int getIdentType(int nid, char * nomid[], char * nom, int typeid[]);
  int ajout(int nid, char * nomid[], int typeid[], char * nom, int typeident);
  extern char * yytext;
  int tid;
  // marche sans les prototypes avec ou sans warnings
%}

%%
PROG: ENTETE BLOCK POINT ;
ENTETE: PROGRAMME IDENT PV;
BLOCK: P_DEC P_INSTR;
P_INSTR: DEBUT L_INSTR FIN POINT;
P_DEC: DECLARE L_DEC;
L_DEC: UNE_DEC L_DEC | ;
L_INSTR: UNE_INSTR S_INSTR;
UNE_INSTR: AFFECT | COND | TQ | LIRE | ECRIRE | ECRCH | LIGNE;
AFFECT: IDENT  {tid = getIdentType(nid, nomid, yytext, typeid);}  EQUAL EXP PV   {if (tid != $4) errSem =1;}   ;
COND: SI EXP ALORS L_INSTR S_COND FSI PV {if ($2 != 2) errSem =1;}  ;
S_COND: SINON L_INSTR | ;
TQ: TANTQUE EXP FAIRE L_INSTR FTQ PV {if ($2 != 2) errSem =1;};
LIRE: OBTENIR PO IDENT PF PV; 
ECRIRE: AFFICHER PO EXP PF PV;
ECRCH: AFFICHAINE PO CHAINE {fprintf(FC, "printf(%s); \n", yytext);}  PF PV;
LIGNE: ALALIGNE PV {fprintf(FC, "printf(\"\\n\");\n");} ;
EXP: EXP OP_REL EXPS  {if ($1 != $3 ) errSem=1; $$ = 2;}  | EXPS;
EXPS: EXPS OP_ADD TERME  {if ($1 != $2 || $2 != $3) errSem=1; $$=1;} | TERME;
TERME: TERME OP_MULT FACT {if ($1 != $2 || $2 != $3) errSem=1; $$=1;} | FACT;
FACT:  PO EXP PF {$$ = $2;} | VRAI {$$=2; fprintf(FC, " 1 ");} | FAUX  {$$=2; fprintf(FC, " 0 ");}| NOMBRE {$$=1; fprintf(FC, " int ");} | CAR {$$=3; fprintf(FC, "\'%c\'", $1);}| IDENT {$$= getIdentType(nid, nomid, yytext, typeid);fprintf(FC, " %s ",yytext);} | NON {fprintf(FC, "!");} FACT {if ($3 != 2) errSem=1; $$=2;};
OP_REL: LESS {fprintf(FC, " < ");} | LESS_EQUAL {fprintf(FC, " <= ");}  | MORE {fprintf(FC, " > ");} | MORE_EQUAL {fprintf(FC, " >= ");} | NOT_EQUAL {fprintf(FC, " != ");} | EQUAL_EQUAL {fprintf(FC, " == ");} ;
OP_ADD: OU {$$=2; fprintf(FC, " || ");} | PLUS {$$=1; fprintf(FC, " + ");} | MINUS {$$=1;  fprintf(FC, " - ");};
OP_MULT: ET {$$=2; fprintf(FC," && ");} | MULT {$$=1; fprintf(FC," * ");} | DIVIDE {$$=1; fprintf(FC," / ");};
S_INSTR: L_INSTR | ;
UNE_DEC: TYPE IDENT { nid = ajout(nid, nomid, typeid, yytext, $1); fprintf(FC, " %s;\n",yytext);}  PV ;
TYPE: NATUREL {$$=1;fprintf(FC,"int"); } | BOOLEEN {$$=2; fprintf(FC,"int");}| CARACTERE {$$=3; fprintf(FC,"char");};

%%
#include "lex.yy.c"

void printTable() {
    for (int i = 0; i <nid; i++) {
       printf("%d %s \n", typeid[i], nomid[i]);
    }
}

int main(){
   FC = fopen("progC.txt","w");
   fprintf(FC, "#include <stdio.h>\n");
   fprintf(FC, "int main() {\n");
   if (yyparse() != 0) printf("Chaine syntaxiquement incorrecte\n");
   else 
    { 
       printf("Chaine syntaxiquement correcte\n");
       if (errSem) printf("Chaine semaniquement incorrecte\n");
       else printf("Chaine semaniquement correcte\n");
    }
   fprintf(FC, "return 0;\n}\n");
   fclose(FC);
   return 0;
}


int yyerror(char *s) {
   printf("%s ligne %d pres de %s\n", s,nbLign, yytext);
   return 0;
}



int present(int nid, char * nomid[], char * nom) {
   for (int i = 0; i < nid; i++) 
      if (strcmp(nomid[i], nom) == 0) 
         return 1;
   return 0;
}

int ajout(int nid, char* nomid[], int typeid[] , char* nom, int typeident) {
   if (present(nid, nomid, nom)) {
      printf("Error duplicate varaible %s", nom );
      return 0;
   }
   nomid[nid] = malloc(strlen(nom + 1) * sizeof(char));
   strcpy(nomid[nid], nom);
   typeid[nid] = typeident;
   return nid + 1;
}

int getIdentType(int nid, char * nomid[], char * nom, int typeid[]) {
   for (int i = 0; i < nid; i++) 
      if (strcmp(nomid[i], nom) == 0) 
         return typeid[i];
   errSem = 1;
   return 0;
}