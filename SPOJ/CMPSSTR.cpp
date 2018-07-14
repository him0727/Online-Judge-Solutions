#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int f[55][55];
  for (int i = 0; i < 55; i++) {
    f[0][i] = f[i][0] = 0;
  }
  char s1[55], s2[55];
  while (cin.getline(s1, 55)) {
    cin.getline(s2, 55);
    int ans = 0;
    for (int i = 1; i <= strlen(s1); i++) {
      for (int j = 1; j <= strlen(s2); j++) {
        if (s1[i - 1] == s2[j - 1]) {
          f[i][j] = f[i - 1][j - 1] + 1;
        } else {
          f[i][j] = 0;
        }
        ans = max(ans, f[i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}