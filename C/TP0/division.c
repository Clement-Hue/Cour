#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b;
    printf("Entrez deux nombre:\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%f\n",(float)a/b);
    printf("%d\n",a/b);
    printf("reste: %d\n",a%b);
    return 0;
}