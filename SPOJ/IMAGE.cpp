#include <bits/stdc++.h>
 
using namespace std;
 
int r, c, cr, cc;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
string image[21];
bool visited[21][21];
 
int dfs(int i, int j) {
  if (visited[i][j] || image[i][j] == '.') return 0;
  visited[i][j] = true;
  int p = 4;
  for (int k = 0; k < 4; k++) {
    int next_i = i + dy[k];
    int next_j = j + dx[k];
    if (next_i >= 0 && next_i < r && next_j >= 0 && next_j < c) {
      if (image[next_i][next_j] == 'X') {
        p--;
        if (!visited[next_i][next_j]) p += dfs(next_i, next_j);
      }
    }
  }
  for (int k = 4; k < 8; k++) {
    int next_i = i + dy[k];
    int next_j = j + dx[k];
    if (next_i >= 0 && next_i < r && next_j >= 0 && next_j < c) {
      if (image[next_i][next_j] == 'X' && !visited[next_i][next_j]) p += dfs(next_i, next_j);
    }
  }
  return p;
}
 
int main() {
  while (1) {
    scanf("%d %d %d %d", &r, &c, &cr, &cc);
    if (!r && !c && !cr && !cc) break;
    for (int i = 0; i < r; i++) {
      cin >> image[i];
      for (int j = 0; j < c; j++) {
        visited[i][j] = false;
      }
    }
    printf("%d\n", dfs(cr - 1, cc - 1));
  }
  return 0;
}