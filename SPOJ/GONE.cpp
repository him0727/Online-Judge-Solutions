#include <bits/stdc++.h>
 
using namespace std;
 
string s;
bool primes[80];
int f[10][80][2];
 
int solve(int p, int sum, bool is_lim, bool first) {
  if (first) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 80; j++) {
        f[i][j][0] = f[i][j][1] = -1;
      }
    }
  }
  if (p == s.size()) {
    return primes[sum];
  }
  if (f[p][sum][is_lim] != -1) {
    return f[p][sum][is_lim];
  }
  int lim = is_lim ? s[p] - '0' : 9;
  int ans = 0;
  for (int i = 0; i <= lim; i++) {
    ans += solve(p + 1, sum + i, is_lim && i >= lim, false);
  }
  return f[p][sum][is_lim] = ans;
}
 
int main() {
  fill(primes, primes + 80, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i < 80; i++) {
    if (!primes[i]) {
      continue;
    }
    int j = i;
    while (i + j < 80) {
      j += i;
      primes[j] = false;
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int l, r;
    scanf("%d %d", &l, &r);
    s = to_string(r);
    r = solve(0, 0, true, true);
    s = to_string(l - 1);
    l = solve(0, 0, true, true);
    printf("%d\n", r - l);
  }
  return 0;
}