#include <stdio.h>
 
int cmp_cresc(const int x, const int y) {
    if (x == y)
        return 0;
    return x > y ? 1 : -1;
}
 
int cmp_desc(const int x, const int y) {
    if (x == y)
        return 0;
    return x > y ? -1 : 1;
}
 
void swap(int *x, int *y) {
    int aux;
 
    aux = *x;
    *x = *y;
    *y = aux;
}
 
void sort(int v[], int n, int (*cmp)(const int x, const int y)) {
    int i, j;
 
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (cmp(v[i], v[j]) == 1)
                swap(&v[i], &v[j]);
}
 
int main() {
    int v[100], n, ord,i;
    int (*cmps[2])(const int, const int) = {cmp_cresc, cmp_desc};

    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("Alegeti tipul de sortare: 0 - crescator; 1 - descrescator.\n");
    scanf("%d", &ord);
    sort(v, n, cmps[ord]);
    for (i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}