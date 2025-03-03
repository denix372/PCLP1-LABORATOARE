#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double integrala(double (*func)(double x), double a, double b, int n) {
    float I, dx, i;
    dx = (b - a) / n;
    for (i = 0; i < n - 1; i++) {
        I += dx * func(a + i * dx);
    }
    return I;
}

int main() {
    double a, b, I;
    int n, ordin;
    double (*func[2])(double x) = {sin, cos}; //pointeri la functii
    scanf("%lf%lf%d", &a, &b, &n);
    scanf("%d", &ordin);
    I = integrala(func[ordin], a, b, n);
    printf("%lf", I);
    return 0;
}