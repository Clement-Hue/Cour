#include <stdio.h>
#include <stdlib.h>
#include "analyse.h"

int main(int argc, char *argv[]){
    FILE* pFile;
    char * fichier  = (argc == 1) ? "fichier.html" : argv[1];
    char c;
    char balise_pile[NB_BALISE][TAILLE_CHAINE];
    int i = 0, j = 0;
    enum Etat etat = HORS_BALISE; 
    init_matrice(balise_pile);
    if ( (pFile = fopen(fichier,"r")) == NULL ){
        printf("erreur d'ouverture de fichier\n");
        return -1;
    }
    for (c=fgetc(pFile); !feof(pFile); c = fgetc(pFile) ){
        switch(etat){
            case BALISE:
                if (c== '/'){
                    etat = BALISE_FERMANTE; 
                }
                else{
                    etat = BALISE_OUVRANTE;
                    balise_pile[j][i] = c;
                    i++; // on passe à la lettre suivante de la balise
                }
                break;
            case BALISE_OUVRANTE:
                if (c == ' '|| c== '>'){
                    etat = HORS_BALISE ;
                    i = 0;
                    j++; // on passe à la balise suivante
                }
                else{
                    balise_pile[j][i] = c;
                    i++; // on passe à la lettre suivante de la balise
                }
                break;
            case BALISE_FERMANTE:
                if (c== '>'){
                    etat = HORS_BALISE ;
                }
                break;
            case HORS_BALISE:
                if (c == '<'){
                    etat = BALISE; 
                }
                break;
            default:break;
        }
    }
    afficher_matrice(balise_pile);
    fclose(pFile);
    return 0;
}


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