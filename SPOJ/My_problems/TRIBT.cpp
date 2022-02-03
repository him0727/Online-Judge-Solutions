#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(int root, int lp, int rp, vector<vector<int>>& child, int& ans) {
  int lc = child[root][0] == -1 ? 0 : dfs(child[root][0], lp + 1, 0, child, ans).first;
  int rc = child[root][1] == -1 ? 0 : dfs(child[root][1], 0, rp + 1, child, ans).second;
  ans += min(lc, rc) + min(lc, rp) + min(rc, lp);
  return {lc + 1, rc + 1};
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, root;
    cin >> n;
    vector<vector<int>> child(n, vector<int>(2, -1));
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p == -1) {
        root = i;
      } else if (child[p][0] == -1) {
        child[p][0] = i;
      } else {
        child[p][1] = i;
      }
    }
    int ans = 0;
    dfs(root, 0, 0, child, ans);
    cout << ans << '\n';
  }
  return 0;
}