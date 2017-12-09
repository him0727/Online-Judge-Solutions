#include <bits/stdc++.h>
 
using namespace std;
 
int t, m, n, e;
bool valid = false;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string maze[21];
bool visited[21][21];
pair<int, int> exits[3];
 
void bfs() {
  int next_i, next_j;
  pair<int, int> current, next = make_pair(exits[0].first, exits[0].second);
  queue<pair<int, int>> q;
  visited[exits[0].first][exits[0].second] = true;
  q.push(next);
  while (!q.empty()) {
    current = q.front();
    q.pop();
    if (current.first == exits[1].first && current.second == exits[1].second) {
      valid = true;
      return;
    }
    for (int i = 0; i < 4; i++) {
      next_i = current.first + dy[i];
      next_j = current.second + dx[i];
      if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n) {
        if (maze[next_i][next_j] != '#' && !visited[next_i][next_j]) {
          visited[next_i][next_j] = true;
          next = make_pair(next_i, next_j);
          q.push(next);
        }
      }
    }
  }
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    valid = false;
    e = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
      cin >> maze[i];
      for (int j = 0; j < n; j++) {
        visited[i][j] = false;
        if (!i || !j || i == m - 1 || j == n - 1) {
          if (maze[i][j] == '.') {
            exits[e++ % 3] = make_pair(i, j);
          }
        }
      }
    }
    if (e != 2) {
      printf("invalid\n");
      continue;
    }
    bfs();
    if (valid) printf("valid\n");
    else printf("invalid\n");
  }
  return 0;
}