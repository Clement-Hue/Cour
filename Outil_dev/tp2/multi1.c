/*@ requires a >=0 ;
    requires b >= 0;
    ensures \result == a * b ;
    */
int mult1(int a, int b){
    int y = b;
    int z = 0;
    /*@
	loop invariant y >= 0;
	loop assigns z,y;
	loop variant y;
      */
    while (y!=0){
        z = z+a;
        y = y-1;
    }
    return z;
 }

