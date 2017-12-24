#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 100001;
int t, n;
int a[SIZE], b[SIZE], c[SIZE], lis[SIZE], pos[SIZE];
 
int ceil_index(int l, int r, int key) {
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if (lis[m] >= key) r = m;
    else l = m;
  }
  return r;
}
 
int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      pos[a[i]] = i;
      lis[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
      c[i] = pos[b[i]];
    }
    int length = 1;
    lis[0] = c[0];
    for (int i = 1; i < n; i++) {
      if (c[i] < lis[0]) lis[0] = c[i];
      else if (c[i] > lis[length - 1]) lis[length++] = c[i];
      else lis[ceil_index(-1, length - 1, c[i])] = c[i];
    }
    printf("%d\n", length);
  }
  return 0;
}