#include <bits/stdc++.h>
typedef long long int ll;
 
using namespace std;
 
ll n, q, o, l, r, x, k = 0;
ll arr1[100001], arr2[100001];
 
int main() {
  scanf("%lld", &n);
  scanf("%lld", &arr1[0]);
  for (int i = 1; i < n; i++) {
    scanf("%lld", &arr1[i]);
    arr1[i] += arr1[i - 1];
  }
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &o);
    if (o == 1) {
      scanf("%lld %lld", &l, &r);
      if (l == r) {
        if (r <= k) {
          if (l > 1) printf("%lld\n", arr2[r - 1] - arr2[l - 2]);
          else printf("%lld\n", arr2[l - 1]);
        } else {
          if (l > 1) printf("%lld\n", arr1[r - k - 1] - arr1[l - k - 2]);
          else printf("%lld\n", arr1[l - k - 1]);
        }
      }
      else if (l <= k && r <= k) printf("%lld\n", arr2[r - 1] - arr2[l - 2]);
      else if (l <= k && r > k) printf("%lld\n", arr2[k - 1] - arr2[l - 2] + arr1[r - k - 1]);
      else printf("%lld\n", arr1[r - k - 1] - arr1[l - k - 2]);
    } else if (o == 2) {
      scanf("%lld", &x);
      for (int i = k; i >= 1; i--) {
        arr2[i] = arr2[i - 1] + x;
      }
      arr2[0] = x;
      k++;
    }
  }
  return 0;
}