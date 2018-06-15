#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
int p[100010], size[100010];
 
int find(int i) {
  if (p[i] != i) {
    return p[i] = find(p[i]);
  }
  return i;
}
 
void unite(int i, int j) {
  int pi = find(i);
  int pj = find(j);
  if (pj != pi) {
    if (size[pi] + size[pj] > m) {
      return;
    }
    p[pj] = p[pi];
    size[pi] += size[pj];
    size[pj] = 0;
  }
}
 
bool same(int i, int j) {
  return find(i) == find(j);
}
 
int main() {
  int q;
  scanf("%d %d", &n, &m);
  scanf("%d", &q);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    size[i] = 1;
  }
  while (q--) {
    char wt;
    int x, y;
    scanf(" %c", &wt);
    if (wt == 'S') {
      scanf("%d", &x);
      printf("%d\n", size[find(x)]);
    } else {
      scanf("%d %d", &x, &y);
      if (wt == 'A') {
        unite(x, y);
      }
      if (wt == 'E') {
        printf(same(x, y) ? "Yes\n" : "No\n");
      }
    }
  }
  return 0;
}