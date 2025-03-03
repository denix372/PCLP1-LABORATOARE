#include <stdio.h>
 
int main()
{
   int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
   unsigned long int adr0, adr1, adr2;
   int *p1, *p2;
 
   printf("a = %p\na + 1 = %p\na + 3 = %p\n\n", a, a + 1, a + 3);
 
   printf("sizeof(a) = %d\n", sizeof(a));
   printf("sizeof(a + 1) = %d\n", sizeof(a + 1));
   printf("sizeof(a + 3) = %d\n\n", sizeof(a + 3));
 
   adr0 = (unsigned long int) a;
   adr1 = (unsigned long int) (a + 1);
   adr2 = (unsigned long int) a + 1;
 
   printf("adr0 = %lu\nadr1 = %lu\nadr2 = %lu\n\n", adr0, adr1, adr2);
 
   p1 = a + 4;
   p2 = &(a[4]);
 
   printf("p1 = %p \t *p1 = %d\n", p1, *p1);
   printf("p2 = %p \t *p2 = %d\n", p2, *p2);
   printf("a + 4 = %p \t a[4] = %d\n", a + 4, a[4]);
 
   *p1 = *p1 + 1;
   printf("\na[4] = %d\n", a[4]);
 
   return 0;
}