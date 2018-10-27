#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    vector<int> cnt(n), pos(n, -1);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int t = -1;
      for (int j = 0; j < n; j++) {
        if (s[j] == '1') {
          t = j;
        }
      }
      cnt[i] = t;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (pos[j] == -1 && cnt[j] <= i) {
          pos[j] = i;
          break;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (pos[i] > pos[j]) {
          ans++;
        }
      }
    }
    printf("Case #%d: %d\n", qq, ans);
  }  
  return 0;
}