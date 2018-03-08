#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void listDir(char* path, int tabs){
	DIR * dir;
	struct dirent *dp;

	struct stat fileStat;
	stat(path, &fileStat);
	if((fileStat.st_mode & S_IFMT) == S_IFDIR){    
        
        if((dir = opendir(path))==NULL){
			perror("Cant open");
			printf("%s\n", path);
			return;
		}

		while((dp=readdir(dir))!= NULL){
			for(int i = 0; i < tabs; i++)
				printf("\t");
			(dp->d_type == DT_REG)?printf("(FILE)"):printf("(DIR)");
			printf("%s \n", dp->d_name);
			if(strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0){
				char pathAux[256] = "";
				strcpy(pathAux, path);
				strcat(pathAux, "/");
				strcat(pathAux, dp->d_name);
				if(dp->d_type == DT_DIR){
					listDir(pathAux, tabs + 1);
				}
			}
		}
		closedir(dir);
	}
	else{
		printf("its a file\n");		
	}

	
}
int main(int argc, char* args[]){
	listDir(args[1], 0);
	return 0;
}
