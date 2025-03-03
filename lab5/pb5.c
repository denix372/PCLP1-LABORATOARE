#include <stdio.h>

int factorial(int n) { int fact = 1, i;
  for (i = 1; i <= n; i++) fact *= i;
  return fact;
}

double putere(double x, int n) { int i;
  double p = 1;
  for (i = 1; i <= n; i++) {
    p *= x;
  }
  return p;
}

double taylor(double x, int n) { double ex=1;
  int i;
  for (i = 1; i <= n; i++) {
    ex += putere(x, i) / factorial(i);
  }
  return ex;
}

int main() { int n;
  double x;
  scanf("%lf%d", &x, &n);
  printf("%.4lf\n", taylor(x, n));
  return 0;
}