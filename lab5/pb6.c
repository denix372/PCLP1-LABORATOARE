#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2) { float dist;
  dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  return dist;
}

int main() { int n, i,j, x[100],y[100],x_d,y_d;
  float dist_max = 0,maxim=0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (i = 0; i < n-1;i++)
  {
    for (j = i + 1; j < n;j++)
    {
        if( dist(x[i],y[i],x[j],y[j]) > maxim )
        {
            maxim=dist(x[i],y[i],x[j],y[j]);
            x_d=i;
            y_d=j;
        }
    } }
  printf("%d %d\n%d %d\n", x[x_d], y[x_d], x[y_d], y[y_d]);
  printf("%f\n", maxim);
  return 0;
}