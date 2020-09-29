int x;
int y; 

/*@ ensures x == \old(y) && y == \old(x) ;*/
void swap(){
	int aux = x;
	x=y;
	y=aux;
}
