#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> bfs(int sx, int sy, vector<string>& g) {
  const vector<int> DX = {1, -1, 0, 0};
  const vector<int> DY = {0, 0, 1, -1};
  int n = (int) g.size();
  int m = (int) g[0].size();
  vector<vector<int>> cost(n, vector<int>(m, -1));
  cost[sx][sy] = 0;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nx = x + DX[d];
      int ny = y + DY[d];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (g[x][y] == '.' && g[nx][ny] == '.') {
          if (cost[nx][ny] == -1 || cost[nx][ny] > cost[x][y]) {
            cost[nx][ny] = cost[x][y];
            q.push({nx, ny});
          }
        }
        if (g[x][y] != '.' || g[nx][ny] != '.') {
          if (cost[nx][ny] == -1 || cost[nx][ny] > cost[x][y] + 1) {
            cost[nx][ny] = cost[x][y] + 1;
            q.push({nx, ny});
          }
        }
      }
    }
  }
  return cost;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, c;
    cin >> n >> m >> c;
    vector<string> g(n);
    int sx, sy, fx, fy;
    for (int i = 0; i < n; i++) {
      cin >> g[i];
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 'S') {
          sx = i; sy = j;
        }
        if (g[i][j] == 'F') {
          fx = i; fy = j;
        }
      }
    }
    vector<vector<int>> cost = bfs(sx, sy, g);
    cout << (cost[fx][fy] <= c ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i == sx && j == sy) || (i == fx && j == fy)) {
          cout << g[i][j];
        } else {
          cout << (cost[i][j] <= cost[fx][fy] ? "." : "#");  
        }
      }
      cout << '\n';
    }
  }
  return 0;
}