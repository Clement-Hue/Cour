#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "quicksort.h"



int main(){
    int tab[TAILLE] ;
    enum Tri tri;
    init_tableau(tab);
    printf("avant\n");
    afficher_tableau(tab);
    printf("Entrer 0 pour croissant 1 pour décroissant 2 pour paire\n");
    scanf("%d",&tri);
    sort(tab,tri);
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

void sort(int*tab, enum Tri tri){
    bool (*comp)(int,int,enum Tri) = comparaison;
    quickSort(tab,tri,0,TAILLE-1,comp);
}

void quickSort(int *tab, enum Tri tri, int L,int R, bool (*comp)(int,int,enum Tri)){
    if (L>=R)
        return;
    int pivot = partition(tab,tri,L,R,comp);
    quickSort(tab,tri,L,pivot-1,comp); 
    quickSort(tab,tri,pivot+1,R,comp);
}

int partition(int *tab, enum Tri tri ,int L,int R, bool (*comp)(int,int,enum Tri)){
    int pivot = tab[L];
    int index_pivot = L;
    int temp = 0;
    L++;
    while  (L<=R){
        if ((*comp)(tab[L],pivot,tri))
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

bool comparaison(int elem,int pivot, enum Tri tri){
    switch(tri){
        case CROISSANT:
            if (elem <= pivot)
                return true;
            else
                return false;
            break;
        case DECROISSANT:
            if (elem >= pivot)
                return true;
            else 
                return false;
            break;
        case PAIRE:
            if (elem %2 == pivot %2)  
                return elem <= pivot;
            else if (elem%2 == 0)
                return true;
            else 
                return false;
            break; 
        default: break;
    }
}