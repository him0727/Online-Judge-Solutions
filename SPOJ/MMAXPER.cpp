#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int> rect[1001];
int res1[1001], res2[1001];
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &rect[i].first, &rect[i].second);
  }
  res1[0] = rect[0].first;
  res2[0] = rect[0].second;
  for (int i = 1; i < n; i++) {
    res1[i] = rect[i].first + max(abs(rect[i].second - rect[i - 1].second) + res1[i - 1], abs(rect[i].second - rect[i - 1].first) + res2[i - 1]);
    res2[i] = rect[i].second + max(abs(rect[i].first - rect[i - 1].first) + res2[i - 1], abs(rect[i].first - rect[i - 1].second) + res1[i - 1]);
  }
  printf("%d\n", max(res1[n - 1], res2[n - 1]));
  return 0;
}