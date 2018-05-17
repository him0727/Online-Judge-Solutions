#include <bits/stdc++.h>
 
using namespace std;
 
int c[1010];
int f[1010][1010];
int n;
 
int solve(int i, int j) {
  if (i > j || j > n || i <= 0 || j <= 0) {
    return 0;
  }
  if (f[i][j] != -1) { 
    return f[i][j];
  }
  int res1 = c[i + 1] >= c[j] ? c[i] + solve(i + 2, j) : c[i] + solve(i + 1, j - 1);
  int res2 = c[i] >= c[j - 1] ? c[j] + solve(i + 1, j - 1) : c[j] + solve(i, j - 2);
  return f[i][j] = max(res1, res2);
}
 
int main() {
  int idx = 0;
  while (1) {
    idx++;
    int sum = 0;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", c + i);
      for (int j = 1; j <= n; j++) {
        f[i][j] = -1;
      }
      f[i][i] = c[i];
      sum += c[i];
    }
    int player1 = solve(1, n);
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", idx, player1 - sum + player1);
  }
  return 0;
}