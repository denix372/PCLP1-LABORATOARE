#include <stdio.h>

int main() {
    long int a, b, c, d;
    scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
    if (a < b && a < c && a < d)
        printf("%ld ", a);
    else if (b < a && b < c && b < c)
        printf("%ld ", b);
    else if (c < a && c < b && c < d)
        printf("%ld ", c);
    else
        printf("%ld ", d);
    if (a > b && a > c && a > d)
        printf("%ld\n", a);
    else if (b > a && b > c && b > d)
        printf("%ld\n", b);
    else if (c > a && c > b && c > d)
        printf("%ld\n", c);
    else
        printf("%ld\n", d);
    return 0;
}