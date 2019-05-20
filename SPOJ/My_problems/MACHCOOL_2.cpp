#include <bits/stdc++.h>

using namespace std;

const int MAX = 110;

int itr;
vector<int> g[MAX];
vector<int> p(MAX), used(MAX);

bool dfs(int u) {
  if (u == -1) {
    return true;
  }
  if (used[u] == itr) {
    return false;
  }
  used[u] = itr;
  for (int v : g[u]) {
    if (dfs(p[v])) {
      p[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> tasks(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &tasks[i]);
    }
    int low = 0, high = 86400;
    int ans;
    while (low <= high) {
      int mid = (low + high) / 2;
      for (int i = 0; i < N; i++) {
        g[i].clear();
        used[i] = p[i] = -1;
        for (int j = 0; j < N; j++) {
          if (i != j && tasks[i] + mid <= tasks[j]) {
            g[i].push_back(j);
          }
        }
      }
      itr = 0;
      int need = 0;
      for (int i = 0; i < N; i++) {
        itr++;
        if (!dfs(i)) {
          need++;
        }
      }
      if (M >= need) {
        low = mid + 1;
        ans = mid;
      } else {
        high = mid - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}