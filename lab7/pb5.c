#include <stdio.h>
#include <limits.h>

void panta(int x1, int y1, int x2, int y2, float *m, float *n)
{
    if(x2==x1) *m=INT_MAX;
    else 
        *m=(y2-y1)/(x2-x1);
    *n=y1-x1*(*m);
}

int main() { int x1, x2, x3, y1, y2, y3;
  float m, n;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  panta(x1, y1, x2, y2, &m, &n);
  if (m * x3 + n == y3)
    printf("DA\n");
  else
    printf("NU\n");
  return 0;
}