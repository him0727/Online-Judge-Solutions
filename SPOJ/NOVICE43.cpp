#include <bits/stdc++.h>
 
using namespace std;
 
int f[12][13];
 
int main() {
  f[1][1] = f[1][12] = 1;
  for (int i = 2; i < 12; i++) {
    int sum = 0;
    for (int j = 1; j <= i; j++) {
      f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * j;
      sum += f[i][j];
    }
    f[i][12] = sum;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", f[n][12]);
  }
  return 0;
} 