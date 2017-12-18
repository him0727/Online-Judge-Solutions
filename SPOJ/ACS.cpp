#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1234;
const int M = 5678;
int r[N + 1], c[M + 1], cr[N + 1], cc[M + 1];
int x, y, z;
char cmd;
 
int main() {
  for (int i = 1; i <= N; i++) {
    r[i] = i;
    cr[i] = i;
  }
  for (int i = 1; i <= M; i++) {
    c[i] = i;
    cc[i] = i;
  }
  while (scanf(" %c", &cmd) != EOF) {
    if (cmd == 'R') {
      scanf("%d %d", &x, &y);
      swap(r[x], r[y]);
      cr[r[x]] = x;
      cr[r[y]] = y;
    } else if (cmd == 'C') {
      scanf("%d %d", &x, &y);
      swap(c[x], c[y]);
      cc[c[x]] = x;
      cc[c[y]] = y;
    } else if (cmd == 'Q') {
      scanf("%d %d", &x, &y);
      printf("%d\n", (r[x] - 1) * M + c[y]);
    } else if (cmd == 'W') {
      scanf("%d", &z);
      printf("%d %d\n", cr[(z - 1 + M) / M], cc[(z - 1) % M + 1]);
    }
  }
  return 0;
}