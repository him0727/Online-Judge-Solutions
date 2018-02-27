#include <bits/stdc++.h>
 
using namespace std;
 
int wds[2001];
 
int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &wds[i]);
    }
    sort(wds, wds + n);
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        int v = wds[i] + wds[j] + 1;
        int bound = lower_bound(wds, wds + n, v) - wds;
        ans += n - bound;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}