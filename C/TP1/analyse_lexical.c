#include <stdio.h>
#include <stdlib.h>

#define  NB_BALISE 100 
#define  TAILLE_CHAINE 20

void afficher_matrice(char matrice[NB_BALISE][TAILLE_CHAINE] );

enum Etat {
    BALISE,
    HORS_BALISE,
};

int main(){
    FILE* pFile;
    char c;
    char balise_pile[NB_BALISE][TAILLE_CHAINE];
    int i = 0, j = 0;
    enum Etat etat; 
    if ( !(pFile = fopen("fichier.html","r")) ){
           printf("erreur d'ouverture de fichier");
        return -1;
    }
    for (c=fgetc(pFile); !feof(pFile); c = fgetc(pFile) ){
        if (c == '<'){
            etat = BALISE; 
            c = fgetc(pFile);
            if (c == '/'){
                etat = HORS_BALISE;
            }
        }
        if (etat == BALISE && c == ' '){
            etat = HORS_BALISE ;
            i = 0;
            j++;
        }
        if (etat == BALISE){
            balise_pile[j][i] = c;
            i++;
        }
    }
    afficher_matrice(balise_pile);
    fclose(pFile);
    return 0;
}


void afficher_matrice(char  matrice [NB_BALISE][TAILLE_CHAINE]){
    for (int i = 0 ;i<NB_BALISE;i++){
        for (int j = 0; j< TAILLE_CHAINE;j++){
            printf("%c",matrice[i][j]);
        }
    }
}