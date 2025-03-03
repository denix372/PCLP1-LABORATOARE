#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *input = fopen(argv[1], "r");
    
    if(input==NULL)
    {
      printf("Eroare la deschiderea fisierului");
      return 1;
    }

    char sir[1024] = {0};
	
	while (fgets(sir, 1023, input)) { 
		if (strstr(sir, argv[2]) != NULL) {
			printf("%s", sir);
		}
	}

	fclose(input);
	return 0;
}
//functii folosite fopen, fgets, fclose
//fgets citeste o linie din fisier!
