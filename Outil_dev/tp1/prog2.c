#include <stdio.h>

int main(){
  int t[5] = {1,2,3,4,5};
  int cpt ;
  for (cpt=0 ; cpt<=5 ; cpt++){
    if ( t[cpt] < getchar() )
		return (cpt/t[cpt]);
  }
  return 10 ;
}
