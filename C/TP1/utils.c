#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void afficher_matrice(char  matrice [NB_BALISE][TAILLE_CHAINE]){
    for (int i = 0 ;i<NB_BALISE;i++){
        printf("%s\n",matrice[i]);
    }
}

void init_matrice(char  matrice [NB_BALISE][TAILLE_CHAINE]){
    for (int i = 0 ; i < NB_BALISE; i++){
        for (int j = 0; j < TAILLE_CHAINE; j++){
            matrice[i][j] = 0;
        }
    }
}

void clean_chaine(char* chaine){
    for (int i=0;i<TAILLE_CHAINE;i++){
        chaine[i] = 0;
    }
}