#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    bool ok = true;
    if (k <= 0) {
      ok = false;
    }
    if (a < b) {
      ok = false;
    }
    if (b + k != a) {
      ok = false;
    }
    printf("Case %d: ", qq);
    if (ok) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}