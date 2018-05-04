#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXP = 21;
const int MAXM = 50;
const int INF = 1e4;
 
int n, mvt, trl;
int r, c;
int exc[MAXP + 1], vt[MAXP + 1], rl[MAXP + 1];
char mx[MAXM + 1][MAXM + 1];
 
int dp1[MAXP + 1][110][1100];
vector<int> ready;
 
void select_place() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= mvt; j++) {
      for (int k = 0; k <= trl; k++) {
        if (i == 0 || j == 0 || k == 0) {
          dp1[i][j][k] = 0;
          continue;
        }
        dp1[i][j][k] = dp1[i - 1][j][k];
        if (vt[i] <= j && rl[i] <= k) {
          dp1[i][j][k] = max(dp1[i][j][k], dp1[i - 1][j - vt[i]][k - rl[i]] + exc[i]);
        }
      }
    }
  }
  int cn = n, ct = mvt, cr = trl;
  while (cn > 0 && ct > 0 && cr > 0) {
    if (dp1[cn][ct][cr] > dp1[cn - 1][ct][cr]) {
      ready.push_back(cn);
      ct -= vt[cn];
      cr -= rl[cn];
    }
    cn--;
  }
}
 
int dir[] = {1, -1, 0, 0, 0, 0, -1, 1};
int sz, bound;
int dp2[MAXP][(1 << MAXP)];
int dist[MAXP][MAXM + 1][MAXM + 1];
vector<pair<int, int>> go;
 
void bfs(int from) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      dist[from][i][j] = INF;
    }
  }
  queue<pair<int, int>> q;
  int x = go[from].first;
  int y = go[from].second;
  q.push({x, y});
  dist[from][x][y] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    x = cur.first;
    y = cur.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[i];
      int ny = y + dir[i + 4];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
        continue;
      }
      if (mx[nx][ny] == '#' || dist[from][nx][ny] != INF) {
        continue;
      }
      dist[from][nx][ny] = dist[from][x][y] + 1;
      if (mx[nx][ny] == '+' || mx[nx][ny] == '.') {
        q.push({nx, ny});
      }
    }
  }
}
 
int calc(int from, int mask) {
  if (mask == bound) {
    return 0;
  }
  if (dp2[from][mask] != -1) {
    return dp2[from][mask];
  }
  int res = INF;
  for (int i = 0; i < sz; i++) {
    if ((mask & (1 << i)) == 0) {
      res = min(res, calc(i, (mask | (1 << i))) + dist[from][go[i].first][go[i].second]);
    }
  }
  dp2[from][mask] = res;
  return res;
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    double foo;
    scanf("%d %d %lf", &n, &mvt, &foo);
    trl = (int) (foo * 100);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d %lf", &exc[i], &vt[i], &foo);
      rl[i] = (int) (foo * 100);
    }
    bool found = false;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      scanf("%s", &mx[i]);
      if (!found) {
        for (int j = 0; j < c; j++) {
          if (mx[i][j] == '+') {
            go.push_back({i, j});
            found = true;
            break;
          }
        }
      }
    }
    select_place();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (mx[i][j] == '.' || mx[i][j] == '#' || mx[i][j] == '+') {
          continue;
        }
        found = false;
        int cur = mx[i][j] - 'A' + 1;
        for (auto v : ready) {
          if (cur == v) {
            go.push_back({i, j});
            found = true;
            break;
          }
        }
        if (!found) {
          mx[i][j] = '#';
        }
      }
    }
    sz = (int) go.size();
    bound = (1 << sz) - 1;
    for (int i = 0; i < sz; i++) {
      bfs(i);
    }
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < bound; j++) {
        dp2[i][j] = -1;
      }
    }
    int ans = calc(0, 1);
    printf(ans >= INF ? "-1\n" : "%d\n", ans);
    ready.clear();
    go.clear();
  }
  return 0;
}