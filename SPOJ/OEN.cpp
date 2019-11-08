#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int ans[19];
  for (int n = 0; n < 19; n++) {
    bool found = false;
    for (int sub = 0; sub < 10; sub++) {
      int b = sub;
      int c = n - sub;
      if (c < 0 || c > 9) {
        continue;
      }
      for (int a = 1; a < 10; a++) {
        int m = a * 100 + b * 10 + c;
        for (int t = 0; t <= 30; t++) {
          int p = m + t;
          int s = 0;
          while (p != 0) {
            s = s + p % 10;
            p = p / 10;
          }
          if (s == t) {
            ans[n] = m / 100;
            found = true;
          }
          if (found) break;
        }
        if (found) break;
      }
      if (found) break;
    }
  }
  ans[18] = 0;
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", qq, ans[n]);
  }
  return 0;
}