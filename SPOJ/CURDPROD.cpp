#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll machine[10010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n, t;
    cin >> n >> t;
    ll high = -1, low = 1;
    for (int i = 0; i < n; i++) {
      cin >> machine[i];
      high = max(high, machine[i]);
    }
    high *= t;
    while (low < high) {
      ll mid = low + ((high - low) >> 1);
      ll temp = 0;
      for (int i = 0; i < n; i++) {
        temp += mid / machine[i];
      }
      if (temp >= t) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << high << endl;
  }
  return 0;
}