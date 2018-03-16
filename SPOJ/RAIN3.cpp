#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
int s[1500001], t[1500001], a[1500001];
 
int main() {
  int T, N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &s[0], &t[0], &N, &M);
    a[0] = (s[0] % 100 + 1) * (t[0] % 100 + 1);
    for (int i = 1; i <= N; i++) {
      s[i] = (78901 + 31 * s[i - 1]) % 699037;
      t[i] = (23456 + 64 * t[i - 1]) % 2097151;
      a[i] = (s[i] % 100 + 1) * (t[i] % 100 + 1);
    }
    int s = 1, e = N, mid;
    int ans = 0;
    while (s <= e) {
      mid = s + ((e - s) >> 1);
      ll sum = 0;
      bool ok = true;
      for (int i = 1; i <= mid; i++) {
        sum += a[i];
        if (sum > M) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int i = mid + 1, j = 1; i < N; i++, j++) {
          sum -= a[j];
          sum += a[i];
          if (sum > M) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        s = mid + 1;
        ans = mid;
      } else {
        e = mid - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}