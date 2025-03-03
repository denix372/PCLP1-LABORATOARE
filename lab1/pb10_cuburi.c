#include <stdio.h>
// pb 10 din curs (problema 10 din lab e pb12 din curs)
int main() {
  int i, j, k, nr = 0;
  for (i = 3; i < 10000;i++)
  {
    nr = 0;
    for (j = 1; j *j*j< i && nr<2; j++) {
      for (k = j+1; k*k*k< i && nr<2; k++)
      {
        if (j * j * j + k * k * k == i) nr++;
      }
    }
    if (nr == 2) printf("%d ", i);
  }
  printf("\n");
  return 0;
}