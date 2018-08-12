#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int a[25];
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    long long ans = 0;
    int bound = (1 << n);
    for (int mask = 0; mask < bound; mask++) {
      long long tmp = 0;
      for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) {
          tmp += a[j];
        }
      }
      if (tmp <= m) {
        ans = max(ans, tmp);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}