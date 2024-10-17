#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
int linux_d, windows_d, w, r, l_bajtow;

char bufor[4096];


        if((linux_d = open(argv[1], O_RDONLY)) < 0) {
                printf("Nie udalo sie otworzyc pliku w formacie linuxowego konca lini\n");
                return 1;
                }
        else {
                printf("Otwarto plik w formacie linuxowym\n");

        }
	
	

        if((windows_d = creat(argv[2], S_IRWXU)) < 0){
                printf("Nie udalo sie utworzyc nowego pliku\n");
                close(linux_d);
		return 1;
        }
        else {
                printf("Utworzono a nastepnie otwarto nowy plik\n");

        }

	while((l_bajtow = read(linux_d, bufor, sizeof(bufor))) > 0){
                for(int i = 0; i < l_bajtow; i++){
			if(bufor[i] == '\n'){


				if((write(windows_d, "\r\n", 2)) < 0){
			        	printf("Nie udalo sie zapisac do pliku windowsoweg");
		       			close(linux_d);
				        close(windows_d);

					return 1;
				}
			}
			else {
				
                		if((write(windows_d, &bufor[i], 1)) < 0) {
                    			printf("Nie mozna zapisac do pliku docelowego");
                    			close(linux_d);
       					close(windows_d);
		
                    			return 1;
                		}
        		}


		}
	}
       
        close(linux_d);
        close(windows_d);

return 0;

}
                    
