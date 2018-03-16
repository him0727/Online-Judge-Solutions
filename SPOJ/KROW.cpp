#include <bits/stdc++.h>
 
using namespace std;
 
int m, n, k;
char g[201][201];
 
bool solve(int x, int y, char who) {
  int h = 0, v = 0, d1 = 0, d2 = 0;
  for (int i = x; i < n; i++) {
    if (g[i][y] != who) {
      break;
    }
    v++;
  }
  for (int i = y; i < m; i++) {
    if (g[x][i] != who) {
      break;
    }
    h++;
  }
  for (int i = x, j = y; i < n && j < m; i++, j++) {
    if (g[i][j] != who) {
      break;
    }
    d1++;
  }
  for (int i = x, j = y; i < n && j >= 0; i++, j--) {
    if (g[i][j] != who) {
      break;
    }
    d2++;
  }
  return max(max(h, v), max(d1, d2)) >= k;
}
 
int main() {
  int t;
  scanf("%d", &t);
  int han = 0, gre = 0;
  while (t--) {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf(" %c", &g[i][j]);
      }
    }
    bool find = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 'x' && solve(i, j, 'x')) {
          han++;
          find = true;
          break;
        }
        if (g[i][j] == 'o' && solve(i, j, 'o')) {
          gre++;
          find = true;
          break;
        }
      }
      if (find) {
        break;
      }
    }
  }
  printf("%d:%d\n", han, gre);
  return 0;
}