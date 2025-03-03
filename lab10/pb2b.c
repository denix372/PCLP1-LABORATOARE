#include <stdio.h>
#include <stdlib.h>

struct multime {
    unsigned int n;  // numărul maxim de elemente
    unsigned char *a;
};

void A(struct multime *m, int x) {
    int k, i, j;
    k = x / 8;  // calculam pozitia din vectorul char
    j = x % 8;
    if (m->n <= k) {
        m->a = realloc(m->a, (k + 1) * sizeof(char));
        for (i = m->n; i <= k; i++) m->a[i] = 0;
        m->n = k + 1;
    }
    m->a[k] = m->a[k] | 1 << j;
}

void D(struct multime *m, int x) {
    int k, j;
    k = x / 8;  // calculam pozitia din vectorul char
    j = x % 8;
    m->a[k] = m->a[k] & ~(1 << j);
}

void P(struct multime *m) {
    int i, j;
    for (i = 0; i < m->n; i++)
        for (j = 0; j < 8; j++)
            if (m->a[i] & (1 << j)) printf("%d ", i * 8 + j);
    printf("\n");
}

int C(struct multime *m, int x) {
    int k, j;
    j = x % 8;
    k = x / 8;
    return (m->a[k] & (1 << x)) != 0;
}

int main() {
    int n, i, x;
    char f;
    struct multime m;
    m.n = 0;
    m.a = malloc(1 * sizeof(char));
    scanf("%d", &n);
    getchar();  // citim endl
    for (i = 0; i < n; i++) {
        scanf("%c", &f);
        if (f == 'A') {
            scanf("%d", &x);
            A(&m, x);
        } 
        else if (f == 'P')
            P(&m);
        else if (f == 'D') {
            scanf("%d", &x);
            D(&m, x);
        } 
        else {
            scanf("%d", &x);
            if (C(&m, x) == 1)
                printf("DA\n");
            else
                printf("NU\n");
        }
        getchar();
    }
    return 0;
}