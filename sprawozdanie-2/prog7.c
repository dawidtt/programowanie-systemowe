#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()  {
	int pid1;
	
	pid1 = fork();

	if(pid1 == 0){
		execlp("ls", "ls", "-l", NULL);
		exit(0);
	}
	else if(pid1 < 0) {
		printf("blad\n");
	}

	wait(NULL);
}
