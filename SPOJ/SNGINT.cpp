#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> dgs;
    if (n <= 9) {
      if (n == 0) {
        n = 10;
      }
      printf("%d\n", n);
      continue;
    }
    bool ok = true;
    while (n > 1) {
      bool div = false;
      for (int i = 9; i >= 2; i--) {
        if (n % i == 0) {
          dgs.push_back(i);
          n /= i;
          div = true;
          break;
        }
      }
      if (!div) {
        ok = false;
        break;
      }
    }
    sort(dgs.begin(), dgs.end());
    if (!ok) {
      printf("-1\n");
    } else {
      for (int i = 0; i < dgs.size(); i++) {
        printf("%d", dgs[i]);
      }
      printf("\n");
    }
  }
  return 0;
}