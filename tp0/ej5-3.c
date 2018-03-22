#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *args[]) {


	int pPID;

	FILE * fp = fopen("./hola.txt", "a+");

	unsigned int fd = fileno(fp);

	pPID = fork();
	if(pPID==0) {
		dup2(fd, 1);
		close(fd);
		execl("./ej5-p", "0", (char *)NULL);
	}


	fclose(fp);


}