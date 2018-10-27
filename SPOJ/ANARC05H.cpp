#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int f[30][300];
  string s;
  int tt = 1;
  while (cin >> s) {
    if (s == "bye") {
      break;
    }
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 0; j < 300; j++) {
        f[i][j] = -1;
      }
    }
    function<int (int, int)> solve = [&](int pos, int prev_sum) {
      if (f[pos][prev_sum] != -1) {
        return f[pos][prev_sum];
      }
      f[pos][prev_sum] = 0;
      int sum = 0;
      for (int i = pos; i < s.size(); i++) {
        sum += s[i] - '0';
        if (sum >= prev_sum) {
          f[pos][prev_sum] += i == s.size() - 1 ? 1 : solve(i + 1, sum);
        }
      }
      return f[pos][prev_sum];
    };
    printf("%d. %d\n", tt++, solve(0, 0));
  }
  return 0;
}