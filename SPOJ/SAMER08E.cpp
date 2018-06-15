#include <bits/stdc++.h>
 
using namespace std;
 
int d[1010], m[1010], y[1010], c[1010];
int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
bool is_leap(int year) {
  if (year % 400 == 0) {
    return true;
  }
  if (year % 100 == 0) {
    return false;
  }
  if (year % 4 == 0) {
    return true;
  }
  return false;
}
 
int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", d + i, m + i, y + i, c + i);
    }
    int ad = 0, ac = 0;
    for (int i = 1; i < n; i++) {
      bool ok = false;
      if (d[i] - 1 == d[i - 1] && m[i] == m[i - 1] && y[i] == y[i - 1]) {
        ok = true;
      }
      if (d[i] == 1 && d[i - 1] == days[m[i - 1]] && m[i] - 1 == m[i - 1] && y[i] == y[i - 1]) {
        ok = true;
      }
      if (d[i] == 1 && d[i - 1] == days[m[i - 1]] && m[i] == 1 && m[i - 1] == 12 && y[i] - 1 == y[i - 1]) {
        ok = true;
      }
      if (d[i] == 1 && d[i - 1] == 28 && m[i] == 3 && m[i - 1] == 2 && y[i] == y[i - 1] && !is_leap(y[i])) {
        ok = true;
      }
      if (ok) {
        ad++;
        ac += c[i] - c[i - 1];
      }
    }
    printf("%d %d\n", ad, ac);
  }
  return 0;
}