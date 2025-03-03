#include <stdio.h>

int main() { int n, i;
  float x, suma_x = 0;
  double y, suma_y = 0;
  scanf("%d %f %lf", &n, &x, &y);
  for (i = 1; i <= n; i++) {
    suma_x += x;
    suma_y += y;
    if (i % 10 == 0) 
        printf("%f %e %f %e\n",suma_x,suma_x,suma_y,suma_y);
    }
    return 0;
}