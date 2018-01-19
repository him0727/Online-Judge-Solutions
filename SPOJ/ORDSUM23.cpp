#include <bits/stdc++.h>
#define MOD 1000000007
 
using namespace std;
 
int dp[1000001];
 
int main() {
  dp[2] = dp[3] = dp[4] = 1;
  for (int i = 5; i <= 1000000; i++) {
    dp[i] = (dp[i - 2] + dp[i - 3]) % MOD;
  }
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", dp[n]);
  }
  return 0;
}