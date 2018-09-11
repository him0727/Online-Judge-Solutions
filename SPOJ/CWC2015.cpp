#include <bits/stdc++.h>
 
using namespace std;
 
int p[41];
vector<bitset<41>> f(40000001);
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", p + i);
      sum += p[i];
    }
    if (sum & 1 || n & 1) {
      printf("Case %d: No\n", qq);
      continue;
    }
    f[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = sum; j >= p[i]; j--) {
        f[j] |= (f[j - p[i]] << 1);
      }
    }
    printf("Case %d: ", qq);
    printf(f[sum / 2][n / 2] ? "Yes\n" : "No\n");
    for (int i = 0; i <= sum; i++) {
      f[i] = 0;
    }
  }
  return 0;
}