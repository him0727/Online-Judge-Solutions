#include <bits/stdc++.h>
 
using namespace std;
 
char maze[110][110];
bool visited[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k, sx, sy, max_dist;
 
void dfs(int x, int y, int dist) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
      if (!visited[nx][ny] && maze[nx][ny] != '*') {
        dfs(nx, ny, dist + 1);
      }
      if (nx == sx && ny == sy) {
        max_dist = max(max_dist, dist + 1);
        if (max_dist >= k) {
          return;
        }
      }
    }
  }
  visited[x][y] = false;
}
 
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d", &k);
  scanf("%d %d", &sx, &sy);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &maze[i][j]);
      visited[i][j] = false;
    }
  }
  max_dist = 0;
  --sx, --sy;
  dfs(sx, sy, 0);
  if (max_dist >= k) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}