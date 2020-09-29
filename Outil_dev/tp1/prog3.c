int y = 3;
int *x = &y;

int incr(){
  return *x + 1 ;
}

int main(){
  return incr() ;
}
