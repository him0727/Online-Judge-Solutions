#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;
int lt[MAX], rt[MAX];
int lt_child[MAX], rt_child[MAX];
int lt_parent[MAX], rt_parent[MAX];
int ans;

void dfs(int root) {
  if (lt[root] != -1) {
    lt_parent[lt[root]] = lt_parent[root] + 1;
    dfs(lt[root]);
    lt_child[root] = lt_child[lt[root]] + 1;
  }
  if (rt[root] != -1) {
    rt_parent[rt[root]] = rt_parent[root] + 1;
    dfs(rt[root]);
    rt_child[root] = rt_child[rt[root]] + 1;
  }
  ans += min(lt_child[root], rt_child[root]) + min(lt_parent[root], rt_child[root]) + min(rt_parent[root], lt_child[root]);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, p, root;
    scanf("%d", &n);
    fill(lt, lt + n, -1);
    fill(rt, rt + n, -1);
    for (int i = 0; i < n; i++) {
      lt_child[i] = 0;
      rt_child[i] = 0;
      lt_parent[i] = 0;
      rt_parent[i] = 0;
      scanf("%d", &p);
      if (p == -1) {
        root = i;
        continue;
      }
      if (lt[p] == -1) {
        lt[p] = i;
      } else {
        rt[p] = i;
      }
    }
    ans = 0;
    dfs(root);
    printf("%d\n", ans);
  }
  return 0;
}