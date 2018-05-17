#include <bits/stdc++.h>
 
using namespace std;
 
map<string, vector<string>> parent;
map<string, int> in_deg;
 
int main() {
  string in;
  while (getline(cin, in)) {
    if (in.size() == 0) {
      break;
    }
    int f = -1;
    int insz = in.size();
    bool found_id = false;
    string name = "", id = "";
    while (++f < insz) {
      if (in[f] == '0' && f == insz - 1) {
        break;
      }
      if (in[f] == ' ') {
        if (!found_id) {
          id = name;
          found_id = true;
          if (!in_deg[id]) {
            in_deg[id] = 0;
          }
        } else {
          bool dup = false;
          for (auto v : parent[name]) {
            if (v == id) {
              dup = true;
              break;
            }
          }
          if (!dup) {
            parent[name].push_back(id);
            in_deg[id]++;
          }
        }
        name.clear();
        continue;
      }
      name.push_back(in[f]);
    }
  }
  queue<string> q;
  int ans = 0;
  for (auto v : in_deg) {
    if (v.second == 0) {
      q.push(v.first);
    }
  }
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    ans++;
    for (auto v : parent[cur]) {
      if (--in_deg[v] == 0) {
        q.push(v);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}