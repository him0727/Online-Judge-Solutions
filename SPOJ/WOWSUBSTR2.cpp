#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 100007;
 
int s[1000010], r[1000010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", s + i);
    }
    fill(r, r + m + 1, 0);
    int last = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int k = last;
      for (int j = k; j < n; j++) {
        r[s[j]]++;
        if (r[s[j]] > 1) {
          r[s[j]]--;
          r[s[i]]--;
          break;
        }
        last++;
      }
      int tmp = last - i;
      ans = (ans + tmp * (tmp + 1) / 2) % MOD;
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}