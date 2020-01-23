#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int fa[n], fb[n];
  int best_a = 0, best_b = 0;
  fa[0] = a[0];
  fb[0] = b[0];
  for (int i = 1; i < n; i++) {
    fa[i] = a[i] + fb[best_b];
    fb[i] = b[i] + fa[best_a];
    assert(i != best_a && i != best_b);
    if (fa[i] > fa[best_a]) {
      best_a = i;
    }
    if (fb[i] > fb[best_b]) {
      best_b = i;
    }
  }
  cout << max(fa[best_a], fb[best_b]) << '\n';
  return 0;
}