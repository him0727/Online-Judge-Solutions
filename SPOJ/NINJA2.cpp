#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s;
    cin >> s;
    int sz = s.size();
    vector<int> cnt(26, 0);
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    sort(cnt.begin(), cnt.end(), [](int l, int r) {
      return l > r;
    });
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0) {
        cnt.resize(i);
        break;
      }
    }
    int ans = INT_MAX;
    int wsz = cnt.size();
    for (int i = 0; i < 26; i++) {
      int go = sz % (i + 1);
      if (go > 0) {
        continue;
      }
      int d = sz / (i + 1);
      int tmp = 0;
      if (wsz > i + 1) {
        for (int j = 0; j <= i; j++) {
          if (cnt[j] > d) {
            tmp += cnt[j] - d;
          }
        }
        for (int j = i + 1; j < wsz; j++) {
          tmp += cnt[j];
        }
      } else {
        for (int j = 0; j < wsz; j++) {
          if (cnt[j] > d) {
            tmp += cnt[j] - d;
          }
        }
      }
      ans = min(ans, tmp);
    }
    printf("%d\n", ans);
  }
  return 0;
}