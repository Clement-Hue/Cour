#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("%d",setenv("HELLO","test",1));
    fork();
    printf("%s",getenv("HELLO"));
    return 0;
}