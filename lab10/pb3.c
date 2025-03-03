#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


/*Exemplu de input
36 S
AMat
36
S
PCLP1
36
S
Sport
36
A
Engleza
6
C
Uso
36
S
(Se apasa ctrl d de doua ori pentru oprire)
Exemplu de output
----------Materiile sunt -----------
AMat          
36
S
PCLP1         
36
S
Uso           
36
S

*/

typedef enum {
    C, S, A
} TipExamen;

typedef struct {
    char nume[16];
    int ore_curs;
    TipExamen tip_examen;
} MATERIA;

void citire_MAT(MATERIA *materie) {
    char buffer[16];
    fgets(materie->nume, 16, stdin);
    materie->nume[strcspn(materie->nume, "\n")] = '\0';

    fgets(buffer, sizeof(buffer), stdin);
    materie->ore_curs = atoi(buffer);
    
    fgets(buffer, sizeof(buffer), stdin);
    switch (buffer[0]) {
        case 'C':
            materie->tip_examen = C;
            break;
        case 'S':
            materie->tip_examen = S;
            break;
        case 'A':
            materie->tip_examen = A;
            break;
    }
}

void citire_PROGRAMA(MATERIA PROGRAMA[], int *nr_materii) {
    *nr_materii = 0;
    while (*nr_materii < MAX) {
        if (feof(stdin)) break;
        citire_MAT(&PROGRAMA[*nr_materii]);
        (*nr_materii)++;
    }
}

void afisare(char tip, int ore, MATERIA PROGRAMA[], int nr_materii) {
    printf("\n----------Materiile sunt -----------\n");
    TipExamen tip_examen;
    switch (tip) {
        case 'C':
            tip_examen = C;
            break;
        case 'S':
            tip_examen = S;
            break;
        case 'A':
            tip_examen = A;
            break;
        default:
            return;
    }
    for (int i = 0; i < nr_materii; i++) {
        if (PROGRAMA[i].ore_curs == ore && PROGRAMA[i].tip_examen == tip_examen) {
            printf("%s\n%d\n%c\n", PROGRAMA[i].nume, PROGRAMA[i].ore_curs, tip);
        }
    }
}

int main() {
    MATERIA PROGRAMA[MAX];
    int nr_materii;
    int ore;
    char tip;
    scanf("%d", &ore);
    getchar();
    scanf("%c", &tip);
    getchar();
    citire_PROGRAMA(PROGRAMA, &nr_materii);
    afisare(tip, ore, PROGRAMA, nr_materii);
    return 0;
}
