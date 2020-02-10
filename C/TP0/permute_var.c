#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c;
    int tmp;
    printf("entrez a,b et c\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    tmp = a;
    a = b;
    b = c;
    c = tmp; 
    printf("a: %d, b: %d, c: %d\n",a,b,c);
    return 0;
}