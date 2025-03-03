#include <stdio.h>

int main() {
  int n, k, m, C = 0, fact_n, fact_m,fact_n_m;
  scanf("%d%d", &n, &m);
  C = 1;
  //FOLSIND RECURENTA
  for (k = 1; k <= m; k++) {
    C = C * (n - k + 1) / k;
  }

  //Cu formula COMBINARILOR
  
  fact_n = 1;
  for (k = 1; k <= n; k++) fact_n *= k;
  fact_m = 1;
  for (k = 1; k <= m; k++) fact_m *= k;
  fact_n_m = 1;
  for (k = 1; k <= n - m; k++) fact_n_m *= k;
  C = fact_n / (fact_m * fact_n_m);
  printf("%d\n", C);
  return 0;
}