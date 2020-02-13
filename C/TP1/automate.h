#ifndef AUTOMATE 
#define AUTOMATE 


enum Etat {
    BALISE,
    BALISE_OUVRANTE,
    BALISE_FERMANTE,
    HORS_BALISE
};

int automate(FILE*);

#endif