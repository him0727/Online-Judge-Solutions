#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    string s;
    cin >> s;
    int sz = s.size();
    printf("Case %d: ", qq);
    if (s[0] == '0' || sz < 3) {
      printf("no\n");
      continue;
    }
    int zero = 0, one = 1;
    bool ok = true;
    for (int i = 1; i < sz; i++) {
      if (s[i] == '0') {
        zero++;
      } else {
        one++;
      }
      if (one >= 1 && zero >= 2) {
        one--;
        zero -= 2;
      }
      if (one == 0 && zero > 0) {
        ok = false;
        break;
      }
    }
    if (!(one == 0 && zero == 0)) {
      ok = false;
    }
    printf(ok ? "yes" : "no");
    printf("\n");
  }
  return 0;
}