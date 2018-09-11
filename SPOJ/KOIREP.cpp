#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int r[n][m], at[n];
  fill(at, at + n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", r[i] + j);
    }
    sort(r[i], r[i] + m);
  }
  int ans = 1e9 + 1;
  while (1) {
    int mi = 1e9 + 1, ma = -1;
    int mii;
    for (int i = 0; i < n; i++) {
      if (mi > r[i][at[i]]) {
        mi = r[i][at[i]];
        mii = i;
      }
      ma = max(ma, r[i][at[i]]);
    }
    ans = min(ans, ma - mi);
    if (ans == 0) {
      break;
    }
    bool change = false;
    if (at[mii] < m - 1 && r[mii][at[mii]] < ma) {
      at[mii]++;
      change = true;
    }
    if (!change) {
      break;
    }
    for (int i = 0; i < n; i++) {
      if (i == mii) {
        continue;
      }
      if (at[i] < m - 1 && r[i][at[i]] < ma) {
        if (r[i][at[i] + 1] <= ma) {
          at[i]++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}