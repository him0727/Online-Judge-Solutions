#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long m, ans = -1, sum = 0, accumlate = 0;
    cin >> n >> m;
    string cubicles;
    cin >> cubicles;
    vector<long long> odors(n);
    for (int i = 0; i < n; i++) {
      cin >> odors[i];
      sum += odors[i];
      accumlate += sum;
      if (ans == -1 && accumlate >= m) {
        ans = i + 1;
      }
    }
    if (ans == -1) {
      ans = n + ((m - accumlate) / sum ) + 1;
    }
    auto find_diff = [&](long long cur) {
      long long res = 0;
      for (int i = 0; i < n && i < cur; i++) {
        res += odors[i] * (cur - i);
      }
      return res;
    };
    if (find_diff(ans) - m > m - find_diff(ans - 1)) {
      ans--;
    }
    long long p = ans <= 1 ? 1 : 10;
    for (int i = 1; i < ceil(log10(ans)); i++) {
      p *= 10;
    }
    int len = (int) cubicles.size();
    int door = floor(ans * 1.0 / p * (len - 1));
    cubicles[door] = 'x';
    int diff = -1, mid = -1, dist = -1;
    int choice = -1;
    for (int i = 0; i < len; i++) {
      if (cubicles[i] == 'x') {
        continue;
      }
      int l = i, r = i;
      while (l >= 0 && cubicles[l] == 'o') {
        l--;
      }
      while (r < len && cubicles[r] == 'o') {
        r++;
      }
      int cur_diff = i - l + r - i;
      int cur_mid = min(i - l, r - i);
      int cur_dist = abs(i - door);
      bool is_best = cur_diff > diff;
      if (cur_diff == diff) {
        is_best = cur_mid > mid || (cur_mid == mid && cur_dist <= dist);
      }
      if (is_best) {
        diff = cur_diff;
        mid = cur_mid;
        dist = cur_dist;
        choice = i;
      }
    }
    cout << ans << ' ' << choice << '\n';
  }
  return 0;
}