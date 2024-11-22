#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void sig(int sig)
{
 printf ("\nSignal No %u", sig);
}
int main()
{ signal(SIGINT,sig);
 for(;;)sleep(1);
}