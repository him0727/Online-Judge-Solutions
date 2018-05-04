#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2000000;
 
int club[MAX + 1];
 
int main() {
  fill(club, club + MAX + 1, 0);
  int n, v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    club[v]++;
  }
  long long ans = n;
  for (int i = 1; i <= MAX; i++) {
    int tmp = 0;
    for (int j = i; j <= MAX; j += i) {
      tmp += club[j];
    }
    if (tmp > 1) {
      ans = max(ans, (long long)i * tmp);
    }
  }
  printf("%lld\n", ans);
  return 0;
}