#include <stdio.h>
#include <string.h>

char *strdel(char *p, int n)  // sterge n caractere din pozitia p
{
    char aux[20];
    if (n < strlen(p)) {
        strcpy(aux, p + n);
        strcpy(p, aux);
    } else
        *p = '\0';  // sau *p=0;
    return p;
}

char *strins(char *p, const char *s)  // insereaza la p, sirul s
{
    char aux[20];
    strcpy(aux, p);
    strcpy(p, s);
    strcat(p, aux);
    return p;
}

int main() {
    char text[3000], cuv1[20], cuv2[20], *point_text;
    fgets(text, 3000, stdin);
    scanf("%s%s", cuv1, cuv2);
    point_text = text;  // cream pointer pentru text sa il modificam
    while (point_text = strstr(point_text, cuv1)) {
        strdel(point_text, strlen(cuv1));
        strins(point_text, cuv2);
        point_text = point_text + strlen(cuv2);
    }
    printf("%s\n", text);
    return 0;
}