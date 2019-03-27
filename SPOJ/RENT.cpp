#include <bits/stdc++.h>
 
using namespace std; 
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<tuple<int, int, int>> s(n);
    for (int i = 0; i < n; i++) {
      int st, d, p;
      scanf("%d %d %d", &st, &d, &p);
      s[i] = make_tuple(st, d, p);
    }
    sort(s.begin(), s.end());
    int f[n + 1];
    f[n] = 0;
    f[n - 1] = get<2>(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      f[i] = f[i + 1];
      int v = get<0>(s[i]) + get<1>(s[i]);
      if (v <= get<0>(s[i + 1])) {
        f[i] = max(f[i], get<2>(s[i]) + f[i + 1]);
      } else {
        int low = 0;
        int high = n;
        while (low < high) {
          int mid = low + ((high - low) / 2);
          if (v <= get<0>(s[mid])) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        f[i] = max(f[i], get<2>(s[i]) + f[low]);
      }
    }
    printf("%d\n", f[0]);
  }
  return 0;
}