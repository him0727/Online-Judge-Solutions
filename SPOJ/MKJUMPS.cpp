#include <bits/stdc++.h>
 
using namespace std;
 
bool b[11][11];
int dx[] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[] = {-1, -2, 1, 2, -2, -1, 2, 1};
int n, ans;
 
void solve(int x, int y, int cell) {
  b[x][y] = false;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) {
      continue;
    }
    if (!b[nx][ny]) {
      continue;
    }
    solve(nx, ny, cell + 1);
  }
  ans = max(ans, cell);
  b[x][y] = true;
}
 
int main() {
  int tt = 1;
  while (1) {
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        b[i][j] = false;
      }
    }
    int f, t;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &f, &t);
      for (int j = 0; j < t; j++) {
        b[i][j + f] = true;
        total++;
      }
    }
    ans = 0;
    solve(0, 0, 1);
    ans = total - ans;
    printf("Case %d, %d ", tt++, ans);
    printf(ans == 1 ? "square " : "squares ");
    printf("can not be reached.\n");
  }
  return 0;
}