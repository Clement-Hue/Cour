#include <stdio.h>
#include <dirent.h>

int main(int argc,char **argv){
    DIR *dirp;
    struct dirent *dptr;
    if (argc == 1){
        dirp = opendir(".");
    }
    else{
        dirp = opendir(argv[1]);
    }
    if (dirp == NULL){
        printf("error\n");
        return -1;
    }
    while (dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
    return 0;
}