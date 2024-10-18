#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
        int pid1, status;
        pid1 = fork();
        if(pid1 == 0) {
                printf("Potomny, nr. procesu: %d\n", getpid());
		exit(0);
	}
        else if(pid1 < 0){
                printf("blad\n");
        }
        else {
		wait(&status);
                printf("macierzysty\n");
		printf("status: %d\n", status);
		
        }
}
