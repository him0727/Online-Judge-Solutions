#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  int a[60];
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans;
    {
      int i = 1, j = n - 2;
      int lv = a[0], rv = a[n - 1];
      ans = rv - lv;
      while (i <= j) {
        int tmp = -1, op;
        if (abs(lv - a[i]) > tmp) {
          tmp = abs(lv - a[i]);
          op = 0;
        }
        if (abs(lv - a[j]) > tmp) {
          tmp = abs(lv - a[j]);
          op = 1;
        }
        if (abs(rv - a[i]) > tmp) {
          tmp = abs(rv - a[i]);
          op = 2;
        }
        if (abs(rv - a[j]) > tmp) {
          tmp = abs(rv - a[j]);
          op = 3;
        }
        if (op == 0) {
          lv = a[i++];
        }
        if (op == 1) {
          lv = a[j--];
        }
        if (op == 2) {
          rv = a[i++];
        }
        if (op == 3) {
          rv = a[j--];
        }
        ans += tmp;
      }
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}