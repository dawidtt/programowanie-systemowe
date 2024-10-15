#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
        int pid1, pid2;
        pid1 = fork();

        if(pid1 == 0) {
                printf("Proces potomny 1, nr. procesu: %d, nr. procesu macierzystego: %d\n", getpid(), getppid());
                exit(0);
        }
        else if(pid1 < 0){
                printf("blad\n");
        }
        
	pid2 = fork();

	if(pid2 == 0) {
                printf("Proces potomny 2, nr. procesu: %d, nr. procesu macierzystego: %d\n", getpid(), getppid());
                exit(0);
        }
	else if(pid2 < 0){
		printf("blad\n");
	}
       	wait(NULL);
	wait(NULL);
	printf("Proces macierzysty\n");
        
}
