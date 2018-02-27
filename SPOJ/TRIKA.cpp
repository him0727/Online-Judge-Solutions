#include <bits/stdc++.h>
 
using namespace std;
 
int dp[21][21];
 
int main() {
  int N, M, X, Y;
  scanf("%d %d", &N, &M);
  scanf("%d %d", &X, &Y);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &dp[i][j]);
    }
  }
  for (int i = X + 1; i < N; i++) {
    dp[i][Y - 1] += dp[i - 1][Y - 1];
  }
  for (int i = Y + 1; i < M; i++) {
    dp[X - 1][i] += dp[X - 1][i - 1];
  }
  for (int i = X; i < N; i++) {
    for (int j = Y; j < M; j++) {
      dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  if (dp[X - 1][Y - 1] >= dp[N - 1][M - 1]) {
    printf("Y %d\n", dp[X - 1][Y - 1] - dp[N - 1][M - 1]);
  } else {
    printf("N\n");
  }
  return 0;
}