#include <stdio.h>

void count(int n, int *v, int *zero, int *poz, int *neg) {
  int i;
  *zero = *neg = *poz = 0;
  for (i = 0; i < n; i++) {
    if (v[i] == 0) (*zero)++;
    else if(v[i]>0)
      (*poz)++;
      else
        (*neg)++;
  }
}

int main() { int i, n, v[100],poz,neg,zero;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  count(n, v, &zero, &poz, &neg);
  printf("nule:%d \npozitive:%d \nnegative:%d\n", zero, poz, neg);
  return 0;
}
