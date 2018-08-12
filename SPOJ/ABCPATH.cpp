#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  char c[55][55];
  bool was[55][55];
  int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
  int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
  int n, m;
  function<int(int, int, int, int)> solve = [&](int x, int y, int ch, int ans) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
      return ans;
    }
    if (was[x][y]) {
      return ans;
    }
    if (c[x][y] != char(ch + 'A')) {
      return ans;
    }
    was[x][y] = true;
    int s = 0;
    for (int i = 0; i < 8; i++) {
      s = max(s, solve(x + dx[i], y + dy[i], ch + 1, ans + 1));
    }
    return s;
  };
  int qq = 0;
  while (++qq) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%s", &c[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        was[i][j] = false;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == 'A') {
          ans = max(ans, solve(i, j, 0, 0));
        }
      }
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}