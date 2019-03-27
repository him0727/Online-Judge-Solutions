#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long solve(long long n) {
  if (n <= 4) {
    return n;
  }
  long long ret = 1LL;
  long long base = 3; 
  long long nn = n / base;
  if (n % base == 1) {
    nn--;
  }
  while (nn > 0) {
    if (nn & 1) {
      ret = (ret * base) % MOD;
    }
    base = (base * base) % MOD;
    nn >>= 1;
  }
  base = 3;
  if (n % base == 1) {
    ret <<= 2;
  } else if (n % base == 2) {
    ret <<= 1;
  }
  return ret % MOD;
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
  }
  return 0;
}