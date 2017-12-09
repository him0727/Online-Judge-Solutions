#include <bits/stdc++.h>
 
using namespace std;
 
int t, r, c, x, y, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string graph[101];
bool visited[101][101];
int ans[10001];
 
struct pos {
  int y, x;
  int dist;
};
 
void bfs() {
  int next_i, next_j, dist= 0;
  pos current, next = pos{y, x, dist};
  queue<pos> q;
  visited[y][x] = true;
  q.push(next);
  while (!q.empty()) {
    current = q.front();
    q.pop();
    if (graph[current.y][current.x] == 'S') ans[n++] = current.dist;
    for (int i = 0; i < 4; i++) {
      next_i = current.y + dy[i];
      next_j = current.x + dx[i];
      if (next_i >= 0 && next_i < r && next_j >= 0 && next_j < c) {
        if (graph[next_i][next_j] != '#' && !visited[next_i][next_j]) {
          visited[next_i][next_j] = true;
          next = pos{next_i, next_j, current.dist + 1};
          q.push(next);
        }
      }
    }
  }
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    int res = 0, max_dist = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      cin >> graph[i];
      for (int j = 0; j < c; j++) {
        visited[i][j] = false;
        if (graph[i][j] == 'C') {
          y = i, x = j;
        }
      }
    }
    n = 0;
    bfs();
    for (int i = 0; i < n; i++) {
      res += ans[i] * 2 + 60;
      max_dist = max(max_dist, ans[i]);
    }
    printf("%d\n", res - max_dist);
  }
  return 0;
}