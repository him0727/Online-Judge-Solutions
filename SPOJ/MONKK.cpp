#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  const int N = 110;
  char field[N][N];
  int bad[N][N], good[N][N], f[N][N];
  for (int i = 0; i < N; i++) {
    f[i][0] = f[0][i] = 0;
    bad[i][0] = bad[0][i] = 0;
    good[i][0] = good[0][i] = 0;
  }
  for (int qq = 1; qq <= tt; qq++) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      scanf("%s", field[i]);
    }
    int from = 0;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        good[i][j] = good[i - 1][j] + good[i][j - 1] - good[i - 1][j - 1] + (field[i - 1][j - 1] == 'B');
        bad[i][j] = bad[i - 1][j] + bad[i][j - 1] - bad[i - 1][j - 1] + (field[i - 1][j - 1] == 'T');
        f[i][j] = field[i - 1][j - 1] == 'T' ? 0 : min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
        from = max(from, f[i][j]);
      }
    }
    auto get_good = [&](int i, int j, int w) {
      return good[i][j] - good[i - w][j] - good[i][j - w] + good[i - w][j - w];
    };
    auto get_bad = [&](int i, int j, int w) {
      return bad[i][j] - bad[i - w][j] - bad[i][j - w] + bad[i - w][j - w];
    };
    int ans = 0;
    for (int sz = from; sz <= min(r, c); sz++) {
      for (int i = sz - 1; i < r; i++) {
        for (int j = sz - 1; j < c; j++) {
          ans = max(ans, get_good(i + 1, j + 1, sz) - get_bad(i + 1, j + 1, sz));
        }
      }
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}