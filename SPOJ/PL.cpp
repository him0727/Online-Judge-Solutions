#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s;
  while (cin >> s) {
    vector<int> cnt(26, 0);
    for (auto v : s) {
      cnt[v - 'a']++;
    }
    bool one_odd = false, ok = true;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        if (one_odd) {
          ok = false;
          break;
        }
        one_odd = true;
      }
    }
    if (ok) {
      printf("1\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}