#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 210;
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char graph[MAX][MAX];
int cost[MAX][MAX];
int n, m;

void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  cost[sx][sy] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    int cur_x = cur.first, cur_y = cur.second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur_x + dx[i], ny = cur_y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (graph[cur_x][cur_y] == '.' && graph[nx][ny] == '.' && (cost[nx][ny] == -1 || cost[nx][ny] > cost[cur_x][cur_y])) {
          cost[nx][ny] = cost[cur_x][cur_y];
          q.push({nx, ny});
        }
        if ((graph[cur_x][cur_y] != '.' || graph[nx][ny] != '.') && (cost[nx][ny] == -1 || cost[nx][ny] > cost[cur_x][cur_y] + 1)) {
          cost[nx][ny] = cost[cur_x][cur_y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int sx, sy, fx, fy, mcost;
    scanf("%d %d %d", &n, &m, &mcost);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf(" %c", &graph[i][j]);
        cost[i][j] = -1;
        if (graph[i][j] == 'S') {
          sx = i, sy = j;
        }
        if (graph[i][j] == 'F') {
          fx = i, fy = j;
        }
      }
    }
    bfs(sx, sy);
    if (cost[fx][fy] <= mcost) {
      printf("POSSIBLE\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == sx && j == sy || i == fx && j == fy) {
          printf("%c", graph[i][j]);
        } else if (cost[i][j] <= cost[fx][fy]) {
          printf(".");
        } else {
          printf("#");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}