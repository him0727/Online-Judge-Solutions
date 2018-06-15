#include <bits/stdc++.h>
 
using namespace std;
 
int f[110][110];
 
int main() {
  for (int i = 0; i < 110; i++) {
    f[i][0] = f[0][i] = 0;
  }
  string s1, s2;
  while (cin >> s1 && cin >> s2) {
    int sz1 = s1.size();
    int sz2 = s2.size();
    for (int i = 0; i < sz1; i++) {
      for (int j = 0; j < sz2; j++) {
        if (s1[i] == s2[j]) {
          f[i + 1][j + 1] = f[i][j] + 1;
          continue;
        }
        f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
      }
    }
    string lcs = "";
    int a = sz1, b = sz2;
    while (a > 0 && b > 0) {
      if (s1[a - 1] == s2[b - 1]) {
        lcs.push_back(s1[a - 1]);
        a--;
        b--;
      } else {
        if (f[a][b - 1] > f[a - 1][b]) {
          b--;
        } else {
          a--;
        }
      }
    }
    reverse(lcs.begin(), lcs.end());
    string ans = "";
    int p = 0, lcsz = lcs.size();
    a = 0, b = 0;
    while (p < lcsz) {
      if (s1[a] == lcs[p] && s2[b] == lcs[p]) {
        ans.push_back(lcs[p++]);
        a++;
        b++;
      } else if (s1[a] == lcs[p] && s1[a] != s2[b]) {
        ans.push_back(s2[b++]);
      } else if (s2[b] == lcs[p] && s2[b] != s1[a]) {
        ans.push_back(s1[a++]);
      } else {
        ans.push_back(s1[a++]);
        ans.push_back(s2[b++]);
      }
    }
    while (a < sz1) {
      ans.push_back(s1[a++]);
    }
    while (b < sz2) {
      ans.push_back(s2[b++]);
    }
    cout << ans << '\n';
  }
  return 0;
}