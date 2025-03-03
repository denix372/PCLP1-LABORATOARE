#include <stdio.h>
#include <time.h>

int main() { 
    time_t timp= time(NULL);
    struct tm *aria  = localtime(&timp);
    printf("Ora este:%.2d:%.2d:%.2d\nData este:%.2d.%.2d.%d\n", 
        aria->tm_hour, aria->tm_min, aria->tm_sec,
        aria->tm_mday, aria->tm_mon+1, 1900+ aria->tm_year);
    return 0;
}