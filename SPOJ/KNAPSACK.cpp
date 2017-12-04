#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 2007;
int s, n;
int w[SIZE], v[SIZE], dp[SIZE];
 
int main() {
  scanf("%d %d", &s, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }
  for (int i = 0; i <= s; i++) {
    dp[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = s; j - w[i] >= 0; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  printf("%d\n", dp[s]);
  return 0;
}