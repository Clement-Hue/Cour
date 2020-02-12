#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "automate.h"


int main(int argc, char *argv[]){
    FILE* pFile;
    char * fichier  = (argc == 1) ? "fichier.html" : argv[1];
    if ( (pFile = fopen(fichier,"r")) == NULL ){
        printf("erreur d'ouverture de fichier\n");
        return -1;
    }
    automate(pFile);
    fclose(pFile);
    return 0;
}

