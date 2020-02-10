#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    int error = 0;
    do {
        while ((c = getchar()) != '\n'){
            if (!(c >= '0' && c <= '9')){
                printf("erreur\n");
                error = 1;
                break;
            }
        printf("%c",c);
        error = 0;
        }
    }while(error);
    return 0;
}