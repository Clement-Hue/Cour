int x;
int y;

/*@ ensures x == \old(y) && y == \old(x) ; */
void main(){
	x=x+y;
	y=x-y;
	x=x-y;
}
