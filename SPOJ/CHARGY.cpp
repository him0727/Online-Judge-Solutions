#include <bits/stdc++.h>
 
using namespace std; 
 
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  stack<int> st;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans += st.size() + 1;
      while (!st.empty()) {
        st.pop();
      }
    } else {
      bool add = true;
      if (!st.empty()) {
        int t = st.top();
        if (t + a[i] == 0) {
          st.pop();
          add = false;
        }
      }
      if (add) {
        st.push(a[i]);
      }
    }
  }
  ans += st.size();
  printf("%d\n", ans);
  return 0;
}