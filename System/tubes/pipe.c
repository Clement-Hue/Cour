#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "pipe.h"

int main(){
    char chaine[TAILLE_MAX];
    int  tube[2];
    int pid;
    if (pipe(tube)){
        printf("erreur ouverture du pipej\n");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    creation_pipe(pid,tube,chaine);
    return 0;
}

void creation_pipe(int pid,int tube[2], char *chaine){
    switch (pid){
        case -1:
            printf("Erreur lors du fork\n");
            exit(EXIT_FAILURE);
        case 0: // processus fils
            close(tube[OUT]);
            for (int i = 0 ;i<10; i++){
                read(tube[IN],chaine,TAILLE_MAX);
                printf("Reception de %s\n",chaine);
            }
            break;
        default: // processus père
            close(tube[IN]); // fermeture de l'entrée
            for (int i = 0; i<10; i++){
                sprintf(chaine,"je suis le numéro %i\n",i);
                write(tube[OUT],chaine,TAILLE_MAX);
                printf("Emission de %s\n",chaine);
                sleep(2);
            }
            wait(NULL);
            break;
    } 
}