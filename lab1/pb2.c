#include <stdio.h>
#include <math.h>

int main() { float a, b, c, x1, x2, delta;
  scanf("%f%f%f", &a, &b, &c);
  if(a==0)
  {
    if(b==0)
    {
      if (c == 0) printf("O infinitate de solutii\n");
      else
        printf("Nu exista solutii reale\n");
    }
    else 
    {
      x1 = -c / b;
      printf("%0.3f\n", x1);
    }
  }
  else
  {
    delta = b * b - 4 * a * c;
    if (delta < 0) printf("Nu exista solutii reale\n");
    else if(delta==0)
    {
      x1 = -b / (2 * a);
      printf("%0.3f\n", x1);
    }
    else
    {
      x1 = (-b + sqrt(delta) )/ (2 * a);
      x2 = (-b - sqrt(delta) )/ (2 * a);
      printf("%0.3f %0.3f\n", x1, x2);
    }
  }
  return 0;
}