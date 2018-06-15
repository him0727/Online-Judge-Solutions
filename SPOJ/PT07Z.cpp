#include <bits/stdc++.h>
 
using namespace std;
 
int far, ans;
bool was[10010];
vector<vector<int>> adj(10010);
 
void dfs(int node, int dist) {
  if (was[node]) {
    return;
  }
  was[node] = true;
  if (dist > ans) {
    ans = dist;
    far = node;
  }
  for (int i = 0; i < adj[node].size(); i++) {
    dfs(adj[node][i], dist + 1);
  }
}
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    adj[foo].push_back(bar);
    adj[bar].push_back(foo);
  }
  fill(was, was + n + 1, false);
  ans = -1;
  dfs(1, 0);
  fill(was, was + n + 1, false);
  ans = -1;
  dfs(far, 0);
  printf("%d\n", ans);
  return 0;
}