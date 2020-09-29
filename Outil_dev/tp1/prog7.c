#include<stdio.h>

int abs(int x){
  if (x >= 0 ) return x ;
  else return -x ;
}

int main(void){
  int r = getchar() ;
  r = abs(r) ;
  if (r<0) return -1;
  else return r ;
}

