#include <iostream>
 
using namespace std;
 
int main() {
  int t, n = 1;
  scanf("%d", &t);
  while(t--) {
    double r;
    scanf("%lf", &r);
    printf("Case %d: %.2lf\n", n++, 0.25 + 4 * r * r);
  }
  return 0;
}