#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char **v1; //vector de cuvinte
	int *v2; //vector de nr intregi
	int cap = 1, n, lungime_v1_v2 = 0;
	
	v1 = malloc(cap * sizeof(char *)); //vector de cuvinte unice
	v2 = malloc(cap * sizeof(int)); //vector de frecventa alocat dinamic
	
	for (int i = 0; i < cap; i++) {
		v1[i] = malloc(20 * sizeof(char));
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //parcurgem cuvintele
		char cuvant[20];
		scanf("%s", cuvant); //citim cuvantul
		
		int found = 0;
		
		for (int j = 0; j < lungime_v1_v2; j++) {
			if (strcmp(v1[j], cuvant) == 0) {
				v2[j]++; // il numaram in vectorul de frecventa
				found = 1; //il contorizam/marcam flag
				break;
			}
		}
		
		if (!found) { //daca nu s-a gasit (daca e unic)
			strcpy(v1[lungime_v1_v2], cuvant); //il punem in vector de cuvinte unice
			v2[lungime_v1_v2] = 1; //marcam gasit pentru prima data
			lungime_v1_v2++; //crestem dimenisunea
			
			if (lungime_v1_v2 == cap) { //realocam daca e cazul
				cap *= 2;
				v2 = realloc(v2, cap * sizeof(int));
				v1 = realloc(v1, cap * sizeof(char *));
			 	
				for (int j = cap / 2; j < cap; j++) {
					v1[j] = malloc(20 * sizeof(char));
				}
			}
		}
	}
	
	for (int i = 0; i < lungime_v1_v2; i++) {
		printf("%s: %d\n", v1[i], v2[i]);
	}
	
	return 0;
}

