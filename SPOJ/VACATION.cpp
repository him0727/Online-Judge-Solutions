#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 200000001;
 
int dist[210][210];
 
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dist[i][j] = inf;
    }
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, d;
    scanf("%d %d %d", &u, &v, &d);
    dist[u][v] = d;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (dist[j][i] != inf && dist[i][k] != inf) {
          if (dist[j][i] + dist[i][k] < dist[j][k]) {
            dist[j][k] = dist[j][i] + dist[i][k];
          }
        }
      }
    }
  }
  int cnt = 0;
  long long sum = 0;
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    bool ok = false;
    int tmp = inf;
    for (int i = 1; i <= k; i++) {
      if (dist[a][i] != inf && dist[i][b] != inf) {
        ok = true;
        tmp = min(tmp, dist[a][i] + dist[i][b]);
      }
    }
    if (ok) {
      cnt++;
      sum += tmp;
    }
  }
  printf("%d\n%lld\n", cnt, sum);
  return 0;
}