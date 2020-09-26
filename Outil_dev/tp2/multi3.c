int pair (int x){
	return (x % 2 == 0);
}

/*@ requires a >= 0;
 requires b >= 0; */
int mult3(int a, int b){
// from M. Wand 1980, p170
	int x = a;
	int y = b;
	int z = 0;
	/*@ 
	 loop invariant y >= 0;
	loop variant y;
	 */
	while (y!=0){
	  if (pair (y)) { 
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

