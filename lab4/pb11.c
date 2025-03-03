#include <stdio.h>
#include <math.h>

int main() { int n,c[51],i;
  double x,P1=0,P2=0;
  scanf("%lf%d", &x, &n);
  for (i = 0; i <= n;i++)
  {
    scanf("%d", &c[i]);
    P1 += c[i]*pow(x, n-i);
  }
  /*Sau recursiv
  P2 = c[0];
  for (i = 1; i <= n; i++) {
    P2 = x*P2 + c[i];
  }*/
  printf("%0.2lf %0.2lf\n", P1,P2);
  return 0;
}