#include <bits/stdc++.h>
 
using namespace std;
 
int toilets[510];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    long long m, ans, pfx = 0, ppfx = 0;
    bool ok = false;
    string s;
    scanf("%d %lld", &n, &m);
    cin >> s;
    for (int i = 0; i < n; i++) {
      scanf("%d", &toilets[i]);
      pfx += toilets[i];
      ppfx += pfx;
      if (!ok && ppfx >= m) {
        ans = i + 1;
        ok = true;
      }
    }
    if (!ok) {
      ans = n + (m - ppfx) / pfx + 1;  
    }
    auto calc = [&](long long v) {
      long long tmp = 0LL;
      for (int i = 0; i < n; i++) {
        if (i + 1 > v) {
          break;
        }
        tmp += toilets[i] * (v - i);
      }
      return tmp;
    };
    if (calc(ans) - m > m - calc(ans - 1)) {
      ans--;
    }
    int sz = (int) s.size();
    long long pow_10 = ans <= 1 ? 1 : 10;
    for (int i = 1; i < ceil(log10(ans)); i++) {
      pow_10 *= 10;
    }
    int door = floor(ans * 1.0 / pow_10 * (sz - 1));
    int left_sc = 0, tmp_lsc = 0, lsi;
    int right_sc = 0, tmp_rsc = 0, rsi;
    for (int i = 0, j = sz - 1; i <= door || j >= door; i++, j--) {
      if (i <= door) {
        if (s[i] == 'x' || i == door) {
          if (tmp_lsc >= left_sc) {
            lsi = i - ceil(tmp_lsc / 2.0);
            left_sc = tmp_lsc;
          }
          tmp_lsc = 0;
        } else {
          tmp_lsc++;
        }
      }
      if (j >= door) {
        if (s[j] == 'x' || j == door) {
          if (tmp_rsc >= right_sc) {
            rsi = j + ceil(tmp_rsc / 2.0);
            right_sc = tmp_rsc;
          }
          tmp_rsc = 0;
        } else {
          tmp_rsc++;
        }
      }
    }
    int si;
    if (left_sc == right_sc) {
      si = rsi - door <= door - lsi ? rsi : lsi;
    } else {
      si = left_sc > right_sc ? lsi : rsi;
    }
    printf("%lld %d\n", ans, si);
  }
  return 0;
}