#include <bits/stdc++.h>
 
using namespace std;
 
int lis[101];
string s;
vector<vector<int>> pos(101);
vector<string> combs;
 
void dfs(int ep, vector<int> v, bool first) {
  if (pos[ep].size() == 0) {
    string ss = "";
    for (int i = v.size() - 1; i >= 0; i--) {
      ss += s[v[i]];
    }
    combs.push_back(ss);
    return;
  }
  if (first) {
    v.push_back(ep);
  }
  for (int i = 0; i < pos[ep].size(); i++) {
    v.push_back(pos[ep][i]);
    dfs(pos[ep][i], v, false);
    v.pop_back();
  }
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> s;
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
      lis[i] = 1;
      pos[i].clear();
    }
    int len, max_pos = 0;
    vector<int> e_pos;
    for (int i = 1; i < sz; i++) {
      len = lis[i];
      for (int j = 0; j < i; j++) {
        if (s[i] >= s[j] && lis[j] + 1 >= len) {
          if (pos[i].size() > 0 && lis[j] + 1 != len) {
            pos[i].clear();
          }
          len = lis[j] + 1;
          pos[i].push_back(j);
        }
      }
      if (len > lis[max_pos]) {
        max_pos = i;
        e_pos.clear();
        e_pos.push_back(i);
      }
      if (len == lis[max_pos]) {
        e_pos.push_back(i);
      }
      lis[i] = len;
    }
    combs.clear();
    for (auto &i : e_pos) {
      dfs(i, {}, true);
    }
    sort(combs.begin(), combs.end());
    for (auto &i : combs) {
      cout << i << "\n";
    }
    cout << "\n";
  }
  return 0;
}