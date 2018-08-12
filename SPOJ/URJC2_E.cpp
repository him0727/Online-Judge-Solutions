#include <bits/stdc++.h>
 
using namespace std;
 
long long p[110][50010];
 
int main() {
  for (int i = 0; i < 110; i++) {
    p[i][0] = 0LL;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int k, h, n;
    scanf("%d %d %d", &k, &h, &n);
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%lld", &p[i][j]);
        p[i][j] += p[i][j - 1];
      }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int s, e, cnt = 0;
      scanf("%d %d", &s, &e);
      for (int i = 1; i <= k; i++) {
        if (p[i][e] - p[i][s - 1] > h) {
          cnt++;
        }
      }
      printf("%d - %d\n", cnt, k - cnt);
    }
  }
  return 0;
}