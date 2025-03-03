#include <stdio.h>
//Algoritmul lui Kadane
int main() {
  int n, v[100], i,k = 0, lungime = 0, suma = 0, maxim = 0,indice;
  scanf("%d", &n);
  for (i = 0; i < n; i++) 
    scanf("%d", &v[i]);
  for (i = 0; i < n; i++) {
    suma = suma + v[i];
        if(suma < 0)
        {
            k = 0;
            suma = 0;
        }

        if(suma > maxim)
        {
            maxim = suma;
            lungime = k;
            indice = i;
        }
        k++;
  }

  for (i = indice - lungime; i <= indice;i++)
    printf("%d ", v[i]);
  printf("\n");
  return 0;
}