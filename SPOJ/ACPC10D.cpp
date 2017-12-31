#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
const int c = 3;
int n, t = 1;
ll graph[100001][c];
 
int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < c; j++) {
        scanf("%lld", &graph[i][j]);
      }
    }
    graph[0][2] += graph[0][1];
    graph[1][0] += graph[0][1];
    graph[1][1] += min(graph[0][1], min(graph[0][2], graph[1][0]));
    graph[1][2] += min(graph[0][1], min(graph[0][2], graph[1][1]));
    for (int i = 2; i < n; i++) {
      graph[i][0] += min(graph[i - 1][0], graph[i - 1][1]);
      graph[i][1] += min(graph[i - 1][1], min(graph[i - 1][0], min(graph[i - 1][2], graph[i][0])));
      graph[i][2] += min(graph[i - 1][2], min(graph[i - 1][1], graph[i][1]));
    }
    printf("%d. %lld\n", t++, graph[n - 1][1]);
  }
  return 0;
}