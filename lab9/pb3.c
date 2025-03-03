#include <stdio.h>
#include <time.h>

char* timestr(struct tm t, char* time) { 
    sprintf(time,"Ora este: %.2d:%.2d:%.2d",t.tm_hour,t.tm_min,t.tm_sec);
    return time;
}

int main() { 
    time_t timp= time(NULL);
    struct tm *aria=localtime(&timp);
    char sir[16]; 
    timestr(*aria, sir);
    puts(sir);
    return 0;
}