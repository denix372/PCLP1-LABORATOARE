#include <stdio.h>

int cifra(int n, int c)
{
    while(n)
    {
      if (n % 10 == c) return 1;
      n /= 10;
    }
    return 0;
}

int main() { int n, c;
  scanf("%d%d", &n,&c);
  if (cifra(n, c) == 1) printf("DA\n");
    else
      printf("NU\n");
    return 0;
}