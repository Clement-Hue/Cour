/*@ requires a >= 0;  ensures \result == a + b ; */
int add (int a,int b){
	int x = a ;
	int y = b ;
	/*@ loop invariant x+y == a+b ; 
	loop invariant x>= 0;
	loop assigns x, y; 
	loop variant x  ;*/

	while (x != 0){
		x = x - 1 ;
		y = y + 1 ;
	}
	return y;
}
