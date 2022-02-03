#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> coord(n, vector<int>(3));
    vector<vector<pair<int, int>>> order(3, vector<pair<int, int>>(n));
    vector<vector<int>> sum(3, vector<int>(n + 1));
    vector<vector<int>> dist(3, vector<int>(n));
    for (int i = 0; i < n; i++) {
      cin >> coord[i][0]  >> coord[i][1] >> coord[i][2];
      for (int j = 0; j < 3; j++) {
        order[j][i] = {coord[i][j], i};
      }
    }
    for (int i = 0; i < 3; i++) {
      sort(order[i].begin(), order[i].end());
      for (int j = 1; j <= n; j++) {
        sum[i][j] = order[i][j - 1].first + sum[i][j - 1];
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][order[i][j].second] = j * order[i][j].first - sum[i][j] + sum[i][n] - sum[i][j + 1] - (n - j - 1) * order[i][j].first;
      }
    }
    int min_dist = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int cur_dist = dist[0][i] + dist[1][i] + dist[2][i];
      if (min_dist >= cur_dist) {
        if (min_dist > cur_dist) {
          ans.clear();
          min_dist = cur_dist;
        }
        ans.push_back(i);
      }
    }
    for (int i : ans) {
      cout << coord[i][0] << ' ' << coord[i][1] << ' ' << coord[i][2] << '\n';
    }
  }
  return 0;
}