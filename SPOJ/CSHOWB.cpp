#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  vector<stack<int>> sf(6);
  int n, p, s, f;
  scanf("%d %d", &n, &p);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s, &f);
    s--;
    if (sf[s].empty()) {
      sf[s].push(f);
      ans++;
      continue;
    }
    if (f == sf[s].top()) {
      continue;
    }
    if (f > sf[s].top()) {
      sf[s].push(f);
      ans++;
    } else {
      while (!sf[s].empty() && sf[s].top() > f) {
        sf[s].pop();
        ans++;
      }
      if (sf[s].empty() || sf[s].top() != f) {
        sf[s].push(f);
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}