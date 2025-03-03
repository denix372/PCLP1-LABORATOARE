#include <stdio.h>

int main() { int B, E, V,n,m,v[1000000]={0},i,j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m;i++)
  {
    scanf("%d%d%d", &B, &E, &V);
    for (j = B; j <= E;j++)
      v[j] += V;
    
  }
  for (i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}