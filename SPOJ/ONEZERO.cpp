#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
bool visited[20001];
 
void bfs(int n) {
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  queue<pair<ll, int>> q;
  pair<ll, int> cur;
  q.push(make_pair(1, 1));
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    visited[cur.second] = true;
    if (cur.second == 0) {
      while (!q.empty()) {
        q.pop();
      }
      ll temp = cur.first;
      stack<ll> st;
      while (temp > 0) {
        st.push(temp & 1);
        temp >>= 1;
      }
      while (!st.empty()) {
        printf("%lld", st.top());
        st.pop();
      }
      printf("\n");
      return;
    }
    int mod = (cur.second * 10) % n;
    int index = cur.first;
    if (!visited[mod]) {
      q.push(make_pair((index << 1), mod));
    }
    mod = (cur.second * 10 + 1) % n;
    if (!visited[mod]) {
      q.push(make_pair((index << 1) + 1, mod));
    }
  }
}
 
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 9999) {
      printf("111111111111111111111111111111111111\n");
      continue;
    }
    bfs(n);
  }
  return 0;
}