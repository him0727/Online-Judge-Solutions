#include <bits/stdc++.h>

using namespace std;

const int MAX = 110;

int itr, mid;
int from[MAX], dur[MAX], p[MAX], used[MAX];
vector<int> g[MAX];

bool dfs(int u) {
  if (u == -1) {
    return true;
  }
  if (used[u] == itr) {
    return false;
  }
  used[u] = itr;
  for (int v : g[u]) {
    if (from[v] >= from[u] + dur[u] + mid && dfs(p[v])) {
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
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &from[i]);
      dur[i] = 0;
      for (int j = 0; j < 4; j++) {
        int tmp;
        scanf("%d", &tmp);
        dur[i] = max(dur[i], tmp);
      }
    }
    for (int i = 0; i < N; i++) {
      g[i].clear();
      used[i] = p[i] = -1;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i != j && from[j] >= from[i] + dur[i]) {
          g[i].push_back(j);
        }
      }
    }
    mid = itr = 0;
    int least = 0;
    for (int i = 0; i < N; i++) {
      itr++;
      if (!dfs(i)) {
        least++;
      }
    }
    int low = 0, high = 86400;
    int ans;
    while (low <= high) {
      mid = (low + high) / 2;
      for (int i = 0; i < N; i++) {
        used[i] = p[i] = -1;
      }
      itr = 0;
      int need = 0;
      for (int i = 0; i < N; i++) {
        itr++;
        if (!dfs(i)) {
          need++;
        }
      }
      if (need > least) {
        high = mid - 1;
      } else {
        low = mid + 1;
        ans = mid;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}