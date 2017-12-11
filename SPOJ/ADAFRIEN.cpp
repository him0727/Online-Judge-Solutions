#include <bits/stdc++.h>
typedef long long int ll;
 
using namespace std;
 
int q, k;
ll ans = 0;
map<string, ll> celebrations;
vector<ll> cost;
 
int main() {
  while (scanf("%d %d", &q, &k) != EOF) {
    celebrations.clear();
    cost.clear();
    ans = 0;
    while (q--) {
      string name;
      ll c;
      cin >> name >> c;
      celebrations[name] += c;
    }
    for (auto &cel : celebrations) {
      cost.push_back(cel.second);
    }
    sort(cost.begin(), cost.end(), greater<ll>());
    for (auto &val : cost) {
      if (!k) break;
      ans += val;
      k--;
    }
    printf("%lld\n", ans);
  }
  return 0;
}