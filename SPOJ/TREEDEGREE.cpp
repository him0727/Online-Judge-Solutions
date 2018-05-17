#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 100010;
 
int p[MAX], d[MAX];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    fill(d, d + n + 1, 0);
    fill(p, p + n + 1, 0);
    int v, cur = 1;
    for (int i = 1; i <= n * 2; i++) {
      scanf("%d", &v);
      if (p[v] == 0) {
        p[v] = cur;
        cur = v;
      } else {
        cur = p[v];
      }
    }
    for (int i = 1; i <= n; i++) {
      d[p[i]]++;
    }
    d[1] -= 2;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, d[i] + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}