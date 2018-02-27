#include <bits/stdc++.h>
 
using namespace std;
 
int n[10001];
 
int main() {
  int t, N;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &n[i]);
    }
    bool ok1 = true, ok2 = false;
    for (int i = 0; i < N - 1; i++) {
      if (n[i] == 0) {
        continue;
      }
      int v = min(n[i], n[i + 1]);
      n[i] -= v;
      n[i + 1] -= v;
      if (n[i] != 0) {
        ok1 = false
        break;
      }
    }
    if (n[N - 1] == 0) {
      ok2 = true;
    }
    if (ok1 && ok2) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}