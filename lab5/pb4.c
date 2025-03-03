#include <stdio.h>

int cmmmc(int a, int b) { int r,cmmm,copie_a,copie_b;
  copie_a = a;
  copie_b = b;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  cmmm = ((copie_a) * (copie_b) )/ a;
  return cmmm;
}

int main() { int x1, y1, x2, y2,cmmmcy,mult_y1,mult_y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  cmmmcy = cmmmc(y1, y2);
  mult_y1 = cmmmcy / y1;
  printf("%d %d\n", mult_y1 * x1, cmmmcy);
  mult_y2 = cmmmcy / y2;
  printf("%d %d\n", mult_y2 * x2, cmmmcy);
  return 0;
}