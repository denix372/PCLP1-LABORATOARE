#include <stdio.h>

int main() { int n, m, i, j,k=0, a[100], b[100], c[200];
  scanf("%d", &n);
  for (i = 0; i < n; i++) 
	  scanf("%d ", &a[i]);
  scanf("%d", &m);
  for (i = 0; i < m; i++) 
	  scanf("%d", &b[i]);
  i = 0;
  j = 0;
  while(i<n && j<m)
  {
	if(a[i]<b[j])
	  c[k++] = a[i++];
	else
	  c[k++] = b[j++];
  }
  while (i < n) c[k++] = a[i++];
  while (j < m) c[k++] = b[j++];
  
  for (i = 0; i < k; i++) 
	printf("%d ", c[i]);
  return 0;
}