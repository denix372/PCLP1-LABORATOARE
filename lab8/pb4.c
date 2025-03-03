#include <stdio.h>
#include <stdlib.h>

int main() {
  int **c, i, j, k, n,*vim1,*vi;
  scanf("%d%d", &n,&k);
  //PRIMA VARIANTA CEA INEFICIENTA D P D V AL TIMPULUI ~~~~~~~~~~~~~~~~~~~~~~~~~
  /*
  vim1 = malloc(2 * sizeof(int));
  vi = malloc(2 * sizeof(int));
  vim1[0] = vim1[1] = 1;

     for (i = 2; i <= n; i++) {
        vi = realloc(vi, (i + 1) * sizeof(int));
        vi[0] = vi[i] = 1;
        for (j = 1; j < i; j++) {
            vi[j] = vim1[j] + vim1[j - 1];
        }
        vim1 = realloc(vim1, (i + 1) * sizeof(int));
        for (j = 0; j <= i; j++) vim1[j] = vi[j];
        }

        printf("%d\n", vi[k]);
        return 0;
        */
//VARIANTA SUPER EFICIENTA

    vim1 = malloc(2 * sizeof(int));
    vi = malloc(2 * sizeof(int));
    vim1[0] = vim1[1] = 1;

     for (i = 2; i <= n; i++) {
        vi = realloc(vi, (i + 1) * sizeof(int));
        vi[0] = vi[i] = 1;
        for (j = 1; j < i; j++) 
            vi[j] = vim1[j] + vim1[j - 1];

        vim1 = realloc(vim1, (i + 1) * sizeof(int));
        //for (j = 0; j <= i; j++) vim1[j] = vi[j];
        int *aux;
        aux = vim1;
        vim1 = vi;
        vi = aux;
     }
     //ATENTIE ULTIMA INTERATIE INTERSCHIMBA POINTERII SI DECI TREBUIE SA AFISAM VIM1[K] SI NU VI[K] 
    printf("%d\n", vim1[k]); //!!!
    return 0;
}