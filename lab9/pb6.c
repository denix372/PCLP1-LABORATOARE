#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* cuvant;
    int nr;
} Pereche;

int main() {
    //=======Varianta 1 doar cu vectori (lab8 pb3)===========
/*
    char** v1;
    int* v2;
    int i, j, cap = 1, n, lungime = 0;

    v1 = malloc(cap * sizeof(char*));
    v2 = malloc(cap * sizeof(int));

    for (i = 0; i < cap; i++)
        v1[i] = malloc(
            20 * sizeof(char));  // presupunem ca un cuvant are 20 de cuvinte

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char cuvant[20];
        scanf("%s", cuvant);  // scanf nu citeste caractere albe (" " sau "\n");
        int ok = 0;

        for (j = 0; j < lungime; j++) {  // daca cuvantul s-a mai gasit
            if (strcmp(cuvant, v1[j]) == 0) {
                v2[j]++;  // il numaram
                ok = 1;
                break;
            }
        }

        if (!ok)  // cuvantul nu a mai fost gasit pana acm
        {
            strcpy(v1[lungime], cuvant);
            v2[lungime] = 1;
            lungime++;

            if (lungime == cap) {
                cap *= 2;
                v1 = realloc(v1, cap * sizeof(char*));
                v2 = realloc(v2, cap * sizeof(int));

                for (j = cap / 2; j < cap; j++)
                    v1[j] = malloc(20 * sizeof(char));
            }
        }
    }
    for (i = 0; i < lungime; i++)
        printf("%s: %d\n", v1[i], v2[i]);
    return 0;
*/
    //===============Varianta 2 cu struct ===============
    Pereche* p;
    int i, j, n, cap = 1, lungime = 0, ok;

    p = malloc(cap * sizeof(Pereche));
    for (i = 0; i < cap; i++) {
        p[i].cuvant = malloc(20 * sizeof(char));
        p[i].nr = 0;
    }
    scanf("%d", &n);

    // for (i = 0; i < n; i++) p[i].cuvant = malloc(20 * sizeof(char));

    for (i = 0; i < n; i++) {
        char cuvant[20];
        scanf("%s", cuvant);
        ok = 0;

        for (j = 0; j < lungime; j++) {
            if (strcmp(cuvant, p[j].cuvant) == 0) {
                p[j].nr++;
                ok = 1;
                break;
            }
        }

        if (ok == 0) {
            strcpy(p[lungime].cuvant, cuvant);
            p[lungime].nr = 1;
            lungime++;

            if (lungime == cap) {
                cap *= 2;
                p = realloc(p, cap * sizeof(Pereche));
                for (int j = cap / 2; j < cap; j++) {
                    p[j].cuvant = malloc(20 * sizeof(char));
                    p[j].nr = 0;
                }
            }
        }
    }
    for (i = 0; i < lungime; i++)
        printf("%s : %d\n", p[i].cuvant, p[i].nr);
    return 0;
}