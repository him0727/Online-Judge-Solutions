#include <bits/stdc++.h>
 
using namespace std;
 
int t[2010];
int f[2010][2010];
 
int main() {  
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
    f[i][i] = n * t[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      int l = n - j + i;
      f[i][j] = max(l * t[i] + f[i + 1][j], l * t[j] + f[i][j - 1]);
    }
  }
  printf("%d\n", f[1][n]);
  return 0;
}