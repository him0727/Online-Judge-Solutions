#include <bits/stdc++.h>
 
using namespace std;
 
int m1[1010], m2[1010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
      scanf("%d", m1 + i);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
      scanf("%d", m2 + i);
    }
    sort(m1, m1 + n1);
    sort(m2, m2 + n2);
    int ans = INT_MAX;
    int s = 0, f = 0;
    while (s < n1 || f < n2) {
      if (s >= n1) {
        ans = min(ans, abs(m1[n1 - 1] - m2[f]));
      } else if (f >= n2) {
        ans = min(ans, abs(m1[s] - m2[n2 - 1]));
      } else {
        ans = min(ans, abs(m1[s] - m2[f]));
      }
      if (s < n1 && f < n2) {
        if (m1[s] == m2[f]) {
          ans = 0;
          break;
        }
        if (m1[s] > m2[f]) {
          f++;
        } else {
          s++;
        }
      } else if (s < n1) {
        s++;
      } else if (f < n2) {
        f++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}