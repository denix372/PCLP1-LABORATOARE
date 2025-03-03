#include <stdio.h>

int main() { int ch;
  for (ch = 32; ch <= 127;ch++)
  {
    printf("%c = %d ", ch, ch);
    if (ch % 10 == 1 ) printf("\n");
  }
  return 0;
}