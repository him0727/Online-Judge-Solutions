#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
int image[251][251];
bool visited[251][251];
 
int dfs(int i, int j) {
  if (visited[i][j] || image[i][j] != 1 || i >= n || j >= m) return 0;
  visited[i][j] = true;
  int up = 0, right = 0, bottom = 0, left = 0;
  if (i > 0) up += dfs(i - 1, j);
  if (i < n - 1) bottom += dfs(i + 1, j);
  if (j > 0) left += dfs(i, j - 1);
  if (j < m - 1) right += dfs(i, j + 1);
  return 1 + up + right + bottom + left;
}
 
int main() {
  while (1) {
    scanf("%d %d", &n, &m);
    if (!n && !m) break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &image[i][j]);
        visited[i][j] = false;
      }
    }
    int n_ans = 0;
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && image[i][j] == 1) {
          ans[dfs(i, j)] += 1;
          n_ans++;
        }
      }
    }
    printf("%d\n", n_ans);
    for (const auto& res : ans) {
      printf("%d %d\n", res.first, res.second);
    }
  }
  return 0;
}