#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Produs.h"

// Problema 2
void creare_fisier(char *nume_fisier) {
    struct Produs produse[100];

    for (int i = 0; i < 100; i++) {
        int x = rand();
        sprintf(produse[i].nume_produs, "Produs%d", x);
        produse[i].cantitate = x % 100;
        produse[i].pret_produs = x <= 100 ? x : x % 100;
    }
    // fiser binar
    FILE *fout = fopen(nume_fisier, "wb");
    fwrite(produse, sizeof(struct Produs), 100, fout);
    fclose(fout);
}
//Problema 3
void afisare_ecran(char *nume_fisier) {
    struct Produs produse[100];

    FILE *fin = fopen(nume_fisier, "rb");
    fread(produse, sizeof(struct Produs), 100, fin);
    fclose(fin);

    for (int i = 0; i < 100; i++) {
        printf("Nume produs: %s\n", produse[i].nume_produs);
        printf("Cantitate: %d\n", produse[i].cantitate);
        printf("Pret produs: %lf\n", produse[i].pret_produs);
        printf("\n");
    }
}
//Problema 4
void sortare(char *nume_fisier) {
    struct Produs produse[100];
    FILE *fisier = fopen(nume_fisier, "rb+");
    fread(produse, sizeof(struct Produs), 100, fisier);
    fseek(fisier, 0, SEEK_SET); //Dupa citirea produselor cursorul de afla la sfarsitul fisierului
    int i, j;
    for (i = 0; i < 99; i++) {
        for (j = i + 1; j < 100; j++) {
            if (strcmp(produse[i].nume_produs, produse[j].nume_produs) > 0) {
                char auxc[21];
                int auxi;
                float auxd;

                strcpy(auxc, produse[i].nume_produs);
                strcpy(produse[i].nume_produs, produse[j].nume_produs);
                strcpy(produse[j].nume_produs, auxc);

                auxi = produse[i].cantitate;
                produse[i].cantitate = produse[j].cantitate;
                produse[j].cantitate = auxi;

                auxd = produse[i].pret_produs;
                produse[i].pret_produs = produse[j].pret_produs;
                produse[j].pret_produs = auxd;
            }
        }
    }
    fwrite(produse, sizeof(struct Produs), 100, fisier);
    fclose(fisier);
}

//Problema 5
void citire_produs(struct Produs produs,char *nume_fisier) { 
    scanf("%s", produs.nume_produs);
    int i,ok=0;
    FILE *fisier = fopen(nume_fisier, "rb");
    struct Produs produse[100];
    fread(produse, sizeof(struct Produs), 100, fisier);
    for (i = 0; i < 100; i++) {
      if (!strcmp(produs.nume_produs, produse[i].nume_produs)) {
        printf("---------------Am gasit produsul ----------\n");
        printf("Produsul are numele:%s\n", produs.nume_produs);
        printf("Are cantitatea: %d\n", produse[i].cantitate);
        printf("Si pretul: %lf\n",produse[i].pret_produs);
        ok = 1;
        break;
      }
    }
    if(ok==0)
      printf("NU S-A GASIT NICIUN PRODUS CU NUMELE %s\n", produs.nume_produs);  
    fclose(fisier);
}
//Problema 6
void readaugare_produs(struct Produs produs, char *nume_fisier){
  FILE *binar = fopen(nume_fisier, "rb+");
  scanf("%s", produs.nume_produs);
  struct Produs produse[100];
  int i, ok = 0;
  for (i = 0; i < 100; i++) {
    fread(&produse[i], sizeof(struct Produs), 1, binar);
    if(!strcmp(produse[i].nume_produs, produs.nume_produs))
    {
        int x = rand();
        sprintf(produs.nume_produs, "Produs%d", x);
        produs.cantitate = x % 100;
        produs.pret_produs = x <= 100 ? x : x % 100;
        // ne repozition sa rescrie produsul respectiv;
        fseek(binar, -sizeof(struct Produs), SEEK_CUR);
        fwrite(&produs, sizeof(struct Produs), 1, binar);
        ok = 1;
        break;
    }
  }
  fclose(binar);
  if(ok==0) printf("NU S-A GASIT NICIUN PRODUS CU NUMELE %s\n", produs.nume_produs);  

}

int main(int argc, char **argv) {
    srand(time(NULL));
    struct Produs produsul;

    creare_fisier("produse.bin");//2
    //afisare_ecran("produse.bin"); //3 
    sortare("produse.bin"); //4
    printf("------------Produse sortare crescator-----------------\n");
    afisare_ecran("produse.bin");
    citire_produs(produsul, "produse.bin");//5
    readaugare_produs(produsul, "produse.bin");//6
    printf("------------Reafisare cu produs schimbat-----------------\n");
    afisare_ecran("produse.bin");
    return 0;
}
