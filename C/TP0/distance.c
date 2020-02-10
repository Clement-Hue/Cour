#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x1,y1,x2,y2;
    int dist;
    x1 = 5;
    y1 =10;
    x2 = 4;
    y2= 8;
    dist = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    printf("la distance est %d\n",dist);
    return 0;
}