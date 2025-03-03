#include <stdio.h>

int main() { int n, inv = 0;
  scanf("%d",&n);
  while (n) {
    inv = inv * 10 + n % 10;
    n = n / 10;
  }
    printf("%d\n", inv);
    return 0;
}