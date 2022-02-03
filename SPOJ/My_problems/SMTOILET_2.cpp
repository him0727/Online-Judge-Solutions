#include <bits/stdc++.h>

using namespace std;

long long find_diff(long long cur, vector<long long>& odors) {
  long long ans = 0;
  for (int i = 0; i < (int) odors.size() && i < cur; i++) {
    ans += odors[i] * (cur - i);
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long m;
    cin >> n >> m;
    long long sum = 0, extra = m;
    string cubicles;
    cin >> cubicles;
    vector<long long> odors(n);
    for (int i = 0; i < n; i++) {
      cin >> odors[i];
      sum += odors[i];
      extra -= odors[i] * (n - i);
    }
    long long low = 1;
    long long high = n + (max(extra, 0LL) / sum) + 1;
    while (low < high) {
      long long mid = low + (high - low) / 2;
      if (find_diff(mid, odors) < m) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    if (find_diff(high, odors) - m > m - find_diff(high - 1, odors)) {
      high--;
    }
    long long p = high <= 1 ? 1 : 10;
    for (int i = 1; i < ceil(log10(high)); i++) {
      p *= 10;
    }
    int len = (int) cubicles.size();
    int door = floor(high * 1.0 / p * (len - 1));
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
    cout << high << ' ' << choice << '\n';
  }
  return 0;
}