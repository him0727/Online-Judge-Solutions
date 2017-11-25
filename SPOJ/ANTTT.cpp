#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 1024;
int adj[SIZE][SIZE], acs[SIZE];
int t, n, m, x, y;
 
struct Stick {
  int x1, y1, x2, y2;
  int category = 0;
} stick[SIZE];
 
inline int orientation(struct Stick s1, int s2x, int s2y) {
  int ds = (s2x - s1.x1) * (s1.y1 - s1.y2) - (s2y - s1.y1) * (s1.x1 - s1.x2);
  if (ds == 0) return 0;
  return ds > 0 ? 1 : 2;
}
 
inline bool overlap(struct Stick s1, int s2x, int s2y) {
  if ((s2x <= max(s1.x1, s1.x2)) && (s2x >= min(s1.x1, s1.x2)) && (s2y <= max(s1.y1, s1.y2)) && (s2y >= min(s1.y1, s1.y2))) {
    return true;
  }
  return false;
}
 
inline bool intersect(struct Stick s1, struct Stick s2) {
  int o1 = orientation(s1, s2.x1, s2.y1), o2 = orientation(s1, s2.x2, s2.y2);
  int o3 = orientation(s2, s1.x1, s1.y1), o4 = orientation(s2, s1.x2, s1.y2);
  if (o1 != o2 && o3 != o4) return true;
  if (!o1 && overlap(s1, s2.x1, s2.y1)) return true;
  if (!o2 && overlap(s1, s2.x2, s2.y2)) return true;
  if (!o3 && overlap(s2, s1.x1, s1.y1)) return true;
  if (!o4 && overlap(s2, s1.x2, s1.y2)) return true;
  return false;
}
 
void dfs(int i, int c) {
  stick[i].category = c;
  for (int j = 0; j < acs[i]; j++) {
    if (!stick[adj[i][j]].category) dfs(adj[i][j], c);
  }
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    int c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &stick[i].x1, &stick[i].y1, &stick[i].x2, &stick[i].y2);
      stick[i].category = 0;
      acs[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (intersect(stick[i], stick[j])) {
          adj[i][acs[i]++] = j;
          adj[j][acs[j]++] = i;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (!stick[i].category) dfs(i, ++c);
    }
    while (m--) {
      scanf("%d %d", &x, &y);
      printf(stick[--x].category == stick[--y].category ? "YES\n" : "NO\n");
    }
  }
  return 0;
}