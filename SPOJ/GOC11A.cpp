#include <bits/stdc++.h>
 
using namespace std;
 
int t, q, x;
string s;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    string t = "";
    for (char &c : s) {
      if (isdigit(c)) {
        int n = c - '0';
        if (n == 0) {
          t = "";
        } else if (n > 1) {
          string t2 = t;
          for (int i = 1; i < n; i++) {
            t += t2;
          }
        }
      } else {
        t += c;
      }
    }
    scanf("%d", &q);
    while (q--) {
      scanf("%d", &x);
      if (x > t.size()) {
        printf("-1\n");
        continue;
      }
      cout << t[x - 1] << endl;
    }
  }
  return 0;
}