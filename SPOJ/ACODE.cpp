#include <bits/stdc++.h>
 
using namespace std;
 
int dp[5001];
 
int main() {
  dp[0] = 0;
  dp[1] = 1;
  string s;
  while (1) {
    cin >> s;
    if (s == "0") {
      break;
    }
    if (s.size() == 1) {
      printf("1\n");
      continue;
    }
    if (s[0] - '0' > 2 || s[1] == '0' || s[0] == '2' && s[1] - '0' > 6) {
      dp[2] = 1;
    } else {
      dp[2] = 2;
    }
    for (int i = 2; i < s.size(); i++) {
      if (s[i - 1] - '0' > 2 || s[i - 1] == '0' || s[i - 1] == '2' && s[i] - '0' > 6 ) {
        dp[i + 1] = dp[i] ;
      } else if (s[i] == '0') {
        dp[i + 1] = dp[i - 1];
      } else {
        dp[i + 1] = dp[i] + dp[i - 1];
      }
    }
    printf("%d\n", dp[s.size()]);
  }
  return 0;
}