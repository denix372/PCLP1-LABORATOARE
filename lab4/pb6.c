#include <stdio.h>

int main() { int n, a[100][100], i, j;
    scanf("%d", &n);
    for (i = 0; i < n;i++)
        for (j = 0; j < n; j++) 
            scanf("%d", &a[i][j]);
    for (j = 0; j < n; j++) 
        for (i = 0; i < n;i++)
            if(i+j>n-1)
                printf("%d ", a[i][j]);
    return 0;
}
