#include <stdio.h>
#include <string.h>

char* substr(char *src, int n, char *dest) // extrage de la pozitia src in dest n caractere
{
  int i, k = 0;
  for (i = 0; i < n;i++)
  {
    dest[k++] = src[i];
  }
  dest[k] = '\0';
}

int main() { char s[100],p[100];
  int poz, nr;
  scanf("%s%d%d", s, &poz, &nr);
  substr(s + poz, nr, p);
  printf("%s\n", p);
  return 0;
}