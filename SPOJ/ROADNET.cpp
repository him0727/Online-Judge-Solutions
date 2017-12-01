#include <bits/stdc++.h>

using namespace std;

const int SIZE = 203;
int graph[SIZE][SIZE] = {0};
int t, n;
 
string s;
int ans, cur;
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &graph[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <=n; j++) {
        if (graph[i][j]) {
          bool neigh = true;
          for (int k = 1; k <= n; k++) {
            if (i == k || j == k) continue;
            if (graph[i][k] && graph[k][j]) {
              if (graph[i][k] + graph[k][j] == graph[i][j]) {
                neigh = !neigh;
                break;
              }
            }
          }
          if (neigh) printf("%d %d\n", i, j);
        }
      }
    }
    if (t) printf("\n");
  }
  return 0;
}