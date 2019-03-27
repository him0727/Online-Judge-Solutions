#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x, a;
    scanf("%d %d", &x, &a);
    int n = a - x;
    printf("%d\n", n * (a + 1) - n * (n - 1) / 2);
  }
  return 0;
}