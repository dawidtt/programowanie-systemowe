#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/file.h>  
#include <sys/types.h>  
#include <sys/wait.h>  
#include <unistd.h>
int main() {
int pdesk[2];
char buf[128];

pipe(pdesk);

if (fork() == 0){ // proces potomny
write(pdesk[1], "Hallo", 6);
exit(0);
}
else { // proces macierzysty

 read(pdesk[0], buf, 10);
printf("Odebrano z potoku: %s\n", buf);
 }
}