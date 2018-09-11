#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;
    printf("%d %d\n", b, a);
  }
  return 0;
}