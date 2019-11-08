clude <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 510;
 
int n, label;
bool g[MAX][MAX] = {false};
bool was[MAX] = {false};
pair<int, int> res[MAX];
 
bool is_connected() {
  fill(was, was + n, false);
  int connected = 1;
  queue<int> q;
  q.push(0);
  was[0] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (i != cur && !was[i] && g[cur][i]) {
        connected++;
        was[i] = true;
        q.push(i);
      }
    }
  }
  return connected == n;
}
 
bool dfs(int cur, int source) {
  was[cur] = true;
  res[cur] = {res[source].second, label++};
  for (int v = 0; v < n; v++) {
    if (cur != v && v != source && g[cur][v]) {
      if (g[v][source]) {
        continue;
      }
      if (was[v] || !dfs(v, cur)) {
        return false;
      }
    }
  }
  return true;
}
 
bool solve_kcore(int v1, int v2, int v3) {
  vector<int> nodes = {v1, v2, v3};
  for (int v = 0; v < n; v++) {
    if (v == v1 || v == v2 || v == v3) {
      continue;
    }
    int deg = 0;
    for (int u : nodes) {
      if (g[v][u]) {
        deg++;
      }
    }
    if (deg > 1) {
      if (deg != (int) nodes.size()) {
        return false;
      }
      nodes.push_back(v);
    }
  }
  fill(was, was + n, false);
  label = 2;
  for (int u : nodes) {
    was[u] = true;
    res[u] = {1, label++};
  }
  for (int v = 0; v < n; v++) {
    if (was[v]) {
      continue;
    }
    int from, deg = 0;
    for (int u : nodes) {
      if (g[v][u]) {
        from = u;
        deg++;
      }
    }
    if (deg > 1 || (deg == 1 && !dfs(v, from))) {
      return false;
    }
  }
  return true;
}
 
bool solve_simple() {
  vector<int> tails;
  for (int v = 0; v < n; v++) {
    int deg = 0;
    for (int u = 0; u < n; u++) {
      if (v != u && g[v][u]) {
        deg++;
      }
    }
    if (deg > 2) {
      return false;
    }
    if (deg == 1) {
      tails.push_back(v);
    }
  }
  if ((int) tails.size() != 2) {
    return false;
  }
  label = 1;
  int from = tails[0];
  int to = tails[0];
  while (true) {
    res[to] = {label, label + 1};
    label++;
    if (to == tails[1]) {
      break;
    }
    for (int v = 0; v < n; v++) {
      if (v != from && g[to][v]) {
        from = to;
        to = v;
        break;
      }
    }
  }
  return true;
}
 
bool solve() {
  if (!is_connected()) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (g[i][j] && g[j][k] && g[i][k]) {
          return solve_kcore(i, j, k);
        }
      }
    }
  }
  return solve_simple();
}
 
int main() {
  scanf("%d", &n);
  for (int from = 0; from < n; from++) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int to;
      scanf("%d", &to);
      to--;
      g[from][to] = g[to][from] = true;
    }
  }
  if (n == 1) {
    printf("YES\n1 2\n");
  } else if (!solve()) {
    printf("NO\n");
  } else {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", res[i].first, res[i].second);
    }
  }
  return 0;
}