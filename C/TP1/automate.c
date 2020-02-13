#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automate.h"
#include "utils.h"

int automate( FILE* pFile){
    char c;
    char balise_pile[NB_BALISE][TAILLE_CHAINE];
    char balise_fermante[TAILLE_CHAINE];
    int i = 0, j = 0, f = 0;
    enum Etat etat = HORS_BALISE; 
    init_matrice(balise_pile);
    clean_chaine(balise_fermante);
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
                    if (strcmp(balise_fermante,balise_pile[j-1]) != 0){
                        return 0; // il y'a une erreur
                    }
                    else{
                        j--; // on dépile
                        clean_chaine(balise_pile[j]);
                    }
                    f= 0;
                    clean_chaine(balise_fermante);
                }
                else{
                    balise_fermante[f] = c;
                    f++;
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
    return 1;
}