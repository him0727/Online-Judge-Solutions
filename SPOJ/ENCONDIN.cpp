#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s;
  while (getline(cin, s)) {
    string ans = "";
    int n = s.size(), i = 0;
    int rep = 0;
    while (i < n) {
      string temp = "";
      if (i < n - 1 && s[i] != s[i + 1]) {
        rep = 1;
        while (i < n - 1 && s[i] != s[i + 1]) {
          if (s[i] == '1') {
            temp += "11";
          } else {
            temp.push_back(s[i]);
          }
          i++;
        }
        if (i == n - 1) {
          if (s[i] == '1') {
            temp += "11";
          } else {
            temp.push_back(s[i]);
          }
          i++;
        }
      } else {
        rep = 0;
        temp.push_back(s[i]);
        while (i < n - 1 && s[i] == s[i + 1] && rep < 9) {
          rep++;
          i++;
        }
        if (rep < 9) {
          rep++;
          i++;
          if (rep == 1 && s[i - 1] == '1') {
            temp.push_back(s[i - 1]);
          } else if (rep == 1 && i == n - 1 && s[i] == '1') {
            temp += "11";
            i++;
          }
        }
      }
      ans += to_string(rep) + temp;
      if (rep == 1) {
        ans += "1";
      }
    }
    cout << ans << "\n";
  }
  return 0;
}