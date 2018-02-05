#include <bits/stdc++.h>
 
using namespace std;
 
double dp[600][3595];
 
int main() {
  for (int i = 0; i < 600; i++) {
    dp[i][0] = 0;
    dp[1][i] = 0;
  }
  for (int i = 600; i < 3595; i++) {
    dp[1][i] = 0;
  }
  for (int i = 1; i <= 6; i++) {
    dp[1][i] = 1.0 / 6.0; 
  }
  for (int i = 2; i < 600; i++) {
    dp[i][1] = 0;
    for (int j = 2; j < 3595; j++) {
      dp[i][j] = 0;
      dp[i][j] += dp[i][j - 1] * 6.0 + dp[i - 1][j - 1];
      if (j > 6) {
        dp[i][j] -= dp[i - 1][j - 7];
      }
      dp[i][j] /= 6.0;
    }
  }
  int t, n, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    if (n < 600 && k < 3595) {
      printf("%d\n", (int) (dp[n][k] * 100));
    } else {
      printf("0\n");
    }
  }
  return 0;
}