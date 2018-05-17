#include <bits/stdc++.h>
 
using namespace std;
 
int a[9010];
 
int main() {
  while (1) {
    int n, sum = 0;
    scanf("%d", &n);
    if (n == -1) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    if (sum % n != 0) {
      printf("-1\n");
      continue;
    }
    int unit = sum / n;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int diff = a[i] - unit;
      a[i + 1] += diff;
      ans = max(ans, abs(diff));
    }
    printf("%d\n", ans);
  }
  return 0;
}