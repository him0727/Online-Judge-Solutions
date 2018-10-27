#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> r(5, 0);
    for (int i = 0; i < n; i++) {
      int p;
      scanf("%d", &p);
      r[p]++;
    }
    int ans = 0;
    if (r[2] == r[1]) {
      ans = r[1];
    } else if (r[2] > r[1]) {
      r[2] -= r[1];
      r[3] += r[1] + 2 * (r[2] / 3);
      ans += r[1] + 2 * (r[2] / 3);
      r[2] %= 3;
      if (r[2] == 2) {
        ans += 2;
      }
      if (r[2] == 1) {
        int remain = r[4] ? 1 : r[3] > 1 ? 2 : -1;
        ans = remain >= 0 ? ans + remain : -1;
      }
    } else {
      r[1] -= r[2];
      r[3] += r[2] + r[1] / 3;
      ans += r[2] + 2 * (r[1] / 3);
      r[1] %= 3;
      if (r[1] == 2) {
        int remain = r[4] || r[3] > 1 ? 2 : -1;
        ans = remain >= 0 ? ans + remain : -1;
      }
      if (r[1] == 1) {
        int remain = r[3] ? 1 : r[4] > 1 ? 2 : -1;
        ans = remain >= 0 ? ans + remain : -1;
      }
    }
    if (ans >= 0) {
      printf("%d\n", ans);
    } else {
      printf("Tresi gagal memuaskan gadisnya.\n");
    }
  }
  return 0;
}