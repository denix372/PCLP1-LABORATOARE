#include <stdio.h>
#include <string.h>

char *next(char *from, char *word) {
    while (*from && (*from < 'a' || *from > 'z')) 
        from++; // Sărim peste caracterele care nu sunt litere mici

    while (*from >= 'a' && *from <= 'z') 
        *word++ = *from++; // Adăugăm litere mici în `word`

    *word = '\0'; // Terminăm șirul
    return from; // Returnăm adresa următoarei poziții
}

int main() {
    char s[100], word[100];
    char *p;
    fgets(s, sizeof(s), stdin);
    //s[strlen(s)] = '\0'; //fgets are newline dar oricum functia sare peste
    p = s;
    while (*p) { //cat timp p nu ajunge la null
        p = next(p, word); // Extragem următorul cuvânt format doar din litere mici
        if (strlen(word) > 0) { // Dacă am extras un cuvânt valid
            printf("%s ", word);
        }
    }
    printf("\n");
    return 0;
}