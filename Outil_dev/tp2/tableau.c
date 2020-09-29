/*@ requires size >=0; 
ensures  \forall int i; 0 <= i <= size-1  ==> t[i] == v;
assigns t[0..(size-1)] ;*/
void init(int t[] , int size , int v){
    int i;
	/*@ 
	loop invariant i >=0;
	*/
    for (i=0; i < size; i++) { t[i] = v ;}
 }

