#ifndef QUICKSORT
#define QUICKSORT
#include <stdbool.h>

#define TAILLE 20
void afficher_tableau(int[TAILLE]);
void init_tableau(int*);
bool test_tri(int*);
void quickSort(int*,int,int);
void sort(int*);
int partition(int*,int,int);


#endif