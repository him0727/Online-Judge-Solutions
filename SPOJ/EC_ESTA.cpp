#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
    }
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;
    left.push(a[0]);
    printf("%lld\n", a[0]);
    for (int i = 1; i < n; i++) {
      if (left.size() > right.size()) {
        if (a[i] < left.top()) {
          long long move = left.top();
          left.pop();
          left.push(a[i]);
          right.push(move);
        } else {
          right.push(a[i]);
        }
      } else {
        if (a[i] > right.top()) {
          long long move = right.top();
          right.pop();
          right.push(a[i]);
          left.push(move);
        } else {
          left.push(a[i]);
        }
      }
      if (left.size() > right.size()) {
        printf("%lld\n", left.top());
      } else {
        long long add = left.top() + right.top();
        if (add % 2 == 0) {
          printf("%lld\n", add / 2);
        } else {
          printf("%.1Lf\n", add / (long double) 2.0);
        }
      }
    }
  }
  return 0;
}