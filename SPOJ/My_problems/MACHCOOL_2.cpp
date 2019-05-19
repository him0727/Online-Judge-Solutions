#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> tasks(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &tasks[i]);
    }
    sort(tasks.begin(), tasks.end());
    int ans = 86400;
    for (int i = 0; i < M; i++) {
      int cur = 86400;
      for (int j = i + M; j < N; j += M) {
        cur = min(cur, tasks[j] - tasks[j - M]);
      }
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}