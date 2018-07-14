#include <bits/stdc++.h>
 
using namespace std;
 
int x[10010], y[10010];
 
double rec(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y) {
  int crs1 = p1x * p2y - p2x * p1y;
  int crs2 = p2x * p3y - p3x * p2y;
  int crs3 = p3x * p4y - p4x * p3y;
  int crs4 = p4x * p1y - p1x * p4y;
  return abs(crs1 + crs2 + crs3 + crs4) / 2.0;
}
 
double cir(int p1x, int p1y, int p2x, int p2y) {
  int dx = p2x - p1x;
  int dy = p2y - p1y;
  double r = sqrt(dx * dx + dy * dy) / 2.0;
  return acos(-1) * r * r;
}
 
double tri(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y) {
  int det1 = p1x * (p2y - p3y);
  int det2 = p2x * (p3y - p1y);
  int det3 = p3x * (p1y - p2y);
  return abs(det1 + det2 + det3) / 2.0;
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", x + i);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", y + i);
    }
    sort(x, x + n);
    sort(y, y + n);
    if (n < 2) {
      printf("0.000000\n");
      continue;
    }
    
    int cur = n - 2;
    vector<int> tx, ty;
    double cir_area = cir(x[0], y[0], x[n - 1], y[n - 1]);
    double rec_area = 0, tri_area = 0;
    
    if (cur == 3) {
      for (int i = 1; i <= 3; i++) {
        tx.push_back(x[i]);
        ty.push_back(y[i]);
      }
      cur -= 3;
    }
    if (cur >= 4) {
      rec_area = rec(x[1], y[1], x[2], y[n - 3], x[n - 2], y[n - 2], x[n - 3], y[2]);
      cur -= 4;
    }
    if (cur >= 3) {
      tx.push_back(x[3]);
      tx.push_back(x[4]);
      ty.push_back(y[3]);
      ty.push_back(y[4]);
      if (cur == 3) {
        tx.push_back(x[5]);
        ty.push_back(y[5]);
      }
      if (cur > 3) {
        tx.push_back(x[n - 5]);
        tx.push_back(x[n - 4]);
        ty.push_back(y[n - 5]);
        ty.push_back(y[n - 4]);
      }
    }
    
    if (tx.size() >= 3 && ty.size() >= 3) {
      for (int i = 0; i < tx.size(); i++) {
        for (int ii = 0; ii < ty.size(); ii++) {
          for (int j = 0; j < tx.size(); j++) {
            if (i == j) {
              continue;
            }
            for (int jj = ii + 1; jj < ty.size(); jj++) {
              for (int k = 0; k < tx.size(); k++) {
                if (i == k || j == k) {
                  continue;
                }
                for (int kk = jj + 1; kk < ty.size(); kk++) {
                  tri_area = max(tri_area, tri(tx[i], ty[ii], tx[j], ty[jj], tx[k], ty[kk]));
                }
              }
            }
          }
        }
      }
    }
    
    printf("%.6lf\n", cir_area + rec_area + tri_area);
  }
  return 0;
}