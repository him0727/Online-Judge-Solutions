#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1010;
 
struct Node {
  int x, y, cost;
};
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char graph[MAX][MAX];
bool visited[MAX][MAX];
int cost1[MAX][MAX], cost2[MAX][MAX];
int n, m, ex, ey;
vector<pair<int, int>> bounds;
 
void bfs_point(int sx, int sy) {
  queue<Node> q;
  q.push(Node {sx, sy, 0});
  cost1[sx][sy] = 0;
  visited[sx][sy] = true;
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ni = cur.x + dx[i], nj = cur.y + dy[i];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj]) {
        if (graph[ni][nj] == '.' && ex == -1 && ey == -1) {
          ex = ni, ey = nj;
        }
        if (graph[ni][nj] != 'F') {
          q.push(Node {ni, nj, cur.cost + 1});
        }
        visited[ni][nj] = true;
        cost1[ni][nj] = cur.cost + 1;
      }
    }
  }
}
 
void bfs_polygon() {
  queue<Node> q;
  for (auto v : bounds) {
    q.push(Node {v.first, v.second, cost2[ex][ey]});
    visited[v.first][v.second] = true;
  }
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ni = cur.x + dx[i], nj = cur.y + dy[i];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && graph[ni][nj] != '.') {
        if (graph[ni][nj] != 'F') {
          q.push(Node {ni, nj, cur.cost + 1});
        }
        visited[ni][nj] = true;
        cost2[ni][nj] = cur.cost + 1;
      }
    }
  }
}
 
void dfs(int sx, int sy) {
  if (visited[sx][sy]) {
    return;
  }
  visited[sx][sy] = true;
  cost2[sx][sy] = cost1[ex][ey];
  int edge = 0;
  for (int i = 0; i < 4; i++) {
    int ni = sx + dx[i], nj = sy + dy[i];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
      if (graph[ni][nj] == '.') {
        dfs(ni, nj);
      } else {
        edge++;
      }
    }
  }
  if (edge > 0) {
    bounds.push_back({sx, sy});
  }
}
 
void reset() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int sx, sy, fx, fy, max_cost;
    scanf("%d %d %d", &n, &m, &max_cost);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf(" %c", &graph[i][j]);
        cost1[i][j] = -1;
        cost2[i][j] = -1;
        visited[i][j] = false;
        if (graph[i][j] == 'S') {
          sx = i, sy = j;
        }
        if (graph[i][j] == 'F') {
          fx = i, fy = j;
        }
      }
    }
    ex = -1, ey = -1;
    bfs_point(sx, sy);
    bounds.clear();
    if (ex != -1 && ey != -1) {
      reset();
      dfs(ex, ey);
      reset();
      bfs_polygon();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cost1[i][j] = min(cost1[i][j], cost2[i][j]);
        }
      }
    }
    if (cost1[fx][fy] <= max_cost) {
      printf("POSSIBLE\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == sx && j == sy || i == fx && j == fy) {
          printf("%c", graph[i][j]);
        } else if (cost1[i][j] <= cost1[fx][fy] && cost1[i][j] != -1) {
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