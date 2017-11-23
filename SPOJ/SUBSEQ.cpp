#include <bits/stdc++.h>
 
#define ll long long int
#define l long int
 
using namespace std;
 
int main() {
  ll t;
  scanf("%lli", &t);
  
  while (t--) {
    ll n, sum = 0, ans = 0;
    scanf("%lli", &n);
    map <ll, ll> value;
    value[0] = 1;
    ll i = n;
    
    while (i--) {
      ll s;
      scanf("%lli", &s);
      sum += s;
      ans += value[sum - 47];
      value[sum]++;
    }
    printf("%lli\n", ans);
  }
  return 0;
}  
