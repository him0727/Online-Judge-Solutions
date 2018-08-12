#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  const int N = 100010;
  pair<int, int> a[N];
  long long pa[N];
  pa[0] = 0LL;
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int d;
      scanf("%d", &d);
      a[i] = {d, i};
    }
    sort(a, a + n);
    for (int i = 1; i <= n; i++) {
      pa[i] = a[i - 1].first + pa[i - 1];
    }
    int ans;
    long long far = 1e16;
    for (int i = 0; i < n; i++) {
      long long cur = (long long)i * a[i].first - pa[i] + pa[n] - pa[i + 1] - (long long)(n - i - 1) * a[i].first;
      if (cur == far) {
        ans = min(ans, a[i].second + 1);
      }
      if (cur < far) {
        far = cur;
        ans = a[i].second + 1;
      }
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}