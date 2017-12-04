#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 2007;
int b, n;
int dp[SIZE];
pair<int, int> parties[SIZE];
 
int main() {
  while (1) {
    scanf("%d %d", &b, &n);
    if (!b && !n) break;
    int cost, fun;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &cost, &fun);
      parties[i] = make_pair(cost, fun);
    }
    for (int i = 0; i <= b; i++) {
      dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = b; j - parties[i].first >= 0; j--) {
        if (dp[j] < dp[j - parties[i].first] + parties[i].second) {
          dp[j] = dp[j - parties[i].first] + parties[i].second;
        }
      }
    }
    int min_c = 0;
    for (int i = b; i >= 0; i--) {
      if (dp[i] < dp[b]) {
        min_c = i + 1;
        break;
      }
    }
    printf("%d %d\n", min_c, dp[b]);
  }
  return 0;
}