#include <stdio.h>

int main() { float x, y;
    scanf("%f%f", &x, &y);
    if (x == 0 || y == 0) printf("punct pe axe\n");
    else if(x>0 && x>0)
        printf("1\n");    
    else if(x<0 && y>0 )
        printf("2\n");
    else if(x<0 && y<0)
        printf("3\n");
    else
        printf("4\n");
    return 0;
}