#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;
    printf("Entrez un caractère\n");
    scanf("%c",&c);
    printf("le caractère est %c, en décimal: %d, en hexa %x\n ", c,c,c);
    return 0;
}