#include <stdio.h>

int main() { int H, M, S;
  scanf("%d%d%d", &H, &M, &S);
  if (H < 10) printf("0");
  printf("%d:", H);
  if (M < 10) printf("0");
  printf("%d:", M);
  if (S < 10) printf("0");
  printf("%d\n", S);
  return 0;
}