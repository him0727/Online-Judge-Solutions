#include <bits/stdc++.h>
 
using namespace std;
 
int r, c, lx, ly, ux, uy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string graph[11];
int status[11][11];
 
void dfs(int x, int y) {
  if (status[x][y] != 0) return;
  status[x][y] = 1;
  int sea = 0;
  if (x == 0 || x == r - 1) sea++;
  if (y == 0 || y == c - 1) sea++;
  if (r == 1 || c == 1) sea++;
  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i], new_y = y + dy[i];
    if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c) {
      if (graph[new_x][new_y] == '.') sea++;
      if (status[new_x][new_y] == 0 && graph[new_x][new_y] == 'X') dfs(new_x, new_y);
    } else if (r == 1) {
      if (new_y >= 0 && new_y < c) {
        if (graph[0][new_y] == '.') sea++;
        if (status[0][new_y] == 0 && graph[0][new_y] == 'X') dfs(0, new_y);
      }
    } else if (c == 1) {
      if (new_x >= 0 && new_x < r) {
        if (graph[new_x][0] == '.') sea++;
        if (status[new_x][0] == 0 && graph[new_x][0] == 'X') dfs(new_x, 0);
      }
    }
  }
  if (sea >= 3) {
    status[x][y] = -1;
  } else {
    lx = min(lx, x), ly = min(ly, y);
    ux = max(ux, x), uy = max(uy, y);
  }
}
 
int main() {
  scanf("%d %d", &r, &c);
  lx = r, ly = c;
  ux = 0, uy = 0;
  for (int i = 0; i < r; i++) {
    cin >> graph[i];
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (status[i][j] == 0 && graph[i][j] == 'X') dfs(i, j);
    }
  }
  for (int i = lx; i <= ux; i++) {
    for (int j = ly; j <= uy; j++) {
      if (status[i][j] == 0 || status[i][j] == -1) printf(".");
      else printf("X");
    }
    printf("\n");
  }
  return 0;
}