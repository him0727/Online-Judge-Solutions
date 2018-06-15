#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int m[10];
vector<vector<int>> c(10);
 
int main() {
  for (int i = 0; i < 8; i++) {
    scanf("%d", m + i);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    c[a - 1].push_back(b - 1);
    c[b - 1].push_back(a - 1);
  }
  int ans = 0;
  for (int i = 0; i < (1 << 8); i++) {
    bool ok = true;
    int tmp = 0;
    for (int j = 0; j < 8; j++) {
      if (i & (1 << j)) {
        for (auto v : c[j]) {
          if (i & (1 << v)) {
            ok = false;
            break;
          }
        }
        tmp += m[j];
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      ans = max(ans, tmp);
    }
  }
  printf("%d\n", ans);
  return 0;
}