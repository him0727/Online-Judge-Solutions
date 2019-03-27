#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int vodka[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", vodka[i] + j);
      }
    }
    if (vodka[1][1] > k || vodka[n][m] > k) {
      printf("-1\n");
      continue;
    }
    vector<vector<vector<bool>>> f(n + 1, vector<vector<bool>> (m + 1, vector<bool> (k + 1, false)));
    f[0][0][0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int vol = vodka[i][j]; vol <= k; vol++) {
          int c = vol - vodka[i][j];
          f[i][j][vol] = f[i - 1][j - 1][c] || f[i - 1][j][c] || f[i][j - 1][c];
        }
      }
    }
    int ans = -1;
    for (int i = k; i >= vodka[n][m]; i--) {
      if (f[n][m][i]) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}