#include <bits/stdc++.h>
 
#define max(x, y) x > y ? x : y
 
using namespace std;
 
int main() {
  int t;
  scanf("%d %", &t);
  
  while (t--) {
    int h, w, ans = 0;
    scanf("%d %d", &h, &w);
    int dp[h][w];
    
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &dp[i][j]);
      }
    }
    
    for (int i = 1; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int temp = dp[i][j];
        dp[i][j] += dp[i - 1][j];
        if (j > 0) dp[i][j] = max(dp[i][j], temp + dp[i - 1][j - 1]);
        if (j < w - 1) dp[i][j] = max(dp[i][j], temp + dp[i - 1][j + 1]);
      }
    }
 
    for (int j = 0; j < w; j++) {
      ans = max(ans, dp[h - 1][j]);
    }
    printf("%d\n", ans);
  }
  return 0;
} 
