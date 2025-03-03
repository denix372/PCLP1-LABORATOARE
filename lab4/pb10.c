#include <stdio.h>

int main() {
    int n, m, i, j, k, a, b, ok = 1, Interval[100];
    float x[1001];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &Interval[i]);
    for (i = 1; i < m; i++)
        if (Interval[i - 1] >= Interval[i])
            ok = 0;
    if (ok == 0)
        printf("Error\n");
    else {
        for (i = 0; i < m-1; i++) {
            a = Interval[i];
            b = Interval[i + 1];  // capetele intervalelor (a,b)
            k = 0;
            for (j = 0; j < n; j++)
                if (a < x[j] && x[j] < b)
                    k++;
            printf("%d ", k);
        }
    }
    return 0;
}