#include <bits/stdc++.h>

using namespace std;

const int MAX = 10010;

struct XYZ {
  int x, y, z;
} xyz[MAX];

pair<int, int> x[MAX], y[MAX], z[MAX];
int pfxx[MAX], pfxy[MAX], pfxz[MAX];
int distx[MAX], disty[MAX], distz[MAX];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}

int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  int tt, n;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &xyz[i].x, &xyz[i].y, &xyz[i].z);
      x[i] = {xyz[i].x, i};
      y[i] = {xyz[i].y, i};
      z[i] = {xyz[i].z, i};
    }
    sort(x, x + n, compare);
    sort(y, y + n, compare);
    sort(z, z + n, compare);
    pfxx[0] = pfxy[0] = pfxz[0] = 0;
    for (int i = 1; i <= n; i++) {
      pfxx[i] = x[i - 1].first + pfxx[i - 1];
      pfxy[i] = y[i - 1].first + pfxy[i - 1];
      pfxz[i] = z[i - 1].first + pfxz[i - 1];
    }
    for (int i = 0; i < n; i++) {
      distx[x[i].second] = i * x[i].first - pfxx[i] + pfxx[n] - pfxx[i + 1] - (n - i - 1) * x[i].first;
      disty[y[i].second] = i * y[i].first - pfxy[i] + pfxy[n] - pfxy[i + 1] - (n - i - 1) * y[i].first;
      distz[z[i].second] = i * z[i].first - pfxz[i] + pfxz[n] - pfxz[i + 1] - (n - i - 1) * z[i].first;
    }
    int min_dist = INT_MAX;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int tmp_dist = distx[i] + disty[i] + distz[i];
      if (min_dist >= tmp_dist) {
        if (min_dist > tmp_dist) {
          ans.clear();
          min_dist = tmp_dist;
        }
        ans.push_back(i);
      }
    }
    for (auto v : ans) {
      printf("%d %d %d\n", xyz[v].x, xyz[v].y, xyz[v].z);
    }
    printf("\n");
  }
  return 0;
}