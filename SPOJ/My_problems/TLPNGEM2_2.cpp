#include <bits/stdc++.h>
 
using namespace std;
 
const int BOUND = 1e9;
 
bool teleport(int x, int y, long long& dist) {
  cout << x << ' ' << y << '\n' << flush;
  cin >> dist;
  return dist == 0LL;
}
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long d1, d2;
    if (teleport(BOUND, BOUND, d1) || teleport(BOUND, -BOUND, d2)) {
      continue;
    }
    long long x1 = BOUND - d1 / 2, y1 = BOUND - (d1 - d1 / 2);
    long long x2 = x1 + 1, y2 = y1 - 1;
    long long x3 = BOUND - d2 / 2, y3 = -BOUND + (d2 - d2 / 2);
    long long x4 = x3 + 1, y4 = y3 + 1;
    long long den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    int x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / den;
    int y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / den;
    assert(teleport(x, y, d1));
  }
  return 0;
}