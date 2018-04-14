#include <bits/stdc++.h>
 
using namespace std;
 
int energy[1010], reshape[1010], dp[1000010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int total, n;
    scanf("%d %d", &total, &n);
    fill(dp, dp + total + 1, 0);
    for (int i = 0; i < n; i++) {
      scanf("%d", &energy[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &reshape[i]);
    }
    for (int i = 1; i <= total; i++) {
      dp[i] = dp[i - 1];
      for (int j = 0; j < n; j++) {
        if (i >= energy[j]) {
          dp[i] = max(dp[i], dp[i - energy[j]] + reshape[j]);
        }
      }
    }
    printf("%d\n", dp[total]);
  }
  return 0;
}