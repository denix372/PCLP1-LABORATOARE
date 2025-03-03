#include <stdio.h>

int main() { int n,m, a[100][100],maxime[100], maxim,minim, i,j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n;i++)
  {
    int maxim = -1;
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if (maxim < a[i][j]) maxim = a[i][j];
    }
    maxime[i] = maxim;
  }
  minim = maxime[1];
  for (i = 1; i < n;i++)
    if (maxime[i] < minim) minim = maxime[i];
  printf("%d\n", minim);
  return 0;
}