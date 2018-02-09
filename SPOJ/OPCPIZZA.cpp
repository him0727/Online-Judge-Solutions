#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 100001;
 
int f[MAX];
bool skip[MAX];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &f[i]);
      skip[i] = false;
    }
    sort(f, f + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (!skip[i]) {
        int offset = m - f[i];
        int pos = lower_bound(f, f + n, offset) - f;
        if (pos == i || skip[pos]) {
          continue;
        }
        if (f[pos] == offset) {
          skip[i] = true;
          skip[pos] = true;
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}