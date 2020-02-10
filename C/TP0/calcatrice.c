#include <stdio.h>
#include <stdlib.h>

int main(){
    char c ;
    int nb1 = 0, nb2 = 0;
    while (c = getchar() ){
        if (c >= '0' && c <= '9' ){
            c = c - '0';
            nb1 = nb1 + c; 
        }
    }
    return 0;
}