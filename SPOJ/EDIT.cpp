#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s;
  while (cin >> s) {
    int n = s.size();
    int d1 = 0, d2 = 0;
    char s1[n], s2[n], s3[n];
    for (int i = 0; i < n; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        s1[i] = '0';
      } else {
        s1[i] = '1';
      }
      if (i & 1) {
        s2[i] = '0';
        s3[i] = '1';
      } else {
        s2[i] = '1';
        s3[i] = '0';
      }
      if (s1[i] != s2[i]) {
        d1++;
      }
      if (s1[i] != s3[i]) {
        d2++;
      }
    }
    printf("%d\n", min(d1, d2));
  }
  return 0;
}