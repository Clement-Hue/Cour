#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a,b,c;
    int delta;
    int x1,x2;
    printf("Entrez les valeur de a,b et c\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    delta = pow(b,2) - 4 * a * c;
    if (delta > 0){
        x1 = (-b + sqrt(delta))/ (2*a);
        x2 = (-b - sqrt(delta))/ (2*a);
        printf("x1 = %d, x2 = %d\n",x1,x2);
    }
    else if (delta == 0){
        x1 = -b / (2*a);
        printf("x = %d",x1);
    }
    else{
        printf("pas de résultat");
    }
    return 0;
}