#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    string s;
    cin >> s;
    s = "(" + s + ")";
    stack<char> st;
    for (char c : s) {
      if (c - 'a' >= 0 && c - 'a' <= 25) {
        printf("%c", c);
      } else {
        if (c == '(') {
          continue;
        } else if (c == ')') {
          if (!st.empty()) {
            printf("%c", st.top());
            st.pop();
          }
        } else {
          st.push(c);
        }
      }
    }
    printf("\n");
  }
  return 0;
}