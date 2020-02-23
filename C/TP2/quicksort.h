#ifndef QUICKSORT
#define QUICKSORT
#include <stdbool.h>

#define TAILLE 20

enum Tri {
    CROISSANT,
    DECROISSANT,
    PAIRE,
    IMPAIRE
};

void afficher_tableau(int[TAILLE]);
void init_tableau(int*);
bool test_tri(int*);
void quickSort(int *, enum Tri , int ,int , bool (*)(int,int));
void sort(int*, enum Tri);
int partition(int* , enum Tri ,int ,int , bool (*)(int,int));
bool croissant(int,int);
bool decroissant(int,int);
bool paire(int,int);
bool impaire(int,int);


#endif