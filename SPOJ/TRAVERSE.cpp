#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> f(n, vector<int>(n, 0));
  vector<vector<int>> m(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      m[i][j] = s[j] - '0';
    }
  }
  function<void(int, int)> calc = [&](int x, int y) {
    int nx = x + m[x][y];
    int ny = y + m[x][y];
    if (m[x][y] == 0) {
      return;
    }
    if (nx < n) {
      f[nx][y]++;
      calc(nx, y);
    }
    if (ny < n) {
      f[x][ny]++;
      calc(x, ny);
    }
  };
  calc(0, 0);
  printf("%d", f[n - 1][n - 1]);
  return 0;
}