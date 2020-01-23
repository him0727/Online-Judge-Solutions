#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N), rg(N);
    vector<int> order, comp;
    vector<bool> visited(N);
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      g[b].push_back(a);
      rg[a].push_back(b);
    }
    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      for (int v : g[u]) {
        if (!visited[v]) {
          dfs(v);
        }
      }
      order.push_back(u);
    };
    function<void(int)> r_dfs = [&](int u) {
      visited[u] = true;
      comp.push_back(u);
      for (int v : rg[u]) {
        if (!visited[v]) {
          r_dfs(v);
        }
      }
    };
    visited.assign(N, false);
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        dfs(i);
      } 
    }
    vector<vector<int>> comps;
    visited.assign(N, false);
    for (int i = N - 1; i >= 0; i--) {
      int u = order[i];
      if (!visited[u]) {
        r_dfs(u);
        comps.push_back(comp);
        comp.clear();
      }
    }
    int sz = (int) comps.size();
    vector<int> belong(N);
    for (int u = 0; u < sz; u++) {
      for (int v : comps[u]) {
        belong[v] = u;
      }
    }
    map<pair<int, int>, bool> used;
    vector<vector<int>> new_g(sz);
    for (int u = 0; u < N; u++) {
      for (int v : g[u]) {
        if (belong[u] != belong[v]) {
          if (used.find({belong[u], belong[v]}) == used.end()) {
            used.insert({{belong[u], belong[v]}, true});
            new_g[belong[u]].push_back(belong[v]);
          }
        }
      }
    }
    vector<int> in_deg(sz, 0);
    for (int u = 0; u < sz; u++) {
      for (int v : new_g[u]) {
        in_deg[v]++;
      }
    }
    vector<bool> new_visited(sz);
    vector<int> total(sz);
    for (int u = 0; u < sz; u++) {
      total[u] = (int) comps[u].size();
    }
    function<int(int)> new_dfs = [&](int u) {
      int res = (int) comps[u].size();
      new_visited[u] = true;
      for (int v : new_g[u]) {
        if (!new_visited[v]) {
          res += new_dfs(v);
        }
      }
      return res;
    };
    int max_ans = 0;
    for (int u = 0; u < sz; u++) {
      new_visited.assign(sz, false);
      if (in_deg[u] == 0) {
        total[u] = new_dfs(u);
        max_ans = max(max_ans, total[u]);
      }
    }
    vector<int> ans;
    for (int u = 0; u < sz; u++) {
      if (total[u] == max_ans) {
        for (int v : comps[u]) {
          ans.push_back(v + 1);
        }
      }
    }
    sort(ans.begin(), ans.end());
    for (int v : ans) {
      cout << v << ' ';
    }
    cout << '\n';
  }
  return 0;
}