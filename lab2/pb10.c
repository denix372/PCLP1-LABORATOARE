#include <stdio.h>

int main() { int H, M, S;
  if(scanf("%d%d%d", &H, &M, &S)==3)
  {

  if (H < 10) printf("0");
  printf("%d:", H);
  if (M < 10) printf("0");
  printf("%d:", M);
  if (S < 10) printf("0");
  printf("%d\n", S);
  }
  else
    printf("Date incorect introduse!\n");
  return 0;
}