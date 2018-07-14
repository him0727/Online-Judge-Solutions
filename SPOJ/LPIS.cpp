#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  vector<int> freq(1000010, 0);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    freq[a[i]] = freq[a[i] - 1] + 1;
    ans = max(ans, freq[a[i]]);
  }
  printf("%d\n", ans);
  return 0;
}