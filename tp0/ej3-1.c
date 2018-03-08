#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void childFunc(){
	printf("%d \n", getpid());
}

void fatherFunc(){
	int * status;
	while(wait(status) > 0);
	printf("PADRE\n");
}

int main(){
	
	pid_t pid;
	pid = fork();
	for(int i = 0; i < 9; i++){
		if(pid!=0){
			pid = fork();
		}
	}
	if(pid != 0)
		fatherFunc();
	else
		childFunc();
	return 0;

}

