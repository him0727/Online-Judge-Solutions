#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if ((x == 1 && y == 1) || (x == 0 && y == 0)) {
      printf("%d\n", x);
    } else if (x == y || y == x - 2) {
      if (x & 1) {
        printf("%d\n", x + y - 1);
      } else {
        printf("%d\n", x + y);
      }
    } else {
      printf("No Number\n");
    }
  }
  return 0;
}