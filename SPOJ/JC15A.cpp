#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int s, f, cs, ws;
  char d;
  scanf("%d %d %d %d %c", &s, &f, &cs, &ws, &d);
  if (s == f) {
    printf("0.000000\n");
  } else if (s > f && d == 'L' || s < f && d =='R' || ws == 0 && cs != 0) {
    printf("%.6f\n", (abs(f - s)) * 1.0 / (cs + ws));
  } else if ((s > f && d == 'L' || s < f && d =='R') && ws != 0 && cs == 0) {
    printf("%.6f\n", (abs(f - s)) * 1.0 / (cs + ws));
  } else if (cs > ws && ((s < f && d == 'L') || (s > f && d == 'R'))) {
    printf("%.6f\n", (abs(f - s)) * 1.0 / (cs - ws));
  } else {
    printf("Impossible\n");
  }
  return 0;
}