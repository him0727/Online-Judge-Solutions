#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int lps[100010];
 
int main() {
  while (1) {
    cin >> s;
    if (s == "*") {
      break;
    }
    int sz = s.size();
    {
      int i = 1, j = 0;
      lps[0] = 0;
      while (i < sz) {
        if (s[i] == s[j]) {
          lps[i++] = ++j;
          continue;
        }
        if (j == 0) {
          lps[i++] = 0;
        } else {
          j = lps[j - 1];
        }
      }
    }
    int len = sz - lps[sz - 1];
    if (lps[sz - 1] == 0 || sz % len != 0) {
      printf("1\n");
      continue;
    }
    bool ok = true;
    string token = s.substr(0, len);
    for (int i = len; i < sz; i++) {
      if (s[i] != token[i % len]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%d\n", sz / len);
    } else {
      printf("1\n");
    }
  }
  return 0;
}