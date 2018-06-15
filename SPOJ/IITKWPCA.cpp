#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  cin.ignore();
  while (tt--) {
    string s, ss;
    getline(cin, s);
    s += " ";
    set<string> se;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        if (ss.size() > 0) {
          se.insert(ss);
          ss = "";
        }
        continue;
      }
      ss += s[i];
    }
    printf("%d\n", se.size());
  }
  return 0;
}