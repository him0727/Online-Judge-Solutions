#include <bits/stdc++.h>
 
using namespace std;
 
int h[10010];
int f[10010][10010];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", h + i + 1);
    f[i][0] = f[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    for (int j = i; j <= n; j++) {
      f[i][j] = max(f[i - 1][j - 1], h[j]);
      ans += f[i][j];
    }
    printf("%lld\n", ans);
  }
  return 0;
}