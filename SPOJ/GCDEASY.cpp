#include <bits/stdc++.h>
 
using namespace std;
 
int t, n, k;
int a[100001];
 
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int temp = n > 1 ? gcd(a[0], a[1]) : a[0];
    for (int i = 2; i < n; i++) {
      temp = gcd(temp, a[i]);
    }
    if (temp == 1) {
      printf("0\n");
      continue;
    }
    int ans = k / temp * temp;
    for (int i = 2; i <= sqrt(temp); i++) {
      if (temp % i == 0) ans = max(max(ans, k / i * i), k / (temp / i) * temp / i);
    }
    printf("%d\n", ans);
  }
  return 0;
}