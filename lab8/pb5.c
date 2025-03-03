#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  int i,n,poz_r,poz_c,ok=1;
  char *cuv,*rec, *sir,a,b,c,d;
  scanf("%d", &n);
  cuv = malloc(20 * sizeof(char));
  rec = malloc(20 * sizeof(char));

  scanf("%s", cuv);
  sir=malloc( (strlen(cuv) + 2 ) *sizeof(char));
  strcpy(sir, cuv);
  strcat(sir, "-");

  for (i = 1; i < n; i++) {
    scanf("%s", rec);
    poz_c = strlen(cuv)-1;

    ok = 0;
    a = tolower(cuv[poz_c]);
    b = tolower(cuv[poz_c-1]);
    c = tolower(rec[0]);
    d = tolower(rec[1]);

    if(b==c && a==d)
    {
      sir = realloc(sir, (strlen(sir) + strlen(rec) + 2 )*sizeof(char));
      strcat(sir, rec);
      strcat(sir, "-");
      ok = 1;
    }
    if(ok==1) strcpy(cuv,rec);
  }
  sir[strlen(sir) - 1] = '\0';
  puts(sir);
  return 0;
}