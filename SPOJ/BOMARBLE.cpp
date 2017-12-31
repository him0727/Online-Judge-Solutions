#include <bits/stdc++.h>
 
using namespace std;
int n;
 
int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    int base = 5, last = 2;
    if (n <= 2) {
      printf("%d\n", n * 5 + (n - 1) * last);
      continue;
    }
    int itr = (n - 2) * (5 + (2 + (n - 2) * 3)) / 2;
    printf("%d\n", base * n + itr + last);
  }
  return 0;
}