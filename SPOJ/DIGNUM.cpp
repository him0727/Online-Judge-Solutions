#include <bits/stdc++.h>
 
using namespace std;
 
map<string, int> d = {{"020101121", 0}, {"000001001", 1}, {"020021120", 2},
                      {"020021021", 3}, {"000121001", 4}, {"020120021", 5},
                      {"020120121", 6}, {"020001001", 7}, {"020121121", 8}, {"020121001", 9}};
 
int main() {
  string s[3];
  while (getline(cin, s[0])) {
    getline(cin, s[1]);
    getline(cin, s[2]);
    for (int i = 0; i < (int) s[0].size(); i += 3) {
      string enc = "";
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (s[j][k + i] == ' ') {
            enc += "0";
          } else if (s[j][k + i] == '|') {
            enc += "1";
          } else {
            enc += "2";
          }
        }
      }
      printf("%d", d[enc]);
    }
    printf("\n");
  }
  return 0;
}