#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  const long long MOD = 1000000007;
  int n;
  scanf("%d", &n);
  long long max_num = -1000000000000000000;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    max_num = max(max_num, a);
  }
  auto power = [](int p) {
    long long ans = 1;
    long long base = 2;
    while (p > 0) {
      if (p % 2) {
        ans = (ans * base) % MOD;
      }
      base = (base * base) % MOD;
      p >>= 1;
    }
    return ans;
  };
  auto mul = [](long long &ans, long long a) {
    a--;
    ans = (ans % MOD + MOD) % MOD;
    long long b = ans;
    while (a > 0) {
      if (a % 2) {
        ans = (ans + b) % MOD;
      }
      b = (b * 2) % MOD;
      a /= 2;
    }
    ans %= MOD;
  };
  long long ans = max_num;
  mul(ans, power(n - 1));
  printf("%lld\n", ans);
  return 0;
}