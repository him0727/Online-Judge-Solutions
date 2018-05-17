#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int a[40];
int f[40][40];
 
int low(int from, int to) {
  if (from > to || from < 0 || to >= n) {
    return 0;
  }
  if (f[from][to] != -1) {
    return f[from][to];
  }
  int min1 = a[from] + min(low(from + 2, to), low(from + 1, to - 1));
  int min2 = a[to] + min(low(from, to - 2), low(from + 1, to - 1));
  return f[from][to] = max(min1, min2);
}
 
int high(int from, int to) {
  if (from > to || from < 0 || to >= n) {
    return 0;
  }
  if (f[from][to] != -1) {
    return f[from][to];
  }
  int max1 = a[from] + max(high(from + 2, to), high(from + 1, to - 1));
  int max2 = a[to] + max(high(from, to - 2), high(from + 1, to - 1));
  return f[from][to] = max(max1, max2);
}
 
void reset() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f[i][j] = -1;
    }
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    reset();
    printf("%d ", high(0, n - 1));
    reset();
    printf("%d\n", low(0, n - 1));
  }
  return 0;
}