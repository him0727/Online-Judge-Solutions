#include <bits/stdc++.h>

using namespace std;

int main() {
  const int inf = 10010;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s;
    cin >> s;
    vector<int> sl, tp;
    vector<vector<int>> sp;
    int len = 0;
    for (auto c : s) {
      len++;
      if (c == '*') {
        sl.push_back(len);
        len = 1;
        sp.push_back(tp);
        tp.clear();
      }
      if (c == '@') {
        tp.push_back(len - 1);
      }
    }
    int ans = 0;
    for (int cs = 0; cs < sl.size(); cs++) {
      int slen = sl[cs];
      int plen = sp[cs].size();
      if (plen == 0) {
        ans += slen - 1;
        continue;
      }
      vector<int> f(slen, inf);
      f[sp[cs][0]] = sp[cs][0];
      int cp = 0;
      while (cp < plen) {
        int p = sp[cs][cp];
        int np = cp < plen - 1 ? sp[cs][cp + 1] : slen;
        np--;
        f[np] = f[p] + np - p;
        for (int i = 1; i <= 3 && cp + i < plen; i++) {
          np = sp[cs][cp + i];
          f[np] = min(f[np], min(f[p] + 3, f[np - 1] + 1));
        }
        cp++;
      }
      ans += f[slen - 1];
    }
    printf("%d\n", ans);
  }
  return 0;
}