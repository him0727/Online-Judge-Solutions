#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
const ll SIZE = 1000001;
ll dp[SIZE];
 
ll max(ll a, ll b) {
  return a > b ? a : b;
}
 
ll solve(ll n) {
  if (n < SIZE) {
    return dp[n];
  }
  return solve(n >> 1) + solve(n / 3) + solve(n >> 2);
}
 
int main() {
  for (ll i = 0; i < SIZE; i++) {
    dp[i] = max(i, dp[i >> 1] + dp[i / 3] + dp[i >> 2]);
  }
  ll n;
  while (scanf("%lld", &n) != EOF) {
    printf("%lld\n", solve(n));
  }
  return 0;
}