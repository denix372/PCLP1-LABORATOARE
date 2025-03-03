#include <stdio.h>

void extragere(int a[], int b[], int n, int m, int c[]) { int i, j,k=0;
  for (i = 0; i < n;i++)
  {
    for (j = 0; j < m ; j++) {
      if (a[i] == b[j]) {
        c[k++] = a[i];
        break;
      }
    }
  }
  printf("%d\n", k);
  for (i = 0; i < k; i++) printf("%d ", c[i]);
}

int main() { int a[1000], b[1000], c[1000], i, j, k, n, m, p;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) 
        scanf("%d", &b[i]);
    extragere(a, b, n, m, c);
    return 0;
}