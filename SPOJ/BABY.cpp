#include <bits/stdc++.h>
 
using namespace std;
 
int n, lim;
int f[(1 << 17)];
int inv[17], v[17];
 
int solve(int mask, int index) {
  if (mask == lim) {
    return 0;
  }
  if (f[mask] != -1) {
    return f[mask];
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) {
      ans = min(ans, abs(index - i) + abs(inv[index] - v[i]) + solve((mask | (1 << i)), index + 1));
    }
  }
  return f[mask] = ans;
}
 
int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", inv + i);
      inv[i]--;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", v + i);
      v[i]--;
    }
    lim = (1 << n) - 1;
    fill(f, f + lim, -1);
    printf("%d\n", solve(0, 0));
  }
  return 0;
}