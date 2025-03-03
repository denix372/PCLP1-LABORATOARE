#include <stdio.h>
 
int nrcf(long n)
{
 if (n == 0)
     return 1;
 int nr = 0; /* declar un contor in care sa numar cifrele */
 while (n) /* cat timp mai pot obtine o cifra */
 {
     n = n/10; /* o trunchiez pe ultima */
     nr++; /* incrementez contorul */
 }
 return nr; /* functia intoarce numarul de cifre */
}

int main(void)
{
 long N;
 printf("N = "); /* afisam un mesaj pentru utilizator */
 scanf("%ld", &N); /* citim numarul introdus de la tastatura */
 printf("Numarul %ld are %d cifre!\n", N, nrcf(N)); /* afisez numarul de cifre */
 return 0;
}