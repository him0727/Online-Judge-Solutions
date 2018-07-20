#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  const int M = 25;
  int m, n;
  int a[M], b[M];
  int f[M][110];
  while (1) {
    scanf("%d %d", &m, &n);
    if (m == 0 && n == 0) {
      break;
    }
    for (int i = 0; i < m; i++) {
      scanf("%d %d", a + i, b + i);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j <= n; j++) {
        f[i][j] = 0;
        for (int k = a[i]; k <= b[i]; k++) {
          if (i == 0) {
            f[i][k] = 1;
            continue;
          }
          if (j - k >= 0) {
            f[i][j] += f[i - 1][j - k];
          }
        }
      }
    }
    printf("%d\n", f[m - 1][n]);
  }
  return 0;
}