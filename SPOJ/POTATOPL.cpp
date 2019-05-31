#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &r[i]);
    }
    sort(r.begin(), r.end());
    int li = 0, ri = n - 1;
    int lv = 0, rv = k + 1;
    int idx = 0;
    int remain = n;
    long long ans = 0LL;
    while (remain > 0) {
      if (remain == 1) {
        ans += k - r[li] < lv ? k - lv : r[li];
        ans += r[li] > rv ? rv : r[li];
      } else if (remain == 2) {
        if (idx % 2 == 0) {
          ans += (k - r[ri] < lv ? k - lv : r[ri]) + r[ri];
          ans += (r[ri - 1] > rv ? rv : r[ri - 1]) + (k - r[ri - 1] < r[ri] ? k - r[ri] : r[ri - 1]);
        } else {
          ans += (k - r[li] < lv ? k - lv : r[li]) + r[li];
          ans += (r[li + 1] > rv ? rv : r[li + 1]) + (k - r[li + 1] < r[li] ? k - r[li] : r[li + 1]);
        }
      } else if (idx % 2 == 0) {
        ans += (k - r[ri] < lv ? k - lv : r[ri]) + r[ri];
        ans += (r[ri - 1] > rv ? rv : r[ri - 1]) + r[ri - 1];
        lv = r[ri];
        rv = k - r[ri - 1];
        ri -= 2;
      } else {
        ans += (k - r[li] < lv ? k - lv : r[li]) + r[li];
        ans += (r[li + 1] > rv ? rv : r[li + 1]) + r[li + 1];
        lv = r[li];
        rv = k - r[li + 1];
        li += 2;
      }
      remain -= 2;
      idx++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}