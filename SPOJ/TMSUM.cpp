#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, tmp, zero = 0;
    vector<int> pos, neg;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      if (tmp == 0) {
        zero = 1;
        continue;
      }
      if (tmp < 0) {
        neg.push_back(tmp);
      } else {
        pos.push_back(tmp);
      }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    long long ans = 0;
    for (int i = 1; i < pos.size(); i += 2) {
      if (pos[i] == 1 || pos[i - 1] == 1) {
        ans += pos[i] + pos[i - 1];
      } else {
        ans += pos[i] * pos[i - 1];
      }
    }
    if (pos.size() % 2 == 1) {
      ans += pos[pos.size() - 1];
    }
    for (int i = 1; i < neg.size(); i += 2) {
      ans += neg[i] * neg[i - 1];
    }
    if (neg.size() % 2 == 1 && zero == 0) {
      ans += neg[neg.size() - 1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}