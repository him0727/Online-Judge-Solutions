#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 10010;
const int M = 14;
 
int p[N][M], d[N];
vector<vector<int>> adj(N);
 
void dfs(int node) {
  for (auto v : adj[node]) {
    if (p[v][0] == -1) {
      p[v][0] = node;
      d[v] = d[node] + 1;
      dfs(v);
    }
  }
}
 
int lca(int a, int b) {
  if (d[a] < d[b]) {
    swap(a, b);
  }
  {
    int i = M - 1;
    while (i >= 0) {
      if (d[a] - (1 << i) >= d[b]) {
        a = p[a][i];
      }
      i--;
    }
  }
  if (a == b) {
    return a;
  }
  for (int i = M - 1; i >= 0; i--) {
    if (p[a][i] != -1 && p[a][i] != p[b][i]) {
      a = p[a][i];
      b = p[b][i];
    }
  }
  return p[a][0];
}
 
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; (1 << j) < n; j++) {
      p[i][j] = -1;
    }
  }
  d[1] = 0;
  p[1][0] = 1;
  dfs(1);
  for (int i = 1; (1 << i) < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (p[j][i - 1] != -1) {
        p[j][i] = p[p[j][i - 1]][i - 1];
      }
    }
  }
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (d[a] < d[b]) {
      printf("NO\n");
    } else {
      printf("YES ");
      printf("%d\n", lca(a, b));
    }
  }
  return 0;
}