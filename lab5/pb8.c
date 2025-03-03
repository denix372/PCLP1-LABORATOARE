#include <stdio.h>
#include <math.h>

int intersect(int a1,int b1,int a2, int b2)
{
  int aux;
  if (a2 > a1) {
    aux = a1;
    a1 = a2;
    a2 = aux;
  }
  if (b1 <= a2 && a1<=b1) return 0;
  else if(a2<=b1 )
    return b1 - a2;
 else if(b2<=b1)
   return b1 - b2;
}

int arie_intersectie(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22) 
{
  int x = intersect(x11, x12, x21, x22);
  int y = intersect(y11, y12, y21, y22);
  return x * y;
}

int main() {
  int x11, x12, x21, x22, y11, y12, y21, y22;
  scanf("%d%d%d%d%d%d%d%d", &x11, &y11, &x12,&y12,&x21, &y21, &x22, &y22);
  printf("%d\n",arie_intersectie(x11,y11,x12,y12,x21,y21,x22,y22));
  return 0;
}