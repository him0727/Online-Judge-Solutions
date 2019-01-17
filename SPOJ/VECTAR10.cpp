#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int log = (int) log2(n);
    printf("%d\n", ((1 << log) == n ? n : (n - (1 << log)) << 1));
  }
  return 0;
}