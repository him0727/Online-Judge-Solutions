#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  double f[1010][1010], p[1010];
  while (tt--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%lf", p + i);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i + 1; j++) {
        f[i][j] = 0.0;
      }
    }
    f[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
      f[i][0] = f[i - 1][0] * (1.0 - p[i]);
      for (int j = 1; j <= i; j++) {
        f[i][j] = f[i - 1][j - 1] * p[i] + f[i - 1][j] * (1.0 - p[i]);
      }
    }
    printf("%.10lf\n", f[n][k]);
  }
  return 0;
}