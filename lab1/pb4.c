#include <stdio.h>

int main() { int s = 0, i,j,fact,n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    fact = 1;
    for (j = 1; j <= i; j++) fact = fact * j;
    s = s + fact;
  }
  printf("%d\n", s);
  return 0;
}