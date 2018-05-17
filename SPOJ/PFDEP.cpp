#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> parent[110];
int in_deg[110];
bool used[110];
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int node, np, p;
  fill(in_deg, in_deg + n + 1, 0);
  fill(used, used + n + 1, false);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &node, &np);
    for (int j = 0; j < np; j++) {
      scanf("%d", &p);
      parent[p].push_back(node);
      in_deg[node]++;
    }
    sort(parent[p].begin(), parent[p].end());
  }
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 1; i <= n; i++) {
    if (in_deg[i] == 0) {
      q.push(i);
      used[i] = true;
      break;
    }
  }
  vector<int> seq;
  while (!q.empty()) {
    int cur = q.top();
    q.pop();
    seq.push_back(cur);
    for (auto v : parent[cur]) {
      if (--in_deg[v] == 0) {
        q.push(v);
        used[v] = true;
      }
    }
    if (q.size() == 0) {
      for (int i = 1; i <= n; i++) {
        if (in_deg[i] == 0 && !used[i]) {
          q.push(i);
          used[i] = true;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d", seq[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
  for (int i = 1; i <= n; i++) {
    parent[i].clear();
  }
  return 0;
}