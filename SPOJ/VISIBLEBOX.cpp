#include <bits/stdc++.h>
 
using namespace std;
 
int a[100010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    sort(a, a + n);
    int outer = n - 1, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[outer] >= 2 * a[i]) {
        outer--;
      } else {
        ans++;
      }
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}