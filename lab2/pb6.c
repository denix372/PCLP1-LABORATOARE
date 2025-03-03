#include <stdio.h>
#include <math.h>

int main() { float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if (fabs(a - b) < 0.001 && fabs(a - c) < 0.001) 
        printf("echilateral");
    else if( fabs(a*a+b*b-c*c)<0.001 || fabs(a*a-b*b+c*c)<0.001 || fabs(b*b+c*c-a*a)<0.001)
    {
        if(fabs(a-b)<0.001 || fabs(a-c)<0.001 || fabs(b-c)<0.001)
          printf("dreptunghic isoscel");
        else
          printf("dreptunghic");
    }
    else if(fabs(a-b)<0.001 || fabs(a-c)<0.001 || fabs(b-c)<0.001)
          printf("isoscel");
    else  printf("oarecare");
    return 0;
}