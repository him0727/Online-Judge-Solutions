#include <bits/stdc++.h>
 
using namespace std;
 
int cost[26], dp[2001][2001];
 
int main() {
  int n, m;
  string s1, s2;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 26; i++) {
    scanf("%d", &cost[i]);
  }
  cin >> s1;
  cin >> s2;
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1] + cost[s1[i - 1] - 'a'];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  printf("%d\n", dp[s1.size()][s2.size()]);
  return 0;
}