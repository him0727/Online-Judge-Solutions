#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int> plank[11000];
 
bool compare(const pair<int, int> &left, const pair<int, int> &right) {
  return left.second != right.second ? left.second < right.second : left.first < right.first;
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &plank[i].first, &plank[i].second);
    }
    sort(plank, plank + n, compare);
    int ans = 1;
    int bound = plank[0].second;
    for (int i = 1; i < n; i++) {
      if (plank[i].first > bound) {
        ans++;
        bound = plank[i].second;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}