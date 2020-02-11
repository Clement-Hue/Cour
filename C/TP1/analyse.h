#ifndef ANALYSE
#define ANALYSE

#define NB_BALISE 100 
#define TAILLE_CHAINE 20

void afficher_matrice(char [NB_BALISE][TAILLE_CHAINE] );
void init_matrice(char [NB_BALISE][TAILLE_CHAINE] );
void clean_chaine(char*);

enum Etat {
    BALISE,
    BALISE_OUVRANTE,
    BALISE_FERMANTE,
    HORS_BALISE
};


#endif