#include <bits/stdc++.h>
#define MAX 34000
 
using namespace std;
 
int n;
int res[3001];
bool luck[MAX];
 
int main() {
  for (int i = 0; i <= MAX; i++) {
    luck[i] = false;
  }
  for (int i = 2, x = 0; i <= MAX && x <= 3000; i++) {
    if (!luck[i]) {
      for (int k = 0, j = i + 1; j <= MAX; j++) {
        if (!luck[j]) {
          k++;
          if (k == i) {
            luck[j]= true;
            k = 0;
          }
        }
      }
      res[x++] = i;
    }
  } 
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    printf("%d\n", res[n - 1]);
  }
  return 0;
}