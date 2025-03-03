#include <stdio.h>

int main() {
    int n, i, j, ok, x;
    scanf("%d", &n);
    x = 1;
    for (i = 1; i <= n; i++) {
        ok = 0;
        while (ok == 0) {
            x++;
            ok = 1;
            if (x % 2 == 0 && x != 2)
                ok = 0;
            else if (x == 2)
                ok = 1;
            else {
                for (j = 3; j * j <= x && ok == 1; j = j + 2)
                    if (x % j == 0) ok = 0;
            }
        }
        printf("%d ", x);
    }
    return 0;
}