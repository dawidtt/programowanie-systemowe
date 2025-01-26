#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


void *Hello(void *arg) {
    int i;
    for (i = 0; i < 20; i++) {
        printf("Watek mowi czesc!\n");
        sleep(1);
    }
    return NULL;
}

int main(void) {
    pthread_t mojwatek;

    
    pthread_create(&mojwatek, NULL, &Hello, NULL);

    alarm(10);
    for (;;) {
        sleep(1);
    }

    
    return 0;
}
