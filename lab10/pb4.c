#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int n,m;
    int **a;
}MATRICE;

MATRICE* creeaza_MATRICE(int n, int m) {
  int i;
  MATRICE *ma = (MATRICE*)malloc(sizeof(MATRICE));
  ma->n = n;
  ma->m = m;
  ma->a = malloc(n * sizeof(int*));
  for (i = 0; i < n; i++) 
    ma->a[i] = malloc(m * sizeof(int));
  return ma;
}

MATRICE* citeste_MATRICE(MATRICE* ma) { 
    int i, j;
    for (i = 0; i < ma->n;i++)
      for (j = 0; j < ma->m; j++) 
        scanf("%d", &ma->a[i][j]);
    return ma;
}

void scrie_MATRICE(MATRICE* ma)
{
    int i, j;
    for (i = 0; i < ma->n; i++)
    {
        for (j = 0; j < ma->m; j++) 
        printf("%d ", ma->a[i][j]);
        printf("\n");
    }
}

MATRICE* aduna_MATRICE(MATRICE* ma, MATRICE* mb) {
  if (ma->n == mb->n && ma->m == mb->m) {
    int i, j;
    MATRICE* suma = creeaza_MATRICE(ma->n, ma->m);

    for (i = 0; i < ma->n; i++)
      for (j = 0; j < ma->m; j++) 
        suma->a[i][j] = ma->a[i][j] + mb->a[i][j];
    return suma;
  } 
  else return NULL;
}

MATRICE* inmulteste_MATRICE(MATRICE* ma, MATRICE* mb) 
{
    if(ma->m==mb->n)
    {
      MATRICE* prod = creeaza_MATRICE(ma->n, mb->m);
      int i, j, k;

      for (i = 0; i < prod->n;i++)
        for (j = 0; j < prod->m;j++)
          for (k = 0; k < ma->m; k++) 
            prod->a[i][j] = ma->a[i][k] * mb->a[k][j];
      return prod;
    }
    else return NULL;
}

int main() {
  MATRICE *ma, *mb, *suma, *produs;
  int n, m;
  scanf("%d%d", &n, &m);
  ma = creeaza_MATRICE(n, m);
  citeste_MATRICE(ma);

  scanf("%d%d", &n, &m);
  mb = creeaza_MATRICE(n, m);
  citeste_MATRICE(mb);

  suma = aduna_MATRICE(ma, mb);
  printf("+++++++++ Suma matricelor este +++++++++++\n");
  scrie_MATRICE(suma);
  printf("********* Produsul matricelor este *********\n");
  produs = inmulteste_MATRICE(ma, mb);
  scrie_MATRICE(produs);
  return 0;
}