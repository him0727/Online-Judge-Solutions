#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> tlps, gems;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        gems.push_back(i);
      }
      if (s[i] == '@') {
        tlps.push_back(i);
      }
    }
    int last_gem = gems.back();
    int tlp_idx = 0, gem_idx = 0;
    vector<int> f(last_gem + 1, 10010);
    f[0] = 0;
    for (int i = 0; i <= last_gem; i++) {
      if (i > 0) {
        f[i] = min(f[i], f[i - 1] + 1);
      }
      if (s[i] == '*') {
        gem_idx++;
      }
      if (s[i] == '@') {
        int move = 1;
        while (move <= 3 && tlp_idx + move < (int) tlps.size() && tlps[tlp_idx + move] < gems[gem_idx]) {
          f[tlps[tlp_idx + move]] = min(f[tlps[tlp_idx + move]], f[i] + 3);
          move++;
        }
        tlp_idx++;
      }
    }
    cout << f[last_gem] << '\n';
  }
  return 0;
}