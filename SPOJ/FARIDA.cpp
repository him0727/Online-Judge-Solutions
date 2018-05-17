#include <bits/stdc++.h>
 
using namespace std;
 
int m[10010];
long long f[10010];
 
int main() {
  f[0] = 0LL;
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", m + i);
    }
    f[1] = m[1];
    for (int i = 2; i <= n; i++) {
      f[i] = max(m[i] + f[i - 2], f[i - 1]);
    }
    printf("Case %d: %lld\n", qq, f[n]);
  }
  return 0;
}