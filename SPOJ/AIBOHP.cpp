#include <bits/stdc++.h>
 
using namespace std;
 
int f[6500][6500];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s1, s2;
    cin >> s2;
    s1 = s2;
    reverse(s2.begin(), s2.end());
    int sz = s1.size();
    for (int i = 0; i <= sz; i++) {
      f[i][0] = f[0][i] = 0;
    }
    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= sz; j++) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        if (s1[i - 1] == s2[j - 1]) {
          f[i][j] = f[i - 1][j - 1] + 1;
        }
      }
    }
    printf("%d\n", sz - f[sz][sz]);
  }
  return 0;
}