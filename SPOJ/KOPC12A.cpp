#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int h[n], c[n];
    int l = 11000, r = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", h + i);
      l = min(l, h[i]);
      r = max(r, h[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    long long ans = 10000LL * 10000 * 10000;
    while (l <= r) {
      int mid = (l + r) / 2;
      long long ll = 11000, mm = 0, rr = 0;
      if (mid > 0) {
        ll = 0LL;
        for (int i = 0; i < n; i++) {
          ll += (long long) (abs(mid - 1 - h[i])) * c[i];
        }
      }
      for (int i = 0; i < n; i++) {
        mm += (long long) (abs(mid - h[i])) * c[i];
      }
      for (int i = 0; i < n; i++) {
        rr += (long long) (abs(mid + 1 - h[i])) * c[i];
      }
      ans = min(ans, mm);
      if (ll <= mm) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int h[n], c[n];
    int l = 11000, r = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", h + i);
      l = min(l, h[i]);
      r = max(r, h[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    long long ans = 10000LL * 10000 * 10000;
    while (l <= r) {
      int mid = (l + r) / 2;
      long long ll = 11000, mm = 0, rr = 0;
      if (mid > 0) {
        ll = 0LL;
        for (int i = 0; i < n; i++) {
          ll += (long long) (abs(mid - 1 - h[i])) * c[i];
        }
      }
      for (int i = 0; i < n; i++) {
        mm += (long long) (abs(mid - h[i])) * c[i];
      }
      for (int i = 0; i < n; i++) {
        rr += (long long) (abs(mid + 1 - h[i])) * c[i];
      }
      ans = min(ans, mm);
      if (ll <= mm) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}