#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  const int N = 50010;
  vector<vector<pair<int, long long>>> adj(N);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int foo, bar;
      long long s;
      scanf("%d %d %lld", &foo, &bar, &s);
      adj[foo].push_back({bar, s});
      adj[bar].push_back({foo, s});
    }
    vector<long long> speed(n + 1, 0);
    queue<int> q;
    q.push(1);
    speed[1] = 1e18 + 1;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto v : adj[cur]) {
        long long spd = min(v.second, speed[cur]);
        if (spd > speed[v.first]) {
          speed[v.first] = spd;
          q.push(v.first);
        }
      }
    }
    if (speed[n] == 0) {
      speed[n] = -1;
    }
    printf("%lld\n", speed[n]);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
  }
  return 0;
}