#include <bits/stdc++.h>
#define MAX 100001
typedef long long int ll;
 
using namespace std;
 
int n, m, o, x, y;
ll a[MAX], b[MAX], root[MAX];
 
int find(int i) {
  if (root[i] != i) root[i] = find(root[i]);
  return root[i];
}
 
int main() {
  int id = 1;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      a[i] = 0;
      root[i] = i;
    }
    root[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &b[i]);
      for (int j = i; j <= n; j += j & (-j)) {
        a[j] += b[i];
      }
    }
    scanf("%d", &m);
    printf("Case #%d:\n", id++);
    while (m--) {
      scanf("%d %d %d", &o, &x, &y);
      if (x > y) swap(x, y);
      if (o) {
        ll sum = 0;
        for (int i = y; i > 0; i -= i & (-i)) {
          sum += a[i];
        }
        for (int i = x - 1; i > 0; i -= i & (-i)) {
          sum -= a[i];
        }
        printf("%lld\n", sum);
      } else {
        int j = find(x);
        for (int i = j; i <= y; i = find(i + 1)) {
          if (b[i] != 1) {
            ll val = sqrt(b[i]);
            for (int k = i; k <= n; k += k & (-k)) {
              a[k] -= b[i];
              a[k] += val;
            }
            if (val == 1) root[i] = i + 1;
            b[i] = val;
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}