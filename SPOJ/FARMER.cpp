#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int q, m, k;
    scanf("%d %d %d", &q, &m, &k);
    if (q == 0 || (m == 0 && k == 0)) {
      printf("0\n");
      continue;
    }
    vector<int> mv(m), kv(k);
    int total = 0, ans = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", &mv[i]);
      total += mv[i];
    }
    for (int i = 0; i < k; i++) {
      scanf("%d", &kv[i]);
    }
    if (q != total) {
      if (q < total) {
        vector<vector<int>> f(m + 1, vector<int> (q + 1, 0));
        vector<bool> used(m, false);
        for (int i = 1; i <= m; i++) {
          for (int j = 1; j <= q; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= mv[i - 1]) {
              f[i][j] = max(f[i][j], f[i - 1][j - mv[i - 1]] + mv[i - 1]);
            }
          }
        }
        {
          int i = m, j = q;
          while (i > 0 && j > 0) {
            if (f[i][j] != f[i - 1][j]) {
              used[i - 1] = true;
              j -= mv[i - 1];
            }
            i--;
          }
        }
        for (int i = 0; i < m; i++) {
          if (!used[i]) {
            kv.push_back(mv[i]);
          }
        }
        ans = f[m][q];
        q -= f[m][q];
        total -= f[m][q];
      } else {
        ans = total;
        q -= total;
        total = 0;
      }
      if (q > 1) {
        sort(kv.begin(), kv.end(), greater<int> ());
        for (int i = 0; i < kv.size(); i++) {
          if (q == 0) {
            break;
          }
          if (q > kv[i]) {
            q -= kv[i];
            ans += kv[i] - 1;
          } else {
            ans += q - 1;
            q = 0;
          }
        }
      }
    } else {
      ans = q;
    }
    printf("%d\n", ans);
  }
  return 0;
}