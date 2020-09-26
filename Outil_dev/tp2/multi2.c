/*@ requires b >= 0; */
 int mult2(int a, int b){
    int x = a;
    int y = b;
    int z = 0;
    /*@
	loop invariant y >= 0;
	loop invariant z == a*b;
     loop variant y;
	*/
   while (y!=0){
        if (y % 2 == 0) { 
    	    y = y/2;
    	    x = x*2;
    	}
        else {
            z = z+x;
    	    y = y-1;
        }
    }
    return z;
 }

