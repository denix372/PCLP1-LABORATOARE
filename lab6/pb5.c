#include <stdio.h>

void transform(int v[], int n, int x) {
  int st,dr,aux;
    st=0;dr=n-1;
    while(st<dr)
    {
        while(v[st]<=x ) st++;
        while(v[dr]>=x) dr--;
        if(st<dr)
        {
            aux=v[st];
            v[st]=v[dr];
            v[dr]=aux;
            st--;dr++;
        }
        st++;dr--;
    }
}
int main() { int v[100], x, n, i;
  scanf("%d%d", &n,&x);
  for (i = 0; i < n; i++) 
    scanf("%d", &v[i]);
  transform(v, n, x);
  for (i = 0; i < n; i++) printf("%d ", v[i]);
  return 0;
}
