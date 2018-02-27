#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
int t[1000001];
 
int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + n);
  int s = 0, e = t[n - 1];
  int mid;
  int ans = 0;
  while (s <= e) {
    mid = (s + ((e - s) >> 1));
    ll m = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (t[i] <= mid) {
        break;
      }
      m += t[i] - mid;
    }
    if (m > h) {
      s = mid + 1;
      ans = mid;
    } else if (m < h) {
      e = mid - 1;
    } else {
      ans = mid;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}