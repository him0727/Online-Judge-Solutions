#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int a[100010];
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    long long ans = 0LL;
    scanf("%d", &n);
    vector<int> bit(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      int sum = 0;
      for (int j = a[i]; j > 0; j -= j & (-j)) {
        sum += bit[j];
      }
      ans += i - sum - 1;
      for (int j = a[i]; j <= n; j += j & (-j)) {
        bit[j]++;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}