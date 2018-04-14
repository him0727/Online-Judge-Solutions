#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s;
  while (getline(cin, s)) {
    if (s.substr(0, 7) == "Left to") {
      int pos = -1;
      int sz = (int) s.size();
      for (int i = 7; i < sz; i++) {
        if (s[i] == '.') {
          pos = i + 2;
          break;
        }
      }
      if (pos != -1 && sz > pos + 8 && s[sz - 1] == '.') {
        if (s.substr(pos, 8) == "Right to") {
          string left = s.substr(8, pos - 10);
          string right = s.substr(pos + 9, s.size() - (pos + 10));
          int lz = (int) left.size();
          int rz = (int) right.size();
          if (lz + rz + 20 != sz) {
            continue;
          }
          if (lz == 0 || rz == 0) {
            continue;
          }
          bool valid = true;
          for (int i = 0; i < lz; i++) {
            if (!(left[i] - 'A' >= 0 && left[i] - 'A' <= 25) && !(left[i] - 'a' >= 0 && left[i] - 'a' <= 25)) {
              valid = false;
              break;
            }
          }
          if (valid) {
            for (int i = 0; i < rz; i++) {
              if (!(right[i] - 'A' >= 0 && right[i] - 'A' <= 25) && !(right[i] - 'a' >= 0 && right[i] - 'a' <= 25)) {
                valid = false;
                break;
              }
            }
          }
          if (!valid) {
            continue;
          }
          if ((left == "dragon" || right == "dragon") && left != right) {
            if (left != "dragon") {
              cout << "Left, to the " << left << "!\n";
            }
            if (right != "dragon") {
              cout << "Right, to the " << right << "!\n";
            }
          }
        }
      }
    }
  }
  return 0;
}