#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
int zrodlo_d, nowy_d, w, r;
char bufor[16];
	if((zrodlo_d = open(argv[1], O_RDONLY)) < 0) {
 		printf("Nie udalo sie otworzyc pliku zrodlowego\n");		
		return 1;
		}
	else {
		printf("Otwarto plik zrodlowy\n");
		
	}

	if((nowy_d = creat(argv[2], S_IRWXU)) < 0){
		printf("Nie udalo sie utworzyc nowego pliku\n");
		return 1;
	}
	else {
		printf("Utworzono nowy plik\n");
		
	}
	if((nowy_d = open(argv[2], O_RDWR))< 0) {
		printf("Nie udalo sie otworzyc nowego pliku\n");
	       return 1;
	}	       
        else {
        	printf("Otwarto nowy plik\n");
        	
        }
	if((r = read(zrodlo_d, bufor, 16))<0){
		printf("Nie udalo sie odczytac pliku\n");
		return 1;
	}
	else {
		printf("Odczytano plik\n");
		
	}

	if((w = write(nowy_d, bufor, 16)) < 0) {
		printf("Nied udalo sie zapisac do pliku\n");
		return 1;
		}
	else {
		printf("Zapisano do nowego pliku\n");
		
		}

	close(zrodlo_d);
	close(nowy_d);

return 0;

}
