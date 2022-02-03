#include <bits/stdc++.h>

using namespace std;

bool dfs(int u, int itr, int extra, vector<pair<int, int>>& tasks, vector<vector<int>>& g, vector<int>& p, vector<int>& used) {
  if (u == -1) {
    return true;
  }
  if (used[u] == itr) {
    return false;
  }
  used[u] = itr;
  for (int v : g[u]) {
    if (tasks[v].first >= tasks[u].second + extra && dfs(p[v], itr, extra, tasks, g, p, used)) {
      p[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    vector<vector<int>> g(n);
    vector<int> p(n, -1), used(n, -1);
    for (int i = 0; i < n; i++) {
      cin >> tasks[i].first;
      tasks[i].second = 0;
      for (int j = 0; j < 4; j++) {
        int dur;
        cin >> dur;
        tasks[i].second = max(tasks[i].second, dur);
      }
      tasks[i].second += tasks[i].first;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && tasks[j].first >= tasks[i].second) {
          g[i].push_back(j);
        }
      }
    }
    int itr = 0;
    int least = 0;
    for (int i = 0; i < n; i++) {
      itr++;
      if (!dfs(i, itr, 0, tasks, g, p, used)) {
        least++;
      }
    }
    int ans = 0;
    int low = 0;
    int high = 86400;
    while (low <= high) {
      int mid = (low + high) / 2;
      for (int i = 0; i < n; i++) {
        used[i] = p[i] = -1;
      }
      itr = 0;
      int need = 0;
      for (int i = 0; i < n; i++) {
        itr++;
        if (!dfs(i, itr, mid, tasks, g, p, used)) {
          need++;
        }
      }
      if (need <= least) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}