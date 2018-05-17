#include <bits/stdc++.h>
 
using namespace std;
 
const double PI = acos(-1);
 
int t;
double x, y, r;
 
int main() {
  scanf("%ld", &t);
  while (t--) {
    scanf("%lf %lf %lf", &x, &y, &r);
    double r_dist = sqrt(x * x + y * y);
    double t_dist = sqrt(r_dist * r_dist - r * r);
    double angle = abs(90 * PI / 180 - atan2(y, x) - asin(r / r_dist));
    double xx = t_dist * sin(angle);
    double yy = t_dist * cos(angle);
    xx = r > x ? -xx : xx;
    printf("%lf %lf\n", xx, yy);
  }
  return 0;
}