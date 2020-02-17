#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "quicksort.h"



int main(){
    int tab[TAILLE] ;
    init_tableau(tab);
    printf("avant\n");
    afficher_tableau(tab);
    sort(tab);
    printf("après\n");
    afficher_tableau(tab);
    if (test_tri(tab)){
        printf("le tableau est trié\n");
    }
    else{
        printf("le tablleau n'est pas trié\n");
    }
    return 0;
}

void afficher_tableau(int tab[]){
    for (int i = 0 ; i<TAILLE; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void init_tableau(int *tab){
    srand(time(NULL));
    for (int i = 0;i<TAILLE;i++){
       tab[i] = rand() % 100;
    }
}

bool test_tri(int *tab){
    for (int i = 0;i<TAILLE-1;i++){
        if (tab[i] > tab[i+1]){
           return false; 
        }
    }
    return true;
}

void sort(int*tab){
    quickSort(tab,0,TAILLE-1);
}

void quickSort(int *tab, int L,int R){
    if (L>=R)
        return;
    int pivot = partition(tab,L,R);
    quickSort(tab,L,pivot-1); 
    quickSort(tab,pivot+1,R);
}

int partition(int *tab,int L,int R){
    int pivot = tab[L];
    int index_pivot = L;
    int temp = 0;
    L++;
    while  (L<=R){
        if (tab[L] <= pivot)
            L++;
        else{
            temp = tab[L];
            tab[L] = tab[R];
            tab[R] = temp;
            R--;
        }
    }
    temp = tab[index_pivot];
    tab[index_pivot] = tab[R];
    tab[R] = temp;
    return R;
}