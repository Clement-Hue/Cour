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
void quickSort(int *, enum Tri , int ,int , bool (*)(int,int,enum Tri));
void sort(int*, enum Tri);
int partition(int* , enum Tri ,int ,int , bool (*)(int,int,enum Tri));
bool comparaison(int,int,enum Tri);

#endif