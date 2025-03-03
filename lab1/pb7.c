#include <stdio.h>

int main() { int n, i,ok;
    scanf("%d", &n);
    if (n < 2) printf("nu e prim\n");
    else if(n%2==0 && n!=2)
      printf("nu e prim\n");
      else if(n==2)
        printf("e prim\n");
        else 
        {
          ok = 1;
          for (i = 3; i * i <= n && ok == 1; i = i + 2)
            if (n % i == 0) ok = 0;
          if (ok == 1) printf("e prim\n");
          else
            printf("nu e prim\n");
        }
    return 0;
}