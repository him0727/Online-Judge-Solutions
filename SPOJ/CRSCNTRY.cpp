#include <bits/stdc++.h>
 
using namespace std;
 
int dp[2001][2001];
 
int main() {
  for (int i = 0; i < 2001; i++) {
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  int t;
  vector<vector<int>> routes;
  vector<int> route;
  scanf("%d", &t);
  while (t--) {
    routes.clear();
    while (1) {
      int col = 0;
      int stop;
      while (1) {
        scanf("%d", &stop);
        if (stop == 0) {
          break;
        }
        route.push_back(stop);
        col++;
      }
      if (col == 0)  {
        break;
      }
      routes.push_back(route);
      route.clear();
    }
    int row = 1, ans = 0;
    while (row < routes.size()) {
      for (int i = 1; i <= routes[0].size(); i++) {
        for (int j = 1; j <= routes[row].size(); j++) {
          if (routes[0][i - 1] == routes[row][j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          } else {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
          }
        }
      }
      ans = max(ans, dp[routes[0].size()][routes[row].size()]);
      row++;
    }
    printf("%d\n", ans);
  }
  return 0;
}