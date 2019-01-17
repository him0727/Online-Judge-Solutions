#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  vector<bitset<910>> connect(n);
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string s, ss;
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ' ') {
        int v = stoi(ss);
        adj[i].push_back(v);
        connect[i][v] = 1;
        ss = "";
        continue;
      }
      ss += s[j];
      if (j == s.size() - 1) {
        int v = stoi(ss);
        adj[i].push_back(v);
        connect[i][v] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (auto j : adj[i]) {
      if (i < j) {
        for (auto k : adj[j]) {
          if (j < k && connect[i][k]) {
            ans += (connect[i] & connect[j] & connect[k]).count();
          }
        }
      }
    }
  }
  ans /= 4;
  printf("%d\n", ans);
  return 0;
}