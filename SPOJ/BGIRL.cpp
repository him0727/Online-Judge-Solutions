#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  const int N = 100100;
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      int j = i;
      while ((j += i) <= N) {
        if (prime[j]) {
          prime[j] = false;
        }
      }
    }
  }
  vector<vector<int>> r(N);
  vector<bool> was(N, false);
  function<int(int)> dfs = [&](int p) {
    if (was[p]) {
      return 0;
    }
    was[p] = true;
    int res = 1;
    for (auto v : r[p]) {
      res += dfs(v);
    }
    return res;
  };
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      r[a].push_back(b);
      r[b].push_back(a);
    }
    int ans = 0, tmp;
    for (int i = 1; i <= n; i++) {
      if (!was[i]) {
        tmp = dfs(i);
        if (prime[tmp]) {
          ans = max(ans, tmp);
        }
      }
    }
    if (ans == 0) {
      ans = -1;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      r[i].clear();
      was[i] = false;
    }
  }
  return 0;
}