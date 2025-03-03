#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N 4
 
typedef struct Persoana{
        char* nume;
        char* prenume;
} Persoana;
 
void serializeaza(Persoana v[], int nrPersoane, char* fileName)
{
        FILE* f = fopen(fileName, "wb");
        int i,lung;

        for (i = 0; i < nrPersoane; i++) {
          lung = strlen(v[i].nume);
          fwrite(&lung, sizeof(int), 1, f);
          fwrite(v[i].nume, sizeof(char), lung, f);

          lung = strlen(v[i].prenume);
          fwrite(&lung, sizeof(int), 1, f);
          fwrite(v[i].prenume, sizeof(char), lung, f);
        }

        fclose(f);
}
 
void deserializeaza(Persoana v[], int nrPersoane, char* fileName)
{
        FILE* f = fopen(fileName, "rb");
        int i, lung;
        for (i = 0; i < nrPersoane;i++)
        {
          fread(&lung, sizeof(int), 1, f);
          v[i].nume = malloc((lung+1) * sizeof(char));
          fread(v[i].nume, sizeof(char), lung, f);
          v[i].nume[lung] = '\0';

          fread(&lung, sizeof(int), 1, f);
          v[i].prenume = malloc((lung+1) * sizeof(char));
          fread(v[i].prenume, sizeof(char), lung, f);
          v[i].prenume[lung] = '\0';
        }

        fclose(f);
}
 
int main()
{
        Persoana v[N],w[N];
        char* prenume[N] = { "Eric", "Kyle", "Stan", "Kenny" };
        char* nume[N] = { "Cartman", "Broflovski", "Marsh", "McCormick" };
        int i;
        for (i = 0; i < N; i++){
                v[i].nume = nume[i];
                v[i].prenume = prenume[i];
        }
 
        // Serializam vectorul intr-un fisier
        serializeaza(v, N, "persoane.bin");
        // Deserializam in alt vector, din acelasi fisier. Ar trebui sa obtinem aceleasi informatii.
        deserializeaza(w, N, "persoane.bin");
 
        for (i = 0; i < N; i++){
                printf("%s %s\n",w[i].prenume,w[i].nume);
        }
 
        return 0;
}