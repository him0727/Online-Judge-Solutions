#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> U(m), V(m), W(m), L(m);
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<vector<int>> cur(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
      cin >> U[i] >> V[i] >> W[i] >> L[i];
      U[i]--; V[i]--;
    }
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
    }
    while (k--) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cur[i][j] = dist[i][j];
        }
      }
      for (int edge = 0; edge < m; edge++) {
        int u = U[edge];
        int v = V[edge];
        for (int node = 0; node < n; node++) {
          if (dist[node][u] == -1) {
            continue;
          }
          if (dist[node][u] <= L[edge]) {
            if (cur[node][v] == -1 || cur[node][v] > dist[node][u] + W[edge]) {
              cur[node][v] = dist[node][u] + W[edge];
            }
          }
        }
      }
      swap(dist, cur);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) {
          cout << ' ';
        }
        cout << dist[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}