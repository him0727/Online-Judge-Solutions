#include <bits/stdc++.h>
 
using namespace std;
 
int ac[6];
bool ans[100010];
 
int main() {
  int x, k;
  scanf("%d %d", &x, &k);
  ac[0] = 0;
  for (int i = 1; i <= k; i++) {
    int c;
    scanf("%d", &c);
    ac[i] = ac[i - 1] + c;
  }
  ans[0] = true;
  for (int i = 1; i <= x; i++) {
    if (ans[i]) {
      continue;
    }
    ans[i] = false;
    for (const int &v : ac) {
      if (i >= v && ans[i - v]) {
        ans[i] = true;
      }
    }
  }
  if (ans[x]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}