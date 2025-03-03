#include <stdio.h>
#include <math.h>
//#define M_PI 3.14159
void unghi1(float v[], float w[])
{
  w[0] = acos((v[1] * v[1] + v[2] * v[2] - v[0] * v[0]) / (2 * v[1] * v[2])) / M_PI * 180;
  w[1] = acos((-v[1] * v[1] + v[2] * v[2] + v[0] * v[0]) / (2 * v[0] * v[2])) / M_PI * 180;
  w[2] = acos((v[1] * v[1] - v[2] * v[2] + v[0] * v[0]) / (2 * v[1] * v[0])) / M_PI * 180;
}

void unghi2(float x,float y,float z,float *a,float *b, float *c)
{
  *a = (acos((z * z + y * y - x * x) / (2 * z * y))) / M_PI * 180;
  *b = (acos((z * z - y * y + x * x) / (2 * x * z))) / M_PI * 180;
  *c = (acos((-z * z + y * y + x * x) / (2 * x * y))) / M_PI * 180;
}


int main()
{
  // primul mod;
  float lat[3], ung[3];
  int i;
  for (i = 0; i <= 2; i++) 
    scanf("%f", &lat[i]);
  unghi1(lat, ung);
  for (i = 0; i <= 2; i++) 
    printf("%.3f ", ung[i]);

  // al doilea mod cu variabile
  /*
  float x, y, z, a, b, c;
  scanf("%f%f%f", &x, &y, &z);
  unghi2(x, y, z, &a, &b, &c);
  printf("%.3f %.3f %.3f\n", a, b, c); 
  */
  return 0;
}