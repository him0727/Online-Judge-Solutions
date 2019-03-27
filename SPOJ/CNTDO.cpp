#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[n];
    int max_value = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      max_value = max(max_value, a[i]);
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      freq[a[i]]++;
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i > 0 && a[i] == a[i - 1]) {
        continue;
      }
      int next = a[i] << 1;
      if (next > max_value) {
        break;
      }
      int fq = freq[next];
      if (fq > 0) {
        ans += fq;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}