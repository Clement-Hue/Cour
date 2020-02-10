#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char *argv[])
{
	if (argc !=2) 
		return 0;
	struct stat infoFile;
	for (int i=0;i<2;i++){
		int openFile = open(argv[1],O_RDWR);
		printf("-------------------\n");

		printf("Type de fichier :                ");

		switch (infoFile.st_mode & S_IFMT) {
		case S_IFBLK:  printf("périphérique de bloc\n");      break;
		case S_IFCHR:  printf("périphérique de caractère\n"); break;
		case S_IFDIR:  printf("répertoire\n");                break;
		case S_IFIFO:  printf("FIFO/tube\n");                 break;
		case S_IFLNK:  printf("lien symbolique\n");           break;
		case S_IFREG:  printf("fichier ordinaire\n");         break;
		case S_IFSOCK: printf("socket\n");                    break;
		default:       printf("inconnu ?\n");                 break;
		}

		printf("Description du fichier : %d\n",openFile);
		printf("Numéro d'inœud :  %ld\n", (long) infoFile.st_ino);
		printf("Mode :  %lo (octal)\n",(unsigned long) infoFile.st_mode);
		printf("Nombre de liens :  %ld\n", (long) infoFile.st_nlink);
		printf("Propriétaires :   UID=%ld   GID=%ld\n",(long) infoFile.st_uid, (long) infoFile.st_gid);
		printf("Taille de bloc d’E/S :  %ld octets\n",(long) infoFile.st_blksize);
		printf("Taille du fichier :   %lld octets\n",(long long) infoFile.st_size);
		printf("Blocs alloués :  %lld\n",(long long) infoFile.st_blocks);
		printf("Dernier changement d’état :        %s", ctime(&infoFile.st_ctime));
		printf("Dernier accès au fichier :         %s", ctime(&infoFile.st_atime));
		printf("Dernière modification du fichier:  %s", ctime(&infoFile.st_mtime));

	}

	return 0;
}
