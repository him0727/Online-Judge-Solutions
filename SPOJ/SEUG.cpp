#include <bits/stdc++.h>
 
using namespace std;
int t, a, b, h, w, n;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d", &a, &b, &h, &w);
    scanf("%d", &n);
    int stones[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &stones[i]);
    }
    sort(stones, stones + n, greater<int>());
    int ans = 0, cur_w = w;
    for (int &i : stones) {
      cur_w += i;
      ans++;
      if (cur_w > h) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}