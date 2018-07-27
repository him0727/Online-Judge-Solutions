#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
long long f[6][N];

struct GIFT {
  long long w, h, d;
} gift[6][N];

void solve(int i) {
  for (int now = 0; now < 6; now++) {
    long long cur_max = 0;
    GIFT cur = gift[now][i];
    for (int other = 0; other < 6; other++) {
      long long dh = 0, dd = 0;
      GIFT prev = gift[other][i - 1];
      if (cur.h > prev.h) {
        dh = (cur.h - prev.h) * cur.d;
        if (cur.d <= prev.d) {
          dh *= 2;
        }
      }
      if (cur.d > prev.d) {
        dd = (cur.d - prev.d) * cur.h;
        if (cur.h <= prev.h) {
          dd *= 2;
        }
      }
      if (cur.h > prev.h && cur.d > prev.d) {
        dh -= (cur.d - prev.d) * (cur.h - prev.h);
        dh *= 2;
        dd *= 2;
      }
      cur_max = max(cur_max, cur.w * cur.d * 2 + cur.w * cur.h + f[other][i - 1] + dd + dh);
    }
    f[now][i] = cur_max;
  }
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      long long w, h, d;
      scanf("%lld %lld %lld", &w, &h, &d);
      gift[0][i] = GIFT {w, h, d};
      gift[1][i] = GIFT {w, d, h};
      gift[2][i] = GIFT {d, h, w};
      gift[3][i] = GIFT {d, w, h};
      gift[4][i] = GIFT {h, d, w};
      gift[5][i] = GIFT {h, w, d};
    }
    for (int i = 0; i < 6; i++) {
      GIFT cur = gift[i][0];
      f[i][0] = cur.w * cur.d * 2 + cur.h * cur.d * 2 + cur.w * cur.h;
    }
    for (int i = 1; i < n; i++) {
      solve(i);
    }
    long long ans = 0;
    for (int i = 0; i < 6; i++) {
      ans = max(ans, f[i][n - 1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}