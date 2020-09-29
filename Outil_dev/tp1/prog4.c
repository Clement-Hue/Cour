#include<stdio.h>

int abs(int x){
  if (x >= 0 ) return x ;
  return -x ;
}

int main(void){
  int r = getchar() / 2 ;
  r = abs(r) ;
  return (1/ (r+1)) ;
}

