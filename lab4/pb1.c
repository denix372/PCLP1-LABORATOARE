#include <stdio.h>
 
int main() {
    int N, v[100], i, n5;
    float procent;
 
    /* Citim numarul de note ce vor fi introduse de la tastatura */
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        /* Citim a i-a nota */
        scanf("%d", &v[i]);
    }
 
    /* In n5 vom numara cate note mai mici ca 5 au fost citite. Initial sunt 0*/
    n5 = 0;
 
    /* Parcurgem vectorul de note... */
    for (i = 0; i < N; i++) {
        /* ... si daca gasim o nota mai mica decat 5 ... */
        if (v[i] < 5) {
            /* ... vom incrementa n5. */
            n5++;
        }
    }
 
    /* Aplicam formula de calculare a procentului: cum n5, 100 si N sunt de tip
     * int, daca nu am converti una dintre ele la float, s-ar face impartire 
     * intreaga.
     */
    procent = (float)n5 * 100 / N;
 
    printf("%.3f", procent);
 
    return 0;
}