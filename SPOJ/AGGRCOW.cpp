#include <bits/stdc++.h>
 
using namespace std;
 
int stalls[100010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
      scanf("%d", stalls + i);
    }
    sort(stalls, stalls + n);
    int low = 0, high = stalls[n - 1];
    while (low < high) {
      int mid = low + (high - low) / 2;
      int cnt = 1, p = stalls[0];
      bool ok = false;
      for (int i = 1; i < n; i++) {
        if (stalls[i] - p >= mid) {
          cnt++;
          p = stalls[i];
        }
        if (cnt == c) {
          ok = true;
          break;
        }
      }
      if (ok) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    printf("%d\n", low - 1);
  }
  return 0;
}