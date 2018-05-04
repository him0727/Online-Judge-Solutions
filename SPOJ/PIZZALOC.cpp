#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> res[21];
 
struct LOC {
  int x, y, pp;
} loc[21], sol[110];
 
int main() {
  int k, r, m, n;
  scanf("%d %d", &k, &r);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    loc[i] = LOC {x, y, 0};
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y, pp;
    scanf("%d %d %d", &x, &y, &pp);
    sol[i] = LOC {x, y, pp};
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (((loc[i].x - sol[j].x) * (loc[i].x - sol[j].x) + (loc[i].y - sol[j].y) * (loc[i].y - sol[j].y)) <= r * r) {
        res[i].push_back(j);
      }
    }
  }
  int from = (1 << k) - 1;
  int bound = (1 << m) - 1;
  int ans = 0;
  while (from < bound) {
    bool used[n];
    fill(used, used + n, false);
    int tmp = 0;
    for (int i = 0; i < m; i++) {
      if (from & (1 << i)) {
        for (int v : res[i]) {
          if (!used[v]) {
            tmp += sol[v].pp;
            used[v] = true;
          }
        }
      }
    }
    int a = (from & -from);
    int b = (from + a);
    int c = (((from ^ b) / a) >> 2);
    from = b | c;
    ans = max(ans, tmp);
  }
  printf("%d\n", ans);
  return 0;
}