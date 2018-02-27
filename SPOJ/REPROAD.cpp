#include <bits/stdc++.h>
 
using namespace std;
 
int n[10001];
 
int main() {
  int T, N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
      scanf("%d", &n[i]);
    }
    int ans = 0, z = 0, j = 0;
    for (int i = 0; i < N; i++) {
      if (n[i] == 0) {
        z++;
      }
      if (z <= M) {
        ans = max(ans, i - j + 1);
      } else {
        while (j < i) {
          if (n[j++] == 0) {
            z--;
            break;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}