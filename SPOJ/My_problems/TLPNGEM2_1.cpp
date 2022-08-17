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
    int x = BOUND * 2 - (d1 + d2) / 2;
    int y = BOUND * 2 - x - d1;
    assert(teleport(x, y, d1));
  }
  return 0;
}