#include <stdio.h>

int main() { int termen1, termen2,termen_gen, n, j,i = 3,ok;
  scanf("%d", &n);
  termen1 = 0;
  termen2 = 1;
  for (i = 3; i <= n; i++) 
  {
    termen_gen = termen1 + termen2;
    ok = 1;
    if (termen_gen == 1) ok = 0;
    for (j = 2; j * j <= termen_gen; j++)
      if (termen_gen % j == 0) ok = 0;
    if (ok == 1) printf("%d\n", termen_gen);
    termen1 = termen2;
    termen2 = termen_gen;
  }
  return 0;
}