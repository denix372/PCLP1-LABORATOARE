#include <stdio.h>
#define BUFMAX 1005
 //Problema rezolvata
int main(int argc, char **argv)
{
    FILE *pFile;
    char buffer[BUFMAX];
 
    pFile = fopen("myfile.txt" , "r");
    if (pFile == NULL) {
        printf("Nu s-a putut deschide fisierul");
        return 1;
    }
 
    while (fgets(buffer, BUFMAX, pFile) != NULL) {
        printf("%s", buffer);
    }
    fclose(pFile);
    return 0;
}
// functii folosite: fopen, fgets, fclose