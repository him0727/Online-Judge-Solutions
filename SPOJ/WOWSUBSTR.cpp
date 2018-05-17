#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 100007;
 
int r[26];
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    string s;
    cin >> s;
    fill(r, r + 26, 0);
    int sz = (int) s.size();
    int last = 0, ans = 0;
    for (int i = 0; i < sz; i++) {
      int k = last;
      for (int j = k; j < sz; j++) {
        r[s[j] - 'a']++;
        if (r[s[j] - 'a'] > 1) {
          r[s[j] - 'a']--;
          r[s[i] - 'a']--;
          break;
        }
        last++;
      }
      int tmp = last - i;
      ans = (ans + tmp * (tmp + 1) / 2) % MOD;
    }
    printf("Case %d: %d\n", qq, ans);
  }
  return 0;
}