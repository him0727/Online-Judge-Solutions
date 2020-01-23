#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    vector<int> f((1 << 10), 1010);
    f[0] = 0;
    for (int tot = 0; tot < n; tot++) {
      string s;
      cin >> s;
      int mask = 0;
      for (int i = 0; i < (int) s.size(); i++) {
        mask |= (1 << (s[i] - '0'));
      }
      for (int i = 0; i < (1 << 10); i++) {
        if ((i | mask) == mask) {
          f[i] = 1;
        }
      }
      for (int i = 0; i < (1 << 10); i++) {
        f[i | mask] = min(f[i | mask], f[i] + 1);
      }
    }
    cout << (f[(1 << 10) - 1] == 1010 ? -1 : f[(1 << 10) - 1]) << '\n';
  }
  return 0;
}