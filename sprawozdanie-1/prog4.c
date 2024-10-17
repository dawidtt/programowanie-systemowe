#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
int zrodlo_d, nowy_d, w, r, l_bajtow;
l_bajtow = atoi(argv[2]);
char bufor[l_bajtow];

char nowa_nazwa[256];  // Zakładamy, że nazwa pliku nie przekracza 255 znaków
    snprintf(nowa_nazwa, sizeof(nowa_nazwa), "%s3", argv[1]);


        if((zrodlo_d = open(argv[1], O_RDONLY)) < 0) {
                printf("Nie udalo sie otworzyc pliku zrodlowego\n");
                return 1;
                }
        else {
                printf("Otwarto plik zrodlowy\n");

        }

        if((nowy_d = creat(nowa_nazwa, S_IRWXU)) < 0){
                printf("Nie udalo sie utworzyc nowego pliku\n");
                return 1;
        }
        else {
                printf("Utworzono a nastepnie otwarto nowy plik\n");

        }
       
        if((r = read(zrodlo_d, bufor, l_bajtow))<0){
                printf("Nie udalo sie odczytac pliku\n");
                return 1;
        }
        else {
                printf("Odczytano plik\n");

        }

	for(int i = 0; i < 3;i++){


        if((w = write(nowy_d, bufor, l_bajtow)) < 0) {
                printf("Nie udalo sie zapisac do pliku\n");
                return 1;
                }
        else {
                printf("Zapisano do nowego pliku\n");

                }
	}
        close(zrodlo_d);
        close(nowy_d);

return 0;

}
