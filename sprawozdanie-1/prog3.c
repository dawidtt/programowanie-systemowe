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
		close(zrodlo_d);
		return 1;
	}
	else {
		printf("Utworzono oraz otwarto nowy plik\n");
		
	}
	
	if((r = read(zrodlo_d, bufor, 16))<0){
		printf("Nie udalo sie odczytac pliku\n");
		close(zrodlo_d);
		close(nowy_d);
		return 1;
	}
	else {
		printf("Odczytano plik zrodlowy\n");
		
	}

	if((w = write(nowy_d, bufor, 16)) < 0) {
		printf("Nied udalo sie zapisac do pliku\n");
		close(zrodlo_d);
		close(nowy_d);
		return 1;
		}
	else {
		printf("Zapisano pierwsze 16 bajtow z pliku zrodlowego do nowego pliku\n");
		
		}

	close(zrodlo_d);
	close(nowy_d);

return 0;

}
