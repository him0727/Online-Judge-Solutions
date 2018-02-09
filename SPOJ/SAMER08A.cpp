#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 501;
 
int dist[MAX];
vector<int> parent[MAX];
vector<pair<int, int>> adj[MAX];
bool is_adj[MAX][MAX], visited[MAX];
 
int dijkstra(int from, int to, int n, bool first) {
  for (int i = 0; i < n; i++) {
    parent[i].clear();
    dist[i] = INT_MAX;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, from));
  dist[from] = 0;
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (v == to && !first) {
      return dist[v];
    }
    if (v == to && first) {
      continue;
    }
    for (int i = 0; i < adj[v].size(); i++) {
      int u = adj[v][i].first;
      int w = adj[v][i].second;
      if (dist[v] + w < dist[u] && is_adj[v][u]) {
        dist[u] = dist[v] + w;
        pq.push(make_pair(dist[u], u));
        parent[u].clear();
        parent[u].push_back(v);
      }
      if (dist[v] + w == dist[u] && is_adj[v][u]) {
        parent[u].push_back(v);
      }
    }
  }
  return dist[to] == INT_MAX ? -1 : dist[to];
}
 
void bfs(int d) {
  queue<int> q;
  q.push(d);
  visited[d] = true;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int i = 0; i < parent[c].size(); i++) {
      int cc = parent[c][i];
      if (!visited[cc]) {
        visited[cc] = true;
        is_adj[cc][c] = false;
        q.push(cc);
      }
    }
  }
}
 
int main() {
  int n, m, s, d;
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) {
      break;
    }
    scanf("%d %d", &s, &d);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      visited[i] = false;
      for (int j = 0; j < n; j++) {
        is_adj[i][j] = false;
      }
    }
    for (int i = 0; i < m; i++) {
      int p, c, w;
      scanf("%d %d %d", &p, &c, &w);
      adj[p].push_back(make_pair(c, w));
      is_adj[p][c] = true;
    }
    int ans = dijkstra(s, d, n, true);
    if (ans == -1) {
      printf("-1\n");
      continue;
    }
    bfs(d);
    ans = dijkstra(s, d, n, false);
    printf("%d\n", ans);
  }
  return 0;
}