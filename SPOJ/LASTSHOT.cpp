#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, a, b;
vector<int> bomb[10001];
bool visited[10001];
 
int dfs(int start, int count) {
  if (visited[start]) return count;
  visited[start] = true;
  for (int j = 0; j < bomb[start].size(); j++) {
    if (!visited[bomb[start][j]]) count += dfs(bomb[start][j], 1);
  }
  return count;
}
 
void reset() {
  for (int i = 0; i <= n; i++) {
    visited[i] = false;
  }
}
 
int main() {
  scanf("%d %d", &n, &m);
  reset();
  while (m--) {
    scanf("%d %d", &a, &b);
    bomb[a].push_back(b);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dfs(i, 1));
    reset();
  }
  printf("%d\n", ans);
  return 0;
}