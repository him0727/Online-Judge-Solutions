#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x, d, n;
    scanf("%d %d %d", &x, &d, &n);
    vector<vector<int>> stone(x + 1, vector<int>());
    for (int i = 1; i <= x; i++) {
      int tot;
      scanf("%d", &tot);
      while (tot--) {
        int s;
        scanf("%d", &s);
        stone[i].push_back(s);
      }
    }
    if (n >= d) {
      printf("0\n");
      continue;
    }
    int at = 0, ans = 0;
    bool ok = false;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int s = 1; s <= x; s++) {
      for (int i = 0; i < stone[s].size(); i++) {
        pq.push(stone[s][i]);
      }
      while (!pq.empty() && !ok) {
        int now = pq.top();
        if (now - at > n) {
          break;
        }
        pq.pop();
        if (at >= now) {
          continue;
        }
        at = now;
        if (at + n >= d) {
          ok = true;
          ans = s;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    printf("%d\n", (ok ? ans : - 1));
  }
  return 0;
}