#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int> p[10001];
 
bool compare(const pair<int,int> &a, const pair<int,int> &b) {
  return a.first > b.first;
}
 
int main() {
  int T, N, dist, fuel;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d %d", &p[i].first, &p[i].second);
    }
    p[N] = make_pair(0, 0);
    scanf("%d %d", &dist, &fuel);
    sort(p, p + N, compare);
    int ans = 0;
    priority_queue <int> pq;
    for (int i = 0; i <= N; i++) {
      int cd = dist - p[i].first;
      if (fuel < cd) {
        while (!pq.empty() && fuel < cd) {
          int cf = pq.top();
          pq.pop();
          fuel += cf;
          ans++;
        }
        if (fuel < cd) {
          ans = -1;
          break;
        }
      }
      pq.push(p[i].second);
      fuel -= cd;
      dist -= cd;
    }
    printf("%d\n", ans);
  }
  return 0;
}