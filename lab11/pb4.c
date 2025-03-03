#include <ctype.h>
#include <stdio.h>
#include <string.h>

void convert(char *x, FILE *tabel) {
    rewind(tabel);
    //fseek(tabel, 0, 0); //sau
    char linie[4];
    while (fgets(linie, 4, tabel)) {
        if (linie[0] == *x) {
            *x = linie[2];
            break;
        } else if (*x == toupper(linie[0])) {
            *x = toupper(linie[2]);
            break;
        }
    }
}

int main(int argc, char **argv) {
    FILE *tabel = fopen(argv[1], "r");
    if (!tabel) {
        fprintf(stderr, "Eroare! Nu am putut deschide fisierul output!\n");
        return 0;
    }

    FILE *input = fopen(argv[2], "r");
    if (!input) {
        printf("Eroare la deschiderea inputului\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "w");
    if (!output) {
        fprintf(stderr, "Eroare! Nu am putut deschide fisierul output!\n");
        return 0;
    }

    char linie[200];
    int i;
    while (fgets(linie, 200, input) != NULL) {
        // amintim ca fgets citeste si endl (daca exista), in cazul nostru
        // tabela nu are la final endl 
        if (linie[strlen(linie) - 1] == '\n') linie[strlen(linie) - 1] = '\0';
        for (i = 0; i < strlen(linie); i++) convert(&linie[i], tabel);
        fputs(linie, output);
        fputs("\n", output);
    }

    fclose(input);
    fclose(output);
    fclose(tabel);
    return 0;
}