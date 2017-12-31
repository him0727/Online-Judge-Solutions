#include <bits/stdc++.h>
 
using namespace std;
int t, n;
 
int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    int node[2 * n + 1];
    for (int i = 1; i < 2 * n + 1; i++) {
      scanf("%d", &node[i]);
    }
    int ans[n + 1], parent = 1;
    bool visited[n + 1];
    for (int i = 0; i <= n; i++) {
      ans[i] = 0;
      visited[i] = false;
    }
    stack<int> st;
    st.push(1);
    visited[1] = true;
    for (int i = 2; i < 2 * n + 1; i++) {
      if (!st.empty()) {
        if (node[i] == st.top()) {
          st.pop();
          if (!st.empty()) parent = st.top();
          continue;
        }
        if (!visited[node[i]]) {
          ans[parent]++;
          parent = node[i];
          visited[parent] = true;
          st.push(parent);
        } else {
          st.pop();
          if (!st.empty()) parent = st.top();
        }
      }
    }
    printf("Case %d:\n", tt);
    for (int i = 1; i <= n; i++) {
      printf("%d -> %d\n", i, ans[i]);
    }
    printf("\n");
  }
  return 0;
}