#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 1440;
int t, n, q;
string from, to, name;
 
struct Show{
  int from, to;
  string name;
} shows[SIZE];
 
int convert(string s) {
  return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    while (n--) {
      cin >> from >> to >> name;
      int of = convert(from), ot = convert(to);
      int ff = of - of / 100 * 40, tt = ot - ot / 100 * 40;
      for (int i = ff; i < (tt == 0 ? SIZE : tt); i++) {
        shows[i] = Show {ff, tt, name};
      }
    }
    scanf("%d", &q);
    while (q--) {
      cin >> from;
      int of = convert(from);
      int ff = of - of / 100 * 40;
      cout << shows[shows[ff].to].name << "\n";
    }
  }
  return 0;
}