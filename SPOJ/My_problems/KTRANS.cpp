#include <bits/stdc++.h>
 
using namespace std;
 
const int NN = 55;
const int MM = 2500;
 
int dist[NN][NN], cur[NN][NN];
int u[MM], v[MM], w[MM], l[MM];
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
      cin >> u[i] >> v[i] >> w[i] >> l[i];
      u[i]--;
      v[i]--;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = (i == j ? 0 : -1);
      }
    }
    while (K--) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          cur[i][j] = dist[i][j];
        }
      }
      for (int edge = 0; edge < M; edge++) {
        int uu = u[edge];
        int vv = v[edge];
        for (int node = 0; node < N; node++) {
          if (dist[node][uu] == -1) {
            continue;
          }
          if (dist[node][uu] <= l[edge]) {
            if (cur[node][vv] == -1 || cur[node][vv] > dist[node][uu] + w[edge]) {
              cur[node][vv] = dist[node][uu] + w[edge];
            }
          }
        }
      }
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dist[i][j] = cur[i][j];
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
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