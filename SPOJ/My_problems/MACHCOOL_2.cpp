#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
      cin >> tasks[i];
    }
    sort(tasks.begin(), tasks.end());
    int low = 0;
    int high = 86400;
    int ans = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      bool ok = true;
      for (int i = 0; i + m < n && ok; i++) {
        ok &= (tasks[i + m] - tasks[i]) >= mid;
      }
      if (ok) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}