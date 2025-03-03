#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v, cap = 10, n = 0, i;
    v = malloc(cap * sizeof(int));
    while (scanf("%d", &v[n]) > 0) {  // cat timp se citeste intreg
        n++;
        if (n == cap) {
            cap *= 2;
            v = realloc(v, cap * sizeof(int));
        }
        if (v[n - 1] == 0) {
            n--;
            break;
        }
    }

    for (i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}