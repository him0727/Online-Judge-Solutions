#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    int ans = 0, start = 2;
    while (start <= n) {
      ans += (n - start + 1) * (n - start + 1);
      start++;
    }
    printf("%d\n", ans + n * n);
  }
  return 0;
} 