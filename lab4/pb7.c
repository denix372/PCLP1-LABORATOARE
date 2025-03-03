#include <stdio.h>

int main() { int n, v[100],x,y, k=0, i,maxim=0,indice;
    scanf("%d", &n);
    for (i = 0; i < n;i++)
        scanf("%d", &v[i]); 
    for (i = 1; i < n;i++)
    {
        if(v[i-1] < v[i]) k++;
        else 
        {
            if (maxim < k) 
            {
                maxim = k;
                indice = i;
            }
            k = 0;
        }
    }
    for (i = indice - maxim-1; i < indice; i++) {
      printf("%d ", v[i]);
    }
  printf("\n");
  return 0;
}