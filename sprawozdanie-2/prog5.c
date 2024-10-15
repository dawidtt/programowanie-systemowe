#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
        int pid1, pid2, pid3, pid4;
        pid1 = fork();

        if(pid1 == 0) {
                
                exit(0);
        }
        else if(pid1 < 0){
                printf("blad\n");
        }

        pid2 = fork();

        if(pid2 == 0) {
           
                exit(0);
        }
        else if(pid2 < 0){
                printf("blad\n");
        
	}
	
	pid3 = fork();
	

        if(pid3 == 0) {
                exit(0);
        }
        else if(pid3 < 0){
                printf("blad\n");
        }

        pid4 = fork();

        if(pid4 == 0) {
               
                exit(0);
        }
        else if(pid4 < 0){
                printf("blad\n");
        }

	sleep(10);

        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        printf("Koniec procesu macierzystego\n");

}         
