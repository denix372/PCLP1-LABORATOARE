#include <stdio.h>

int main() { int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>=c && a+c>=b && b+c>=a && a>=0 && b>=0 && c>=0)
        printf("DA\n");
    else
      printf("NU\n");
    return 0;
}