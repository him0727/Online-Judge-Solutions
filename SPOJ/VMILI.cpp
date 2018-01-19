#include <bits/stdc++.h>
 
using namespace std;
 
int on, cn;
pair<int, int> coords[4001];
int convex[4001], visited[4001];
 
bool compare(const pair<int, int> &lhs, const pair<int, int> &rhs) {
  return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
}
 
int dir(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}
 
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  on = n;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &coords[i].first, &coords[i].second);
  }
  sort(coords, coords + n, compare);
  while (on > 2) {
    ans++;
    cn = 0;
    for (int i = 0; i < on; i++) {
      while (cn > 1 && dir(coords[convex[cn - 2]], coords[convex[cn - 1]], coords[i]) < 0) {
        cn--;
      }
      convex[cn++] = i;
    }
    for (int i = on - 2, j = cn; i >= 0; i--) {
      while (cn > j && dir(coords[convex[cn - 2]], coords[convex[cn - 1]], coords[i]) < 0) {
        cn--;
      }
      convex[cn++] = i;
    }
    cn--;
    for (int i = 0; i < cn; i++) {
      visited[convex[i]] = ans;
    }
    for (int i = 0, j = 0; i < on; i++) {
      if (visited[i] != ans) {
        coords[j++] = coords[i];
      }
    }
    on -= cn;
  }
  printf("%d\n", ans);
  return 0;
}