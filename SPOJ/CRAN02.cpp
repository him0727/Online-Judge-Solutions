#include <bits/stdc++.h>
 
using namespace std;
 
long long pfx[1000010];
map<long long, long long> freq;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    long long last = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", pfx + i);
      pfx[i] += last;
      freq[pfx[i]]++;
      last = pfx[i];
    }
    long long ans = freq[0];
    for (auto v : freq) {
      ans += v.second * (v.second - 1) / 2;
    }
    printf("%lld\n", ans);
    freq.clear();
  }
  return 0;
}