#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, ans = -1;
string grid[501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[501][501];
 
struct Step {
  int x, y;
  int st;
};
 
void bfs() {
  int nx = 0, ny = 0, st = 0;
  Step current, next = Step {0, 0, 0};
  queue<Step> q;
  q.push(next);
  visited[0][0] = true;
  while (!q.empty()) {
    current = q.front();
    q.pop();
    if (current.x == n - 1 && current.y == m - 1) {
      ans = current.st;
      return;
    }
    for (int i = 0; i < 4; i++) {
      nx = current.x + dx[i] * (grid[current.x][current.y] - '0');
      ny = current.y + dy[i] * (grid[current.x][current.y] - '0');
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (!visited[nx][ny]) {
          visited[nx][ny] = true;
          next = Step {nx, ny, current.st + 1};
          q.push(next);
        }
      }
    }
  }
}
 
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  bfs();
  printf("%d\n", ans); 
  return 0;
}