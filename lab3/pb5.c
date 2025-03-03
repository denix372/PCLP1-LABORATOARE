#include <stdio.h>

int main() { int P,i,j,k;
  scanf("%d", &P);
  for (i = 0; i <= P / 2;i++)
  {
    for (j = i; j <= P / 2;j++)
    {
      k = P - i - j;
      if(i+j>=k && i+k>=j && j+k>=i && i<=j && j<=k)
      {
        printf("%d %d %d\n", i, j, k);
      }
    } 
  }
    return 0;

}