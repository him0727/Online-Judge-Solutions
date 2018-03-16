#include <bits/stdc++.h>
 
using namespace std;
 
string s1, s2, s3;
int dp[61][61][61];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> s1 >> s2 >> s3;
    int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
    for (int i = 0; i <= sz1; i++) {
      for (int j = 0; j <= sz2; j++) {
        dp[i][j][0] = 1;
        for (int k = 1; k <= sz3; k++) {
          dp[i][j][k] = 0;
          if (i + j >= k) {
            for (int l = i - 1; l >= 0; l--) {
              if (s1[l] == s3[k - 1]) {
                dp[i][j][k] += dp[l][j][k - 1];
              }
            }
            for (int l = j - 1; l >= 0; l--) {
              if (s2[l] == s3[k - 1]) {
                dp[i][j][k] += dp[i][l][k - 1];
              }
            }
          }
        }
      }
    }
    printf("%d\n", dp[sz1][sz2][sz3]);
  }
  return 0;
}