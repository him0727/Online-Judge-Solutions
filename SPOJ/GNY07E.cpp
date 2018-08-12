#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int pan[35], pos[35];
  bool face[35];
  auto flip = [&](bool &now) {
    now = !now;
  };
  auto sim = [&](int to) {
    int i = 1, j = to;
    while (i <= j) {
      if (i != j) {
        flip(face[pan[i]]);
        flip(face[pan[j]]);
        swap(pan[i], pan[j]);
      } else {
        flip(face[pan[i]]);
      }
      i++;
      j--;
    }
  };
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", pan + i);
      face[abs(pan[i])] = (pan[i] > 0);
      pan[i] = abs(pan[i]);
      pos[pan[i]] = i;
    }
    vector<int> ans;
    int m = n;
    while (m) {
      int pm = pos[m];
      if (pm == m && face[m]) {
        m--;
        continue;
      }
      bool at_first = false;
      if (m != 1 && pm == 1) {
        if (face[m]) {
          flip(face[m]);
          ans.push_back(1);
        }
        at_first = true;
      }
      if (!at_first && m != 1) {
        sim(pm);
        ans.push_back(pm);
      }
      if (face[m] && pm != 1) {
        flip(face[m]);
        ans.push_back(1);
      }
      for (int i = 1; i <= pm; i++) {
        pos[pan[i]] = i;
      }
      sim(m);
      ans.push_back(m);
      for (int i = 1; i <= m; i++) {
        pos[pan[i]] = i;
      }
      m--;
    }
    printf("%d %d", qq, ans.size());
    if (ans.size() > 0) {
      printf(" ");
    }
    for (int i = 0; i < ans.size(); i++) {
      if (i > 0) {
        printf(" ");
      }
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}