#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  while (1) {
    int g, b;
    scanf("%d %d", &g, &b);
    if (g == -1 && b == -1) {
      break;
    }
    if (g == 0 || b == 0) {
      printf("%d\n", max(g, b));
      continue;
    }
    if (g < b) {
      swap(g, b);
    }
    double ans = g * 1.0 / (b + 1);
    printf("%d\n", (int) ceil(ans));
  }
  return 0;
}