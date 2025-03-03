#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() { double x, r1, r2=0,prag;
  scanf("%lf %lf", &x,&prag);
  r1 = x / 2;
    while(fabs(r1-r2)>prag)
    {
      r2 = (r1 + x / r1) / 2;
      r1 = (r2 + x / r2) / 2;
    }
    printf("%lf %lf", r1, sqrt(x));
    return 0;
}