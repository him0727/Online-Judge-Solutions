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
    for (int i = 0; i + M < N; i++) {
      ans = min(ans, tasks[i + M] - tasks[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}