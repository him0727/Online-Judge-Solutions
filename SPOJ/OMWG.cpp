#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    n--;
    m--;
    printf("%d\n", n + m + ((n * m) << 1));
  }
  return 0;
}