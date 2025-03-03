#include <stdio.h>
// pb 13 curs, pb 13 lab
int main() { int n, i,x,maxim=0,v[101];
  scanf("%d", &n);
  for (i = 0; i < 101; i++) v[i] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    v[x] ++;
    if (maxim < v[x]) maxim = v[x];
  }
  for (i = 0; i <= 100;i++) 
    if (v[i] == maxim) printf("%d ", i);
  printf("\n");
  return 0;
}