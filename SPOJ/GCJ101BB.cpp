#include <bits/stdc++.h>
 
using namespace std;
 
int x[51], v[51];
 
int main() {
  int qq, tt, N, K, B, T;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d %d %d %d", &N, &K, &B, &T);
    for (int i = 0; i < N; i++) {
      scanf("%d", &x[i]);
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", &v[i]);
    }
    int ans = 0, pass = 0, change = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (pass == K) {
        break;
      }
      if (x[i] + T * v[i] >= B) {
        pass++;
        ans += change;
      } else {
        change++;
      }
    }
    printf("Case #%d: ", qq);
    if (pass >= K) {
      printf("%d\n", ans);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}