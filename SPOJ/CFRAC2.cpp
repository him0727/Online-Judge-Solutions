#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  while (true) {
    int r, c;
    vector<long long> d;
    scanf("%d %d", &r, &c);
    if (r == 0 && c == 0) {
      break;
    }
    cin.ignore();
    for (int i = 0; i < r; i++) {
      char ch = '.';
      if (i & 1) {
        string s = "";
        while (ch != '\n') {
          scanf("%c", &ch);
          if (ch - '0' >= 0 && ch - '0' <= 9) {
            s += ch;
          }
        }
        d.push_back(stoll(s));
      } else {
        while (ch != '\n') {
          scanf("%c", &ch);
        }
      }
    }
    long long a = 1LL, b = 1LL;
    for (int i = d.size() - 1; i >= 0; i--) {
      long long aa = a * d[i] + b;
      long long bb = a;
      a = aa, b = bb;
    }
    printf("%lld %lld\n", a, b);
  }
  return 0;
}