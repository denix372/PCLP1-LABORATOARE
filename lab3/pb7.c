#include <stdio.h>
#include <math.h>

int main() { int n,k;
  double x, EPS,suma1,tk,suma2,suma3,suma4;
  scanf("%lf %d %lf", &x, &n, &EPS);
  tk = 1;
  //Prima suma calculata prin recurenta
  suma1 = 1;
  for (k = 1; k < n; k++) {
    tk = tk * x / k;
    suma1 = suma1 + tk;
  }
  //A doua suma cu termenii mai mari decat epsilon
  suma2 = 0;
  if(1>EPS) suma2=1;
  tk = 1;
  for (k = 1; tk > EPS; k++) {
    tk = tk * x / k;
    if(tk>EPS) suma2 =suma2+ tk;
  }
  //Pentru suma 3 si suma 4
  suma3 = exp(x);
  suma4 = pow(2.718, x);
  printf("%lf %lf %lf %lf\n", suma1, suma2, suma3, suma4);
  return 0;
}