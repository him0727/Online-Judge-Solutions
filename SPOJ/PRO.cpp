#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
int main() {
  int days;
  ll ans = 0;
  scanf("%d", &days);
  multiset <int, greater <int>> amount;
  
  while (days--) {
    ll n, now_amount;
    scanf("%lli", &n);
 
    for (ll i = 0; i < n; i++) {
      scanf("%lli", &now_amount);
      amount.insert(now_amount);
    }
    
    if (amount.size() < 2) continue;
    ans += *amount.begin() - *prev(amount.end());
    amount.erase(amount.begin());
    amount.erase(prev(amount.end()));
  }
  
  printf("%lli\n", ans);
  return 0;
} 
