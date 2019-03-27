#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
bitset<N> bs;
int f[N];
 
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  bs[0] = 1;
  for (int i = 0; i < n; i++) {
    int coin;
    scanf("%d", &coin);
    bs |= (bs << coin);
  }
  f[0] = 0;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] + bs[i];
  }
  for (int i = 0; i < q; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    printf("%d\n", f[to] - f[from - 1]);
  }
  return 0;
}