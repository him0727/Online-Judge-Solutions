#include <bits/stdc++.h>
 
using namespace std;
 
char s[201];
int z[201], dp[201];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, prev = 0;
    scanf("%d", &n);
    fill(z, z + n, 0);
    fill(dp, dp + n, 0);
    for (int i = 0; i < n; i++) {
      scanf(" %c", &s[i]);
      z[i] += prev;
      if (s[i] == '1') {
        z[i]++;
      }
      prev = z[i];
    }
    dp[0] = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < n; i++) {
      if ((z[i] << 1) > i + 1) {
        dp[i] = i + 1;
      } else {
        if (s[i] == '0') {
          dp[i] = dp[i - 1];
        } else {
          for (int j = 1; j <= i; j++) {
            if (((z[i] - z[j - 1]) << 1) > i - j + 1) {
              dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
            }
          }
        }
      }
    }
    printf("%d\n", dp[n - 1]);
  }
  return 0;
}