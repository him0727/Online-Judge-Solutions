#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  int p[11];
  p[0] = 1;
  for (int i = 1; i < 11; i++) {
    p[i] = 34 * p[i - 1] % 11;
  }
  while (tt--) {
    long long n;
    scanf("%lld", &n);
    long long f = p[n % 11] + 8 * (n % 11) + 10;
    if (f % 11 == 0) {
      printf("0\n");
    } else {
      printf("%lld\n", 11 - (f % 11));
    }
  }
}