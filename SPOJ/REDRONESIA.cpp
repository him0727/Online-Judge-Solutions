#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1000000007;
const int MAX = 501;
 
int dp[MAX + 10][MAX + 10];
 
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
 
int main() {
  for (int i = 0; i <= MAX; i++) {
    dp[0][i] = 1;
    dp[1][i] = i;
    if (i > 0) {
      dp[i][0] = 0;
    }
  }
  for (int i = 2; i <= MAX; i++) {
    for (int j = 1; j <= MAX; j++) {
      dp[i][j] = dp[i][j - 1];
      add(dp[i][j], dp[i - 1][j - 1]);
      add(dp[i][j], dp[i - 2][j - 1]);
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int s, c;
    scanf("%d %d", &s, &c);
    printf("%d\n", dp[s][c]);
  }
  return 0;
}