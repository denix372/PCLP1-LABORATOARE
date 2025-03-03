#include <stdio.h>

int main() {
  int A, B, numar = 1, suma = 0, aux;
  scanf("%d", &numar);
  A = numar;
  while (numar != 0) {
    suma = 0;
    aux = A;
    while(aux)
    {
      suma += aux % 10;
      aux /= 10;
    }
    scanf("%d", &numar);
    B = numar;
    if (B == A % suma) printf("(%d,%d)\n", A, B);
    A = B;
  }
  return 0;
}