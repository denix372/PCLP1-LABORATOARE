#include <stdio.h>
// pb 12 din curs 1, pb 12 din lab 1
int main() {
  int n, i, x,maxim,a=0,b=0,v[100];
  scanf("%d", &n);
  for (i = 10; i < 100; i++) v[i] = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    v[x]++;
  }
  for (i = 99; i >= 10;i--)
  {
    if (v[i] == 0 && a == 0) 
        a = i;
    else if(v[i]==0 && b==0)
        b = i;
  }
  if (a == 0 || b == 0) printf("nu se poate");
  else
    printf("%d %d\n", a, b);
  return 0;
}