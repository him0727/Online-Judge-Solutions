#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1000000007;
 
int f[100010];
 
int main() {
  f[0] = 1;
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> prev(26, -1);
    for (int i = 0; i < (int) s.size(); i++) {
      f[i + 1] = (f[i] << 1) % MOD;
      if (prev[s[i] - 'A'] >= 0) {
        f[i + 1] = (f[i + 1] - f[prev[s[i] - 'A']] + MOD) % MOD;
      }
      prev[s[i] - 'A'] = i;
    }
    cout << f[(int) s.size()] << '\n';
  }
  return 0;
}