#include <stdio.h>
// pb 11 din lab
int main() {
  int i, j, k, nr = 0, n;
  scanf("%d", &n);
  for (i = 3; i < n; i++) {
    nr = 0;
    for (j = 1; j *j< i && nr<2; j++) {
      for (k = j+1; k*k< i && nr<2; k++)
      {
        if (j * j + k * k == i) nr++;
      }
    }
    if (nr == 2) printf("%d ", i);
  }
  printf("\n");
  return 0;
}