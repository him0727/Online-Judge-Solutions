#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 20010;
 
int total;
int p[N], height[N], size[N];
bool removed[N];
pair<int, int> way[N];
pair<char, int> query[N];
 
int find(int a) {
  return a == p[a] ? a : p[a] = find(p[a]);
}
 
void unite(int a, int b) {
  int aa = find(a);
  int bb = find(b);
  if (aa != bb) {
    total += size[aa] * (size[aa] - 1) / 2 + size[bb] * (size[bb] - 1) / 2;
    if (height[aa] >= height[bb]) {
      p[bb] = aa;
      size[aa] += size[bb];
      size[bb] = 0;
      if (height[aa] == height[bb]) {
        height[aa]++;
      }
      total -= size[aa] * (size[aa] - 1) / 2;
    } else {
      p[aa] = bb;
      size[bb] += size[aa];
      size[aa] = 0;
      total -= size[bb] * (size[bb] - 1) / 2;
    }
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      scanf("%d %d", &way[i].first, &way[i].second);
    }
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      height[i] = 0;
      size[i] = 1;
      removed[i] = false;
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
      int x = 0;
      char c;
      scanf(" %c", &c);
      if (c == 'R') {
        scanf("%d", &x);
        removed[x] = true;
      }
      query[i] = {c, x};
    }
    total = n * (n - 1) / 2;
    for (int i = 1; i < n; i++) {
      if (!removed[i]) {
        int a = way[i].first;
        int b = way[i].second;
        unite(a, b);
      }
    }
    vector<int> ans;
    for (int i = q; i >= 1; i--) {
      if (query[i].first == 'R') {
        int a = way[query[i].second].first;
        int b = way[query[i].second].second;
        unite(a, b);
      } else {
        ans.push_back(total);
      }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
      printf("%d\n", ans[i]);
    }
    printf("\n");
  }
  return 0;
}