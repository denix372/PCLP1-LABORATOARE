#include <stdio.h>

int main() { int n, v[100], i,constant=1,cresc=1,descresc=1;
  scanf("%d", &n);
  for (i = 0; i < n;i++)
    scanf("%d", &v[i]);
    for (i = 1; i < n;i++)
      if (v[i - 1] != v[i]) constant = 0;
    if (constant == 1)
      printf("constant\n");
    else {
      for (i = 1; i < n; i++) {
        if (v[i - 1] < v[i])
          descresc = 0;
        else
          cresc = 0;
      }
      if (cresc == 1)
        printf("crescator\n");
      else if (descresc == 1)
        printf("descrescator\n");
      else
        printf("neordonat\n");
  }
  return 0;
}