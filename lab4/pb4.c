#include <stdio.h>

int main() { int n, m, p, q, i,j,k,a[100][100], b[100][100],c[100][100];
    scanf("%d %d", &m, &n);
    for (i = 0; i < m;i++)
        for (j = 0; j < n; j++) 
            scanf("%d", &a[i][j]);
    scanf("%d %d", &p, &q);
    for (i = 0; i < p;i++)
        for (j = 0; j < q; j++) 
            scanf("%d", &b[i][j]);
    if (n != p) printf("imposibil\n");
    else 
    {
      for (i = 0; i < m;i++) 
        for (k = 0; k < n;k++) 
          for (j = 0; j < q;j++)
              c[i][j] = a[i][k] * b[k][j];
      printf("%d %d\n", m, q);
      for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) printf("%d ", c[i][j]);
        printf("\n");
      }
    }
    return 0;
}