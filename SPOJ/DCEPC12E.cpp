#include <bits/stdc++.h>
 
using namespace std;
 
long long a[110][110], b[110][110];
 
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lld", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lld", &b[i][j]);
    }
  }
  long long sum = 0LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        sum += a[i][k] * b[k][j];
      }
    }
  }
  scanf("%d", &q);
  char w;
  int r, c, v;
  while (q--) {
    scanf(" %c %d %d %d", &w, &r, &c, &v);
    if (w == 'A') {
      for (int i = 0; i < n; i++) {
        sum -= a[r][c] * b[c][i];
        sum += v * b[c][i];
      }
      a[r][c] = v;
    }
    if (w == 'B') {
      for (int i = 0; i < n; i++) {
        sum -= b[r][c] * a[i][r];
        sum += v * a[i][r];
      }
      b[r][c] = v;
    }
    printf("%lld\n", sum);
  }
  return 0;
}