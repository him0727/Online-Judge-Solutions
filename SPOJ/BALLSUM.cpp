#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll find_gcd(ll a, ll b) {
  return b == 0 ? a : find_gcd(b, a % b);  
}
 
int main() {
  while (1) {
    ll n, k;
    scanf("%lli %lli", &n, &k);
    if (n == -1 && k == -1) break;
    ll total = n * (n - 1) / 2;
    ll a = k & 1 ? k / 2 : k / 2 - 1;
    ll times = a * k - a * (a + 1);
    if (times == 0) {
      printf("0\n");
    } else if (times == total) {
      printf("1\n");
    } else {
      ll gcd = find_gcd(times, total);
      printf("%lli/%lli\n", times / gcd, total / gcd);
    }
  }
  return 0;
} 