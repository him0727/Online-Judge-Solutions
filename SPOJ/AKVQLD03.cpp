#include <bits/stdc++.h>
typedef long long int ll;
 
using namespace std;
 
int n, q, a, b;
ll people[1000002];
string cmd;
 
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i <= n; i++) {
    people[i] = 0;
  }
  while (q--) {
    cin >> cmd >> a >> b;
    if (cmd == "find") {
      ll sum = 0;
      for (int i = b; i > 0; i -= i & (-i)) {
        sum += people[i];
      }
      for (int i = a - 1; i > 0; i -= i & (-i)) {
        sum -= people[i];
      }
      printf("%lld\n", sum);
    } else if (cmd == "add") {
      for (int i = a; i <= n; i += i & (-i)) {
        people[i] += b;
      }
    }
  }
  return 0;
}