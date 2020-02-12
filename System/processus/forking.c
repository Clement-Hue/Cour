#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int proc = fork();
    if (proc == 0){ // exécution du processus fils
        printf("pid fils %d\n",getpid());
        sleep(20);
    }
    else{  // exécution du processus père
        printf("fork %d\n",proc);
        printf("pere pid %d\n",getppid());
    }
    return 0;
}