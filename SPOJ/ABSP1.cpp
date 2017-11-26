#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
const int SIZE = 10007;
int t, n;
ll num[SIZE];
 
int main() {
  scanf("%d", &t);
  while (t--) {
    ll ans = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      sum += num[i];
    }
    n--;
    for (int i = 0; i < n; i++) {
      sum -= num[i];
      ans += sum - (n - i) * num[i];
    }
    printf("%lli\n", ans);
  }
  return 0;
}