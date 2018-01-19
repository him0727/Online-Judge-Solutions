#include <bits/stdc++.h>
#define MOD 1000007
typedef long long ll;
 
using namespace std;
 
int t;
ll n;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    ll ans = n * (n + 1) + n * (n - 1) / 2;
    printf("%lld\n", ans % MOD);
  }
  return 0;
}