#include <bits/stdc++.h>
typedef unsigned long long ull;
 
using namespace std;
 
int toilets[510];
 
ull calc(ull v, int n) {
  ull tmp = 0LL;
  for (int i = 0; i < n; i++) {
    if (i + 1 > v) {
      break;
    }
    tmp += v * toilets[i];
    tmp -= i * toilets[i];
  }
  return tmp;
}
 
ull to_pow10(ull v) {
  if (v <= 1) {
    return 1;
  }
  if (v <= 10) {
    return 10;
  }
  ull base = 10LL;
  for (ull i = 1; i < ceil(log10(v)); i++) {
    base *= 10;
  }
  return base;
}

ull uabs(ull v1, ull v2) {
  return v1 > v2 ? v1 - v2 : v2 - v1;
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ull m;
    string s;
    scanf("%d %llu", &n, &m);
    cin >> s;
    for (int i = 0; i < n; i++) {
      scanf("%d", &toilets[i]);
    }
    ull low = 1, high = m / toilets[0];
    while (low < high) {
      ull mid = low + ((high - low) >> 1);
      if (calc(mid, n) >= m) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    if (uabs(calc(high, n), m) > uabs(calc(high - 1, n), m)) {
      high -= 1;
    }
    int sz = (int) s.size();
    int door = floor(high * 1.0 / to_pow10(high) * (sz - 1));
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
    printf("%llu %d\n", high, si);
  }
  return 0;
}