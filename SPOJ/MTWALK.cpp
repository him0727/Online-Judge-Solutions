#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int m[110][110];
int min_e = 110;
int max_e = 0;
 
bool bfs(int mi, int ma) {
  vector<vector<bool>> v(n, vector<bool>(n, false));
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int, int>> q;
  q.push({0, 0});
  v[0][0] = true;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    if (cur.first == n - 1 && cur.second == n - 1) {
      return true;
    }
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
        continue;
      }
      if (v[nx][ny] || m[nx][ny] < mi || m[nx][ny] > ma) {
        continue;
      }
      v[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return false;
}
 
bool solve(int mid) {
  for (int i = max(m[0][0] - mid, min_e); i <= m[0][0]; i++) {
    if (i + mid >= m[n - 1][n - 1] && bfs(i, i + mid)) {
      return true;
    }
  }
  return false;
}
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
      min_e = min(min_e, m[i][j]);
      max_e = max(max_e, m[i][j]);
    }
  }
  int low = abs(m[0][0] - m[n - 1][n - 1]);
  int high = max_e - min_e;
  while (low < high) {
    int mid = (low + high) / 2;
    if (solve(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", high);
  return 0;
}