#include <bits/stdc++.h>
 
using namespace std;
 
int pos[50001];
 
int main() {
  int t, m;
  string s;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &m);
    cin >> s;
    int psize = 0;
    int median = (m / 2) + 1;
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        pos[++psize] = i + 1;
      }
    }
    for (int i = 1; i < median; i++) {
      left += pos[i];
    }
    for (int i = median + 1; i <= m; i++) {
      right += pos[i];
    }
    int ans = right - left + (m & 1 ? 0 : pos[median]);
    int next_median = median;
    for (int i = m + 1; i <= psize; i++) {
      left -= pos[next_median - median + 1];
      left += pos[next_median];
      next_median++;
      right -= pos[next_median];
      right += pos[i];
      int temp = right - left + (m & 1 ? 0 : pos[next_median]);
      ans = min(ans, temp);
    }
    ans -= (m * m + 2 * median * (median - 1) - 2 * m * median + m) / 2;
    printf("%d\n", ans);
  }
  return 0;
}