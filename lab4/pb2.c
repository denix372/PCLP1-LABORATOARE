#include <stdio.h>

int main() { int n, v[100], i,nr_poz=0,nr_neg=0;
    scanf("%d", &n);
    for (i = 0; i < n;i++)
    {
      scanf("%d", &v[i]);
      if(v[i]>0)
        nr_poz++;
      else
        nr_neg++;
    }
    printf("%d %d\n", nr_neg, nr_poz);
    return 0;
}