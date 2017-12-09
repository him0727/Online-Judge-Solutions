#include <bits/stdc++.h>
 
using namespace std;
 
const double PI = acos(-1);
int n, tpl_m, m;
pair<int, int> coords[51][11];
pair<int, int> tpl[4][11];
 
void rotate(int angle, int from, int to) {
  double r_angle = (double) angle / 180.0 * PI;
  for (int i = 0; i < to; i++) {
    int npx = (int) round((tpl[0][i].first - tpl[0][0].first) * cos(r_angle) - (tpl[0][i].second - tpl[0][0].second) * sin(r_angle)) + tpl[0][0].first;
    int npy = (int) round((tpl[0][i].first - tpl[0][0].first) * sin(r_angle) + (tpl[0][i].second - tpl[0][0].second) * cos(r_angle)) + tpl[0][0].second;
    tpl[from][i] = make_pair(npx, npy);
  }
}
 
int main() {
  while(1) {
    scanf("%d", &n);
    if (!n) break;
    scanf("%d", &tpl_m);
    int x, y;
    for (int i = 0; i < tpl_m; i++) {
      scanf("%d %d", &x, &y);
      tpl[0][i] = make_pair(x, y);
    }
    for (int i = 1, angle = 90; i < 4; i++, angle += 90) {
      rotate(angle, i, tpl_m);
    }
    int id = 1;
    while(n--) {
      scanf("%d", &m);
      for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        coords[id][i] = make_pair(x, y);
      }
      if (m != tpl_m) {
        id++;
        printf("+++++\n");
        continue;
      }
      bool match;
      for (int i = 0; i < 4; i++) {
        match = true;
        int x_offset = coords[id][0].first - tpl[i][0].first;
        int y_offset = coords[id][0].second - tpl[i][0].second;
        int x_offset_r = coords[id][m - 1].first - tpl[i][0].first;
        int y_offset_r = coords[id][m - 1].second - tpl[i][0].second;
        for (int j = 0; j < m; j++) {
          if (coords[id][j].first - tpl[i][j].first != x_offset || coords[id][j].second - tpl[i][j].second != y_offset) {
            for (int k = m - 1; k >= 0; k--) {
              if (coords[id][k].first - tpl[i][m - k - 1].first != x_offset_r || coords[id][k].second - tpl[i][m - k - 1].second != y_offset_r) {
                match = false;
                break;
              }
            }
            if (!match) break;
          }
        }
        if (match) break;
      }
      if (match) printf("%d\n", id);
      id++;
    }
    printf("+++++\n");
  }
  return 0;
}