#include <bits/stdc++.h>
 
using namespace std;
 
int p[20010], dist[20010];
 
int find(int i) {
  if (p[i] != i) {
    int tmp = p[i];
    p[i] = find(tmp);
    dist[i] += dist[tmp];
    return p[i];
  }
  return i;
}
 
void unite(int i, int j) {
  if (find(i) != find(j)) {
    p[i] = j;
    dist[i] = abs(i - j) % 1000;
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      dist[i] = 0;
    }
    char c;
    while (scanf(" %c", &c)) {
      if (c == 'O') {
        break;
      }
      if (c == 'E') {
        int I;
        scanf("%d", &I);
        int dummy = find(I);
        printf("%d\n", dist[I]);
      }
      if (c == 'I') {
        int I, J;
        scanf("%d %d", &I, &J);
        unite(I, J);
      }
    }
  }
  return 0;
}