#include <stdio.h>
#include <string.h>

int cmp(char sir1[],char sir2[])
{
  int i;
  for (i = 0; sir1[i]!=NULL || (sir2+i)!=NULL;i++) //ambele sunt echivalente
  {
    if ((int)sir1[i] > (int)sir2[i]) return 1;
    else if((int)sir1[i] < (int)sir2[i])return -1;
  }
  return 0;
}

int main() {
  char sir1[100],sir2[100];
  scanf("%s%s", sir1, sir2);
  printf("%d\n", cmp(sir1, sir2));
  return 0;
}