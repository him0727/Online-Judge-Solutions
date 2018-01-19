#include <bits/stdc++.h>
 
using namespace std;
 
int dp[2001][2001];
 
int main() {
  for (int i = 0; i < 2001; i++) {
    dp[i][0] = i;
    dp[0][i] = i;
  }
  int t;
  string s1, s2;
  scanf("%d", &t);
  while (t--) {
    cin >> s1;
    cin >> s2;
    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
      }
    }
    printf("%d\n", dp[s1.size()][s2.size()]);
  }
  return 0;
}