#include <stdio.h>
#include <limits.h>
#include <float.h>
//pb 11 din curs, pb 10 din lab
int main() { int n, i; 
    float x,  minim = FLT_MAX, maxim = FLT_MIN;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%f", &x);
      if (minim > x) minim = x;
      if (maxim < x) maxim = x;
    }
    printf("%0.3f %0.3f\n", minim, maxim);
    return 0;
}