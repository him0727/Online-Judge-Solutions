#include <bits/stdc++.h>
 
using namespace std;
 
int t;
string s;
string special[7] = {"987654312678", "987898765678", "987896545674", "456789234576", "987896512307", "987654888999", "999999993425"};
 
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    bool spec = false;
    for (string &ss : special) {
      if (ss == s) {
        spec = true;
        break;
      }
    }
    if (spec) printf("Special Number\n");
    else printf("Just a number\n");
  }
  return 0;
}