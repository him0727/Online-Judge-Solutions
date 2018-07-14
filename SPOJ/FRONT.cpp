#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> coords[n];
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    coords[i] = {x, y};
  }
  sort(coords, coords + n, [](pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first > b.first;
  });
  int cx = coords[0].first, cy = coords[0].second;
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (coords[i].first < cx && coords[i].second > cy) {
      ans++;
      cx = coords[i].first;
      cy = coords[i].second;
    }
  }
  printf("%d\n", ans);
  return 0;
}