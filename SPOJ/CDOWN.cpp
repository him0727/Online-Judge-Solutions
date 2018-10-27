#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n, d;
    scanf("%d %d", &n, &d);
    unordered_map<string, int> appear;
    vector<string> idx(1010);
    vector<int> p(1010, 0);
    int cur = 1;
    function<void (string)> add = [&](string node) {
      if (!appear[node]) {
        appear[node] = cur;
        idx[cur++] = node;
      }
    };
    while (n--) {
      string parent, child;
      int many;
      cin >> parent;
      add(parent);
      scanf("%d", &many);
      for (int i = 0; i < many; i++) {
        cin >> child;
        add(child);
        p[appear[child]] = appear[parent];
      }
    }
    vector<int> cnt(cur, 0);
    for (int i = 1; i <= cur; i++) {
      int top = i, now = 1;
      while (now <= d) {
        top = p[top];
        now++;
      }
      cnt[top]++;
    }
    vector<pair<string, int>> ans;
    for (int i = 1; i < cur; i++) {
      if (cnt[i] != 0) {
        ans.push_back({idx[i], cnt[i]});
      }
    }
    sort(ans.begin(), ans.end(), [&](pair<string, int> a, pair<string, int> b) {
      if (a.second == b.second) {
        return a.first < b.first;
      }
      return a.second > b.second;
    });
    printf("Tree %d:\n", qq);
    int distinct = 1;
    for (int i = 0; i < ans.size(); i++) {
      if (i > 0) {
        if (distinct >= 3 && ans[i].second != ans[i - 1].second) {
          break;
        }
        if (distinct < 3 && ans[i].second != ans[ans.size() - 1].second) {
          distinct++;
        }
      }
      cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    printf("\n");
  }
  return 0;
}