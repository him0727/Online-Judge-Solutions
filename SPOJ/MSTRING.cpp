#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int>> f(s1.size() + 1, vector<int> (s2.size() + 1));
  vector<vector<int>> next(s1.size(), vector<int> (s2.size()));
  for (int i = 0; i < s1.size(); i++) {
    int last = -1;
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) {
        last = j;
      }
      next[i][j] = last;
    }
  }
  for (int i = 1; i <= s1.size(); i++) {
    f[i][0] = 1;
  }
  for (int i = 0; i <= s2.size(); i++) {
    f[0][i] = 1010;
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      f[i][j] = next[i - 1][j - 1] == -1 ? 1 : min(f[i - 1][j], f[i - 1][next[i - 1][j - 1]] + 1);
    }
  }
  printf("%d\n", f[s1.size()][s2.size()]);
  return 0;
}