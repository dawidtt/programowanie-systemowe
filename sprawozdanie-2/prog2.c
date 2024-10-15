#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int pid1;
	pid1 = fork();
	if(pid1 == 0) {
		printf("Potomny, nr. procesu: %d\n", getpid());
	}
	else if(pid1 < 0){
		printf("blad\n");
	}
	else {
		printf("macierzysty\n");
	}
}
