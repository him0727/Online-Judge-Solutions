#include <bits/stdc++.h>
 
using namespace std;
 
char c[100010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int n, q, diff = 0;
    scanf("%d", &n);
    scanf("%s", c);
    {
      int i = 0, j = n - 1;
      while (i <= j) {
        if (c[i] != c[j]) {
          diff++;
        }
        i++;
        j--;
      }
    }
    scanf("%d", &q);
    printf("Case %d:\n", qq);
    while (q--) {
      int p;
      char ch;
      scanf("%d %c", &p, &ch);
      p--;
      int m = n - p - 1;
      if (p != m) {
        if (c[p] != c[m] && ch == c[m]) {
          diff--;
        }
        if (c[p] == c[m] && ch != c[m]) {
          diff++;
        }
      }
      c[p] = ch;
      if (diff == 0) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}