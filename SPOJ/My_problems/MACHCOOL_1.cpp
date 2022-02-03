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
    int ans = 86400;
    for (int i = 0; i + m < n; i++) {
      ans = min(ans, tasks[i + m] - tasks[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}