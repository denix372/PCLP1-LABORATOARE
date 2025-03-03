#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { int a,b,c, seed;

    time_t timp; //pt lab 9
    struct tm *t;
    timp=time(NULL);
    t=localtime(&timp);
    seed=t->tm_sec;
    /*
    time_t timp=time(NULL);
    t=Localtime(&timp);
    srand(t->tm_sec);
    x=rand();

    */
    srand(seed);
    a = rand();
    b = rand();
    c = rand();
    printf("%d %d %d\n", a,b,c);
    return 0;
}