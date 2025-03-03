#include <stdio.h>
int main() { int n, m, i; 
    scanf("%d%d",&n,&m);
    for (i = 1; i <= n;i++)
    {
      printf("%d ", i);
      if (i % m == 0) printf("\n");
      if (i % 24 == 0) printf("\n");
    }
    fflush(stdin);
    getchar();
    return 0;
}