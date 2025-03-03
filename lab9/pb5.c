#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  float re,im;
}complex;

complex adunare(complex a, complex b) { 
    complex suma;
    suma.re = a.re + b.re;
    suma.im = a.im + b.im;
    return suma;
}

complex scadere(complex a, complex b) { 
    complex suma;
    suma.re = a.re - b.re;
    suma.im = a.im - b.im;
    return suma;
}

complex inmultire(complex a, complex b) { 
    complex suma;
    suma.re = a.re*b.re -a.im*b.im;
    suma.im = a.re*b.im+a.im*b.re;
    return suma;
}

complex putere(complex a, int putere) { 
    complex p;
    int i;
    if(putere==0)
    {
      p.im = 0;
      p.re = 1;
      return p;
    }
    else if(putere==1)
      return a;
    else {
      p = a;
      for (i = 1; i < putere; i++) {
        p = inmultire(p, a);
      }
      return p;
    }
}

int main() { 
    complex z;
    int i,n,*v;
    printf("Partea reala este:");
    scanf("%f", &z.re);
    printf("Partea imaginara este:");
    scanf("%f", &z.im);
    printf("Gradul este:");
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    printf("Coeficientii sunt:");
    for (i = 0; i <=n; i++) 
        scanf("%d", &v[i]);
    
    complex suma;
    suma.re = suma.im = 0;
    for (i = 0; i <= n; i++) {
      suma = adunare(suma, putere(z, i));
      suma.re *= v[i];
      suma.im *= v[i];
    }
    printf("\nPolinomul este:%.2f%+.2fi", suma.re, suma.im);
    return 0;
}