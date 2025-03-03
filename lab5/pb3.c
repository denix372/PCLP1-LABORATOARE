#include <stdio.h>

int prim(int n)
{
  int i;
  if (n == 1) return 1;
  else if (n < 2)
    return 0;
  else if(n==2)
    return 1;
    else if(n%2==0)
      return 0;
      else 
      {
        for (i = 3; i * i <= n;i+=2)
          if (n % i == 0) return 0;
        return 1;
      }
}

int main() { int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n;i++)
    for (j = i; j <= n;j++)
      if (prim(i) == 1 && prim(j) == 1 && i + j == n) printf("%d + %d\n", i, j);
  return 0;
}