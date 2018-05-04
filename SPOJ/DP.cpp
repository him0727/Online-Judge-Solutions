#include <bits/stdc++.h>
 
using namespace std;
 
char t[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int d[55][55];
int n, m;
 
void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  d[sx][sy] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int x = cur.first;
    int y = cur.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nd;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        continue;
      }
      if (t[x][y] == 'X' || t[x][y] == '$' || t[nx][ny] == 'X' || t[nx][ny] == '$') {
        nd = d[x][y] + 2;
        if (d[nx][ny] == -1 || nd < d[nx][ny]) {
          d[nx][ny] = nd;
          q.push({nx, ny});
        }
      } else {
        int diff = abs((t[nx][ny] - '0') - (t[x][y] - '0'));
        if (diff == 0) {
          nd = d[x][y] + 1;
          if (d[nx][ny] == -1 || nd < d[nx][ny]) {
            d[nx][ny] = nd;
            q.push({nx, ny});
          }
        }
        if (diff == 1) {
          nd = d[x][y] + 3;
          if (d[nx][ny] == -1 || nd < d[nx][ny]) {
            d[nx][ny] = nd;
            q.push({nx, ny});
          }
        }
      }
    }
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int sx, sy;
    vector<pair<int, int>> b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", t[i]);
      for (int j = 0; j < m; j++) {
        d[i][j] = -1;
        if (t[i][j] == 'X') {
          sx = i;
          sy = j;
        }
        if (t[i][j] == '$') {
          b.push_back({i, j});
        }
      }
    }
    int sz = (int) b.size();
    if (sz == 0) {
      printf("0\n");
      continue;
    }
    bfs(sx, sy);
    bool ok = true;
    vector<int> bd;
    for (auto v : b) {
      if (d[v.first][v.second] == -1) {
        ok = false;
        break;
      }
      bd.push_back(d[v.first][v.second]);
    }
    if (!ok) {
      printf("-1\n");
      continue;
    }
    sort(bd.begin(), bd.end());
    vector<vector<int>> boy(2);
    int total[2];
    int ans = INT_MAX;
    for (int i = 0; i < (1 << sz); i++) {
      total[0] = total[1] = 0;
      for (int j = 0; j < sz; j++) {
        boy[(i & (1 << j)) != 0].push_back(bd[j]);
      }
      for (int j = 0; j < 2; j++) {
        for (auto v : boy[j]) {
          total[j] += (v << 1);
        }
        if ((int) boy[j].size() > 0) {
          total[j] -= boy[j][boy[j].size() - 1];
        }
      }
      ans = min(ans, max(total[0], total[1]));
      boy[0].clear();
      boy[1].clear();
    }
    printf("%d\n", ans);
  }
  return 0;
}