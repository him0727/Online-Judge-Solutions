#include <bits/stdc++.h>
 
using namespace std;
 
float sum[277];
 
int main() {
  sum[0] = 0;
  for (int i = 1; i < 277; i++) {
    sum[i] = 1.0 / (i + 1.0) + sum[i - 1];
  }
  float n;
  while (1) {
    scanf("%f", &n);
    if (n == 0) {
      break;
    }
    printf("%d card(s)\n", lower_bound(sum, sum + 277, n) - sum);
  }
  return 0;
}