#ifndef PILE
#define PILE


enum Etat {
    BALISE,
    BALISE_OUVRANTE,
    BALISE_FERMANTE,
    HORS_BALISE
};

void automate(FILE*);

#endif