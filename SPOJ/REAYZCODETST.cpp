#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      mp[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int now = mp[a[i] - x] - (x == 0);
      ans += max(0, now);
    }
    printf("Case %d: %lld\n", qq, ans);
  }
  return 0;
}