#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
pair<int, int> n[101], m[101];
 
int main() {
  int T, N, M;
  scanf("%d", &T);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &n[i].first, &n[i].second);
  }
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d %d", &m[i].first, &m[i].second);
  }
  int s = 1, e = T;
  int mid, ans;
  while (s < e) {
    mid = s + ((e - s) >> 1);
    ll t1 = 0, t2 = 0;
    for (int i = 1; i <= N; i++) {
      if (mid >= n[i].first) {
        int base = n[i].first - 1;
        ll sum = (mid - base) / n[i].second;
        sum += (mid - base) % n[i].second == 0 ? 0 : 1;
        t1 += sum;
      }
    }
    for (int i = 1; i <= M; i++) {
      if (T - mid >= m[i].first) {
        int base = mid + m[i].first - 1;
        ll sum = (T - base) / m[i].second;
        sum += (T - base) % m[i].second == 0 ? 0 : 1;
        t2 += sum;
      }
    }
    if (t2 == t1) {
      ans = mid;
      break;
    }
    if (t2 > t1) {
      ans = mid;
      s = mid + 1;
    } else {
      e = mid;
    }
  }
  printf("%d\n", ans);
  return 0;
}