#include <bits/stdc++.h>
 
using namespace std;
 
int s[5000], dp[5000];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    dp[i] = 1;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (abs(s[i]) > abs(s[j]) && ((s[i] > 0 && s[j] < 0) || (s[i] < 0 && s[j] > 0)) && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        ans = max(ans, dp[i]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}