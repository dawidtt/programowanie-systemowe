#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h> 
#define MAX 10
main(){
int shmid, i;
int *buf;
shmid = shmget(162375, MAX*sizeof(char), IPC_CREAT|0600);
if (shmid == -1){
perror("Utworzenie segmentu pamieci wspoldzielonej");
exit(1);
}
buf = (char*)shmat(shmid, NULL, 0);
if (buf == NULL){
perror("Przylaczenie segmentu pamieci wspoldzielonej");
exit(1);
}
printf("Tekst z pamieci wspoldzielonej: %s\n", buf);
if (shmdt(buf) == -1) {
        perror("Odłączenie segmentu pamięci współdzielonej");
        exit(1);
    }
shmctl(shmid,IPC_RMID,(struct shmid_ds *) 0);

}