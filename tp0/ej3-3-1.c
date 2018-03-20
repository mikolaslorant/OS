#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid = fork();
	int status;
	for (int i = 0; i < 10; ++i)
	{
		if(pid != 0)
			pid = fork();
	}
	while(wait(&status) > 0);
	if(pid == 0)
		execl("./ej3-3-2", (char *)NULL);
	else
		printf("padre\n");
	return 0;
}