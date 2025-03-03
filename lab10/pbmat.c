#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef enum {
    C, // Colocviu
    S, // Examen de semestru
    A  // Examen de an
} TipExamen;

typedef struct {
    char nume[16];
    int ore_curs;
    TipExamen tip_examen;
} MATERIA;

void citire_MAT(MATERIA *materie) {
    char buffer[16];

    // Citire nume (poate conține spații)
    if (fgets(materie->nume, sizeof(materie->nume), stdin) == NULL) return;
    materie->nume[strcspn(materie->nume, "\n")] = '\0';  // Elimină newline-ul

    // Citire ore_curs
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    materie->ore_curs = atoi(buffer);  // Convertire la intreg

    // Citire tip_examen
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    buffer[strcspn(buffer, "\n")] = '\0';  // Elimină newline-ul

    // Atribuire tip_examen
    if (strcmp(buffer, "C") == 0) {
        materie->tip_examen = C;
    } else if (strcmp(buffer, "S") == 0) {
        materie->tip_examen = S;
    } else if (strcmp(buffer, "A") == 0) {
        materie->tip_examen = A;
    }
}

void citire_PROGRAMA(MATERIA PROGRAMA[], int *nr_materii) {
    *nr_materii = 0;
    while (*nr_materii < MAX) {
        MATERIA temp;
        citire_MAT(&temp);
        PROGRAMA[*nr_materii] = temp;
        (*nr_materii)++;
    }
}

void afisare(char tip, int ore, MATERIA PROGRAMA[], int nr_materii) {
    TipExamen tip_examen;
    // Determinare tip_examen din caracterul primit
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
            return;  // Dacă tipul nu este valid
    }
    
    // Afișare materii care se potrivesc cu condițiile
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

    // Citire ore (în loc de fgets pentru că este un număr)
    char buffer[16];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        ore = atoi(buffer);  // Convertim numărul de ore
    }

    // Citire tip examen (acum se folosește scanf pentru un singur caracter)
    scanf("%c", &tip);
    getchar();  // Consumăm newline-ul rămas după citirea caracterului

    // Citire programă
    citire_PROGRAMA(PROGRAMA, &nr_materii);

    // Afișare materii care se potrivesc
    afisare(tip, ore, PROGRAMA, nr_materii);

    return 0;
}
