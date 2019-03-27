#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
char dir[1010][1010];
bool visited[1010][1010];
 
void dfs(int x, int y) {
  visited[x][y] = true;
  if (x + 1 < n && !visited[x + 1][y]) {
    if (dir[x + 1][y] == 'N' || dir[x][y] == 'S') {
      dfs(x + 1, y);
    }
  }
  if (x - 1 >= 0 && !visited[x - 1][y]) {
    if (dir[x - 1][y] == 'S' || dir[x][y] == 'N') {
      dfs(x - 1, y);
    }
  }
  if (y + 1 < m && !visited[x][y + 1]) {
    if (dir[x][y + 1] == 'W' || dir[x][y] == 'E') {
      dfs(x, y + 1);
    }
  }
  if (y - 1 >= 0 && !visited[x][y - 1]) {
    if (dir[x][y - 1] == 'E' || dir[x][y] == 'W') {
      dfs(x, y - 1);
    }
  }
}
 
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", dir[i]);
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(i, j);
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}