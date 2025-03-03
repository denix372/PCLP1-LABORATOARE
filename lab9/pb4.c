#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int *v;
  int cap;
  int n;
} vector;

void init_vector(vector *a, int nr) { 
    a->v = malloc(nr * sizeof(int));
    a->cap = nr;
    a->n = 0;
}

void adauga_vector(vector *a, int n) {
  if (a->cap == a->n + 1) {
    a->cap *= 2;
    a->v = realloc(a->v,a->cap * sizeof(int));
  }
  a->v[n] = n;
  a->n++;
}

void scrie_vector(vector a) { int i;
    for (i = 0;i<a.n;i++)
        printf("%d ", a.v[i]);
    printf("\n");
}

int main() { int i;
    vector a;
    init_vector(&a, 4);
    for (i = 0; i <= 100; i++) {
      adauga_vector(&a, i);
      scrie_vector(a);
    }
    return 0;
}