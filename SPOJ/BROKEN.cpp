#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    string s;
    cin.ignore();
    getline(cin, s);
    int sz = s.size();
    if (sz <= n) {
      printf("%d\n", sz);
      continue;
    }
    set<int> se;
    vector<int> cnt(130, 0);
    int head = 0, ans = 0;
    for (int i = 0; i < sz && head < n; i++) {
      if (cnt[s[i]]++ == 0) {
        se.insert(s[i]);
        head++;
      }
      ans++;
    }
    head = 0;
    for (int i = ans; i < sz; i++) {
      se.insert(s[i]);
      cnt[s[i]]++;
      if (se.size() > n) {
        while (--cnt[s[head]]) {
          head++;
        }
        se.erase(s[head++]);
      }
      ans = max(ans, i - head + 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}