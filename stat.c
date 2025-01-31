#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
	struct stat *nfile;
	char path1[10];
	printf("Enter the path: ");
	scanf("%s",path1);
	nfile = (struct stat*)malloc(sizeof(struct stat)); 
	stat(path1,nfile);
	printf("\nUser ID: %d\n",nfile->st_uid);
	printf("Blocksize: %ld\n",nfile->st_blksize);
	printf("Last Access Time: %ld\n",nfile->st_atime);
	printf("Last Modification Time: %ld\n",nfile->st_mtime);
	printf("Production Mode: %d\n",nfile->st_mode);
	printf("Filesize: %ld\n",nfile->st_size);
	printf("Number of Links: %ld\n",nfile->st_nlink);
	exit(0);
}
