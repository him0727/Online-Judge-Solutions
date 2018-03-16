#include <bits/stdc++.h>
 
using namespace std;
 
int w[100010];
 
int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &w[i]);
    }
    int buy = 0, sell = 0;
    long long ans = 0;
    while (1) {
      while (buy < n && w[buy] <= 0) {
        buy++;
      }
      while (sell < n && w[sell] >= 0) {
        sell++;
      }
      if (buy == n || sell == n) {
        break;
      }
      int gs = min(w[buy], w[sell] * -1);
      ans += gs * abs(buy - sell);
      w[buy] -= gs;
      w[sell] += gs;
    }
    printf("%lld\n", ans);
  }
  return 0;
}