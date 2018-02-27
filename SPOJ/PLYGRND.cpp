#include <bits/stdc++.h>
 
using namespace std;
 
double a[21];
 
int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%lf", &a[i]);
    }
    if (n == 1) {
      printf("NO\n");
      continue;
    }
    sort(a, a + n);
    double sum = 0;
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      sum += a[i];
      if (sum >= a[i + 1]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}