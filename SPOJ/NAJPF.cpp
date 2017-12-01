#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t;
ll ans[1000007];
 
void kmp(string t, string p, ll ans[]) {
  ll m = p.length(), n = t.length();
  ll i, k, c = 0;
  ll f[m];
  f[0] = -1;
  for (i = 1; i < m; i++) {
    k = f[i - 1];
    while (k >= 0) {
      if (p[k] == p[i - 1]) break;
      else k = f[k];
    }
    f[i] = k + 1;
  }
  i = 0, k = 0;
  while (i < n) {
    if (k == -1) {
      i++;
      k = 0;
    } else if (t[i] == p[k]) {
      i++;
      k++;
      if (k == m) {
        ans[c++] = i - k + 1;
        i -= k - 1;
        k = 0;
      }
    } else {
      k = f[k];
    }
  }
  if (c) {
    printf("%lld\n", c);
    for (ll i = 0; i < c; i++) {
      printf("%lld", ans[i]);
      if (i < c - 1) printf(" ");
    }
  } else {
    printf("Not Found");
  }
  printf("\n");
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    string target, pattern;
    cin >> target >> pattern;
    kmp(target, pattern, ans);
    if (t) printf("\n");
  }
  return 0;
} 