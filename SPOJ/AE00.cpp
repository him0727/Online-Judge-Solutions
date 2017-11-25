#include <bits/stdc++.h>

using namespace std;
 
int main() {
  int n, ans = 0, i = 2;
  scanf("%d", &n);
  while (n / i + 1 - i > 0) {
    ans += n / i + 1 - i++;
  }
  printf("%d", ans + n);
  return 0;
} 