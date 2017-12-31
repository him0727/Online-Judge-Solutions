#include <bits/stdc++.h>
 
using namespace std;
int t, x, y;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &x, &y);
    int xx = 0, yy = 0;
    for (int i = 1; i <= sqrt(x); i++) {
      if (x % i == 0) {
        xx += i;
        if (i != 1 && i * i != x) xx += x / i;
      }
    }
    for (int i = 1; i <= sqrt(y); i++) {
      if (y % i == 0) {
        yy += i;
        if (i != 1 && i * i != y) yy += y / i;
      }
    }
    if (xx == y && yy == x) printf("Friendship is ideal\n");
    else printf("Friendship is not ideal\n");
  }
  return 0;
}