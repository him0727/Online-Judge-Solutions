#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
      }
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    cin >> ex >> ey;
    if (sx == ex && sy == ey) {
      cout << 1 << '\n';
      continue;
    }
    int ans = 11;
    for (int mask = 1; mask < (1 << 10); mask++) {
      if (__builtin_popcount(mask) >= ans) {
        continue;
      }
      if ((mask & (1 << m[sx][sy])) == 0 || (mask & (1 << m[ex][ey])) == 0) {
        continue;
      }
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      bool done = false;
      queue<pair<int, int>> q;
      q.push({sx, sy});
      visited[sx][sy] = true;
      while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            if (dx * dy != 0) {
              continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
              continue;
            }
            if (visited[nx][ny] || (mask & (1 << m[nx][ny])) == 0) {
              continue;
            }
            if (nx == ex && ny == ey) {
              ans = min(ans, __builtin_popcount(mask));
              done = true;
              break;
            }
            q.push({nx, ny});
            visited[nx][ny] = true;
          }
        }
        if (done) {
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}