nclude<bits/stdc++.h>
 
using namespace std;
 
int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vector<int> stations(n);
    for (int i = 0; i < n; i++) {
      cin >> stations[i];
    }
    if (n < 8) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    sort(stations.begin(), stations.end());
    if (1422 - stations[n - 1] > 200 || 1422 - stations[n - 1] > 200 - 1422 + stations[n - 1]) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (stations[i] - stations[i - 1] > 200) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "IMPOSSIBLE" << '\n';
    } else {
      cout << "POSSIBLE" << '\n';
    }
  }
  return 0;
}