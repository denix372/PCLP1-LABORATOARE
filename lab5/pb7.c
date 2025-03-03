#include <stdio.h>

int transforma(int n) { int N=0,v[10] = {0},i,j; 
    while(n)
    {
      v[n % 10]++;
      n /= 10;
    }
    // n va deveni 0 dupa bucla while
    if(v[0]==0)
    {
      for (i = 1; i <= 9;i++)
        for (j = 0; j < v[i];j++) {
          n = n * 10 + i;
        }
    }
    else 
    {
        for (i = 9; i >=0;i--)
          for (j = 0; j < v[i];j++) n = n * 10 + i;
    }
    return n;
}
int main() { int n;
  scanf("%d", &n);
  printf("%d\n", transforma(n));
  return 0;
}