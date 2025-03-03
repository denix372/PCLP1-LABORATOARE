#include <stdio.h>

int main() {
    int n, lungime = 0, putere = 1, cifre = 1;
    scanf("%d", &n);

    while (putere * 10 <= n)  
    {//parcurgem fiecare interval 1-9, 10-99, 100-999... 
        lungime += cifre * (putere * 9); 
        putere *= 10;
        cifre++;
    }
    lungime += cifre * (n - putere + 1);

    printf("%d\n", lungime);
    return 0;
}
