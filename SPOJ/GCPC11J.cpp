#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> adj(100010);
bool visited[100010];
 
pair<int, int> dfs(int from, int dist) {
  if (visited[from]) {
    return {from, dist};
  }
  visited[from] = true;
  int ans = ++dist;
  int node = from;
  for (int i = 0; i < (int) adj[from].size(); i++) {
    if (!visited[adj[from][i]]) {
      pair<int, int> cur = dfs(adj[from][i], dist);
      if (ans < cur.second) {
        ans = cur.second;
        node = cur.first;
      }
      visited[adj[from][i]] = false;
    }
  }
  visited[from] = false;
  return {node, ans};
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      visited[i] = false;
    }
    for (int i = 0; i < n - 1; i++) {
      int from, to;
      scanf("%d %d", &from, &to);
      adj[from].push_back(to);
      adj[to].push_back(from);
    }
    pair<int, int> random_node = dfs(0, -1);
    pair<int, int> target_node = dfs(random_node.first, -1);
    int ans = target_node.second;
    ans = ans & 1 ? (ans + 1) >> 1 : ans >> 1;
    printf("%d\n", ans);
  }
  return 0;
}