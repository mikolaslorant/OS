#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *args[]) {

	int status = 0;
	int fds[2] = {-1, -1};
	int pPID;
	int cPID;
	pipe(fds);

	pPID = fork();
	if(pPID==0) {
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		execl("./p.exe", "0", (char *)NULL);
	}

	cPID = fork();
	if(cPID==0) {
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		execl("./c.exe", "0", (char *)NULL);
	}

	close(fds[0]);
	close(fds[1]);

	while(wait(&status) > 0); //Waiting for all children processes to end
	//All children processes ended
}