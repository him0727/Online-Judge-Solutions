#include <bits/stdc++.h>
 
using namespace std;
 
const double PI = acos(-1);
 
int main() {
  int a, b, s, m, n;
  while (1) {
    scanf("%d %d %d %d %d", &a, &b, &s, &m, &n);
    if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0) {
      break;
    }
    double h = a * m;
    double v = b * n;
    double angle = atan2(v, h) * 180.0 / PI;
    double speed = sqrt(v * v + h * h) / s;
    printf("%.2lf %.2lf\n", angle, speed);
  }
  return 0;
}