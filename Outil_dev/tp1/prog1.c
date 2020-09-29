int main(void){
  int x = 0 ;
  int* y = &x ;
  x = *y + 1 ;
  y = y + x ;
  return *(y-1) ;
}
