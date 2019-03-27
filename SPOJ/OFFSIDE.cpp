#include <bits/stdc++.h>
 
using namespace std; 
 
int main() {
  while (true) {
    int a, d;
    scanf("%d %d", &a, &d);
    if (a == 0 && d == 0) {
      break;
    }
    int as[a], ds[d];
    for (int i = 0; i < a; i++) {
      scanf("%d", as + i);
    }
    for (int i = 0; i < d; i++) {
      scanf("%d", ds + i);
    }
    sort(ds, ds + d);
    bool offside = false;
    for (int i = 0; i < a; i++) {
      if (as[i] < ds[1]) {
        offside = true;
        break;
      }
    }
    printf(offside ? "Y\n" : "N\n");
  }
  return 0;
}