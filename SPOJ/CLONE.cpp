#include <bits/stdc++.h>
 
using namespace std;
 
string dna[20001];
int ans[20001];
 
int main() {
  int n, m;
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      cin >> dna[i];
      ans[i] = 0;
    }
    if (n == 1) {
      printf("1\n");
      continue;
    }
    sort(dna, dna + n);
    int dup = 1;
    for (int i = 1; i < n; i++) {
      if (dna[i] == dna[i - 1]) {
        dup++;
        if (i == n - 1) {
          ans[dup - 1]++;
        }
      } else {
        ans[dup - 1]++;
        if (i == n - 1) {
          ans[0]++;
        }
        dup = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}