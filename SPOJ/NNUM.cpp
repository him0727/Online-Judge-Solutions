#include <bits/stdc++.h>
 
using namespace std;
 
int ans[] = {9, 0, 4, 3, 3, 1, 4, 3};
 
/*
int find(int n) {
  int from = pow(10, n - 1);
  int to = pow(10, n) - 1;
  int cnt = 0;
  for (int i = from; i <= to; i++) {
    int num = i, d = i;
    int a = 0;
    while (num > 0) {
      d = num % 10;
      num /= 10;
      a += pow(d, n);
    }
    if (a == i) {
      cnt++;
    }
  }
  return cnt;
}
*/
 
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n - 1]);
  return 0;
}