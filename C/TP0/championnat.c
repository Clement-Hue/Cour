#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,J,M;
    int N1, nbJourChamp, nbMatchJour;
    printf("Entrez le nombre d'équipe\n");
    scanf("%d",&N);
    if (N%2 == 0){
        N1 = N;
    }
    else {
        N1 = N + 1;
    }
    nbJourChamp = N1 -1;
    nbMatchJour = N1/2;
    for (J = 0 ; J < nbJourChamp; J ++){
        for (M = 0; M < nbMatchJour; M ++){
            if (M == 1){
               printf("Equipe qui recçoit: %d\n",(N%2 ==0) ? N : 0  );
            }
            else if (M > 1){
               printf("Equipe qui recçoit: %d\n", ((J + M -2) % (N1 -1) ) + 1);
            }
            printf("Equipe en déplacement:%d\n", ( (J-M + N1 -1) % (N1-1) ) + 1);
        }
    }
    return 0;
}