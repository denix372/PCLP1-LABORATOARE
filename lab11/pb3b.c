#include <stdio.h>
#include <string.h>
#include <ctype.h>
//./executabil i c n input.txt vacanta
void strlwr(char *s) {
	for (int i = 0; i < strlen(s); i++) {
		s[i] = tolower(s[i]);
	}
}

int main(int argc, char **argv) {
	FILE *f = fopen(argv[argc - 2], "r");
        if (!f) {
          fprintf(stderr, "Eroare la deschiderea fisierului");
          return 0;
        }

        char s[1024] = {0};
	
	int ignore = 0, show_line_numbers = 0, show_line_count = 0;
	
	for (int i = 1; i < argc - 2; i++) {
          if (strcmp(argv[i], "c") == 0) {
            show_line_count = 1;
          }
          else if (strcmp(argv[i], "i") == 0) {
            ignore = 1;
          }
          else if (strcmp(argv[i], "n") == 0) {
            show_line_numbers = 1;
          }
        }
	
	char *word = strdup(argv[argc - 1]);
     
    if (ignore) strlwr(word);

    int cnt = 0;
	int matched_lines = 0;
	
	while (fgets(s, 1023, f)) {
		char *line = strdup(s);
		
		if (ignore) strlwr(line);
		
		if (strstr(line, word) != NULL) {
			if (show_line_numbers) 
				printf("[%d] ", cnt + 1);
			
			printf("%s", s);
			matched_lines += 1;
		}
		cnt += 1;
	}
	
	if (show_line_count) 
		printf("Numarul total de linii: %d\n", matched_lines);

	fclose(f);
    return 0;
}

