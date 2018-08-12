#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int m[1010];
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", m + i);
    }
    stack<int> st;
    int cur = 1;
    for (int i = 0; i < n; i++) {
      if (m[i] != cur) {
        while (!st.empty() && st.top() == cur) {
          st.pop();
          cur++;
        }
        st.push(m[i]);
      } else {
        cur++;
      }
    }
    while (!st.empty()) {
      if (st.top() != cur) {
        break;
      }
      cur++;
      st.pop();
    }
    printf(cur - 1 == n ? "yes" : "no");
    printf("\n");
  }
  return 0;
}