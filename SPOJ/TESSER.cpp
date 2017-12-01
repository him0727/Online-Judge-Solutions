#include <bits/stdc++.h>
 
using namespace std;
 
int t, n;
char s[100001];
 
bool kmp(char t[], int n, string p) {
  int m = p.length();
  int i, k;
  int f[m];
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
      if (k == m) return true;
    } else {
      k = f[k];
    }
  }
  return false;
}
 
int main() {
  string p;
  int prev, cur;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%d", &prev);
    for (int i = 1; i < n; i++) {
      scanf("%d", &cur);
      if (cur > prev) s[i - 1] = 'G';
      if (cur == prev) s[i - 1] = 'E';
      if (cur < prev) s[i - 1] = 'L';
      prev = cur;
    }
    cin >> p;
    if (kmp(s, n - 1, p)) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}