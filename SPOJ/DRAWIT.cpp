#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    vector<bool> used(n + 1);
    for (int i = 0; i < k; i++) {
      int s, d, m;
      scanf("%d %d %d", &s, &d, &m);
      adj[s].push_back(d);
      adj[d].push_back(s);
      deg[s] += m;
      deg[d] += m;
    }
    int visited = 0;
    function<void (int)> dfs = [&](int node) {
      if (used[node]) {
        return;
      }
      used[node] = true;
      visited++;
      for (auto v : adj[node]) {
        dfs(v);
      }
    };
    dfs(1);
    if (visited != n) {
      printf("NO\n");
      continue;
    }
    int odd = 0;
    for (int i = 1; i <= n; i++) {
      if (deg[i] & 1) {
        odd++;
      }
    }
    if (odd <= 2) {
      if (odd == 0) {
        printf("YES 1\n");
      } else {
        int ans;
        for (int i = 1; i <= n; i++) {
          if (deg[i] & 1) {
            ans = i;
            break;
          }
        }
        printf("YES %d\n", ans);
      }
    } else {
      printf("NO\n");
    }
  }
  return 0;
}