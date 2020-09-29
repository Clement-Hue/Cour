int x;
int y;

/*@ ensures x == \old(y) && y == \old(x) ; */
void swap(){
	x=y;
	y=x;
}
