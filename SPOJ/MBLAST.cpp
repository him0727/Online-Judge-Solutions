#include <bits/stdc++.h>
 
using namespace std;
 
int dp[2001][2001];
 
int main() {
  string a, b;
  int k;
  cin >> a;
  cin >> b;
  int as = a.size(), bs = b.size();
  scanf("%d", &k);
  for (int i = 0; i <= as; i++) {
    dp[i][0] = i * k;
  }
  for (int i = 0; i <= bs; i++) {
    dp[0][i] = i * k;
  }
  for (int i = 1; i <= as; i++) {
    for (int j = 1; j <= bs; j++) {
      dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + k);
    }
  }
  printf("%d\n", dp[as][bs]);
  return 0;
}