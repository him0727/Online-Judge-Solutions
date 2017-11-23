#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
ll find_gcm(ll a, ll b) {
  return b == 0 ? a : find_gcm(b, a % b);  
}
 
int main() {
  while (1) {
    ll n, k;
    scanf("%lli %lli", &n, &k);
    if (n == -1 && k == -1) break;
    
    ll a = n * (n - 1) / 2;
    ll b = k & 1 ? k / 2 : k / 2 - 1;
    ll c = b * k - b * (b + 1);
    ll total = a, prob = c;
    
    if (prob == 0) {
      printf("0\n");
    } else if (prob == total) {
      printf("1\n");
    } else {
      ll gcm = find_gcm(prob, total);
      printf("%lli/%lli\n", prob / gcm, total / gcm);
    }
  }
  return 0;
} 
