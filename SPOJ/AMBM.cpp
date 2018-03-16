#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll b[51];
 
int main() {
  int t, k;
  ll n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %d", &n, &k);
    b[0] = 0;
    for (int i = 1; i <= k; i++) {
      int tmp;
      scanf("%d", &tmp);
      b[i] = (b[i - 1] << 1) + tmp;
    }
    vector<int> days;
    for (int i = k; i > 0; i--) {
      if (n >= b[i]) {
        days.push_back(i);
        n -= b[i];
      }
    }
    if (n != 0) {
      printf("-1\n");
      continue;
    }
    for (int i = days.size() - 1; i >= 0; i--) {
      printf("%d", days[i]);
      if (i > 0) {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}