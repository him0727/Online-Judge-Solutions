#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> coord(n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &coord[i].first, &coord[i].second);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      vector<double> slope;
      int same = 0;
      for (int j = i + 1; j < n; j++) {
        if (coord[j].first == coord[i].first) {
          same++;
        } else {
          slope.push_back((1.0 * coord[j].second - coord[i].second) / (coord[j].first - coord[i].first));
        }
      }
      ans = max(ans, same);
      sort(slope.begin(), slope.end());
      int tmp = 0;
      for (int j = 0; j < slope.size(); j++) {
        if (j == 0 || slope[j] > slope[j - 1]) {
          tmp = 1;
        } else {
          tmp++;
        }
        ans = max(ans, tmp);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}