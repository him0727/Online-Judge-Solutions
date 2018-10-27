#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  long long times[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", times + i);
  }
  sort(times, times + n);
  if (n <= 2) {
    printf("%lld\n", times[n - 1]);
  } else if (n == 3) {
    printf("%lld\n", times[0] + times[1] + times[2]);
  } else {
    long long ans = times[0] * ((n - 1) / 2);
    if (n & 1) {
      ans += times[1] * (n - 2);
      for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
          ans += times[i];
        }
      }
    } else {
      ans += times[1] * (n - 1);
      for (int i = 2; i < n; i++) {
        if (i % 2 != 0) {
          ans += times[i];
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}