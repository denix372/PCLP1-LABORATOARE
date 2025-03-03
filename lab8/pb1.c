#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_replace(char *s, char *s1, char *s2) {
    char *aux = malloc((strlen(s) + strlen(s2) - strlen(s1)) * sizeof(char));
    char *p = strstr(s, s1);
    strncpy(aux, s, p - s);
    aux[strlen(aux)] = 0;
    strcat(aux, s2);
    strcat(aux, p + strlen(s1));
    return aux;
}

int main() {
    char s1[100], s2[100], s3[100];
    scanf("%s%s", s1, s2);
    getchar();
    fgets(s3, 100, stdin);
    s3[strlen(s3) - 1] = '\0';  // stergem endl
    while (strstr(s3, s1)) 
        strcpy(s3, my_replace(s3, s1, s2));
    puts(s3);
    return 0;
}