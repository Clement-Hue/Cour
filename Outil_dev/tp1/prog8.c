#include<stdio.h>

int credit = 0 ;
int tmp    = 1 ;
int tmp2   = 2 ;

void depot(int v){
  printf("Demande de dépôt : %i\n", v) ;
  credit += v ;
  printf ("Depôt effectué, nouveu crédit =%i\n", credit);
}

int retrait(int v){
  printf("Demande de retrait : %i\n", v) ;
  if (credit >= v) {
    credit -= v ;
    printf ("Retrait effectué, nouveau crédit =%i\n", credit);
    return 1 ;
  }
  else {
    printf ("Crédit insuffisant, débit refusé\n");
    return 0 ;
  }
}

int main(void){
  int result ;
  depot(getchar());
  depot (tmp2);
  tmp2+=tmp;
  result = retrait(getchar());
  return result ;
}

