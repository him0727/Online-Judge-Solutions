#include <bits/stdc++.h>
 
using namespace std;
 
int rev(int n) {
  int revs = 0;
  while (n > 0) {
    revs <<= 1;
    if (n & 1) {
      revs ^= 1;
    }
    n >>= 1;             
  }
  return revs;
}
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2 == 0) {
      printf("%d\n", rev(a));
    } else {
      printf("%d\n", a);
    }
  }
  return 0;
}