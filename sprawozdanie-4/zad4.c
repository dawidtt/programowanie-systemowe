#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAX 10
main(){
int shmid, i;
int *buf;
shmid = shmget(162375, MAX*sizeof(int), IPC_CREAT|0600);
if (shmid == -1){
perror("Utworzenie segmentu pamieci wspoldzielonej");
exit(1);
}

}