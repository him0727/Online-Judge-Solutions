#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 51;
 
int g[MAX], r[MAX];
 
int main() {
  string s;
  while (cin >> s) {
    int S = s.size();
    g[0] = s[0] == 'G' ? 1 : 0;
    r[S - 1] = s[S - 1] == 'R' ? 1 : 0;
    for (int i = 1, j = S - 2; i < S && j >= 0; i++, j--) {
      g[i] = g[i - 1];
      if (s[i] == 'G') {
        g[i]++;
      }
      r[j] = r[j + 1];
      if (s[j] == 'R') {
        r[j]++; 
      }
    }
    int ans = min(r[0], g[S - 1]);
    for (int i = 0; i < S - 1; i++) {
      ans = min(ans, g[i] + r[i + 1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}