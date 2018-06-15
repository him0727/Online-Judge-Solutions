#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  cin.ignore();
  while (tt--) {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int ssz = s.size();
    int tsz = t.size();
    if (ssz == 0 || tsz == 0) {
      printf("0\n");
      continue;
    }
    int p = 0, ts = 0;
    for (int i = 0; i < ssz; i++) {
      if (t[p] != s[i]) {
        continue;
      }
      if (++p == tsz) {
        p = 0;
        ts++;
      }
    }
    printf("%d\n", ssz - ts * tsz);
  }
  return 0;
}