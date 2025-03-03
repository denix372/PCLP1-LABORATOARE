#include <stdio.h>

void spirala(int a[][100], int n, int m, int v[]) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int k=0;
    while (top <= bottom && left <= right) {
        // Print left column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            v[k++] = a[i][left];
        }
        left++;

        // Print bottom row (left to right)
        if (top <= bottom) {
            for (int i = left; i <= right; i++) {
                v[k++] = a[bottom][i];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                v[k++] = a[i][right];
            }
            right--;
        }
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                v[k++] = a[top][i];
            }
            top++;
        }
    }
}

void afisare (int V[], int dim)
{
    for(int i=0;i<dim;i++) printf("%d ",V[i]);
    printf("\n");
}

int main()
{
    int n,m,i,j,a[100][100],v[100];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&a[i][j]);
    spirala(a,n,m,v);
    afisare(v,n*m);
    return 0;
}