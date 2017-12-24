#include <bits/stdc++.h>
 
using namespace std;
 
int t, r, c;
bool match = false;
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
string w = "ALLIZZWELL";
int len = w.size();
string graph[101];
bool visited[101][101];
 
void dfs(int x, int y, int p) {
  if (visited[x][y]) return;
  visited[x][y] = true;
  for (int i = 0; i < 8; i++) {
    int new_x = x + dx[i], new_y = y + dy[i];
    if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c) {
      if (!visited[new_x][new_y] && p + 1 < len && graph[new_x][new_y] == w[p + 1]) {
        if (p + 1 == len - 1) {
          match = true;
          return;
        }
        dfs(new_x, new_y, p + 1);
      }
    }
  }
  visited[x][y] = false;
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      cin >> graph[i];
      for (int j = 0; j < c; j++) {
        visited[i][j] = false;
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        match = false;
        if (graph[i][j] == 'A') {
          dfs(i, j, 0);
          if (match) {
            printf("YES\n");
            break;
          }
        }
      }
      if (match) break;
    }
    if (!match) printf("NO\n");
  }
  return 0;
}