#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int p;
  scanf("%d", &p);
  for (int pp = 1; pp <= p; pp++) {
    int n, a;
    scanf("%d %d", &n, &a);
    pair<int, int> asg[a];
    for (int i = 0; i < a; i++) {
      scanf("%d %d", &asg[i].first, &asg[i].second);
    }
    sort(asg, asg + a, [](pair<int, int> x, pair<int, int> y) {
      if (x.first == y.first) {
        return x.second < y.second;
      }
      return x.first < y.first;
    });
    int need = 0;
    bool ok = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < a; i++) {
      if (!pq.empty()) {
        int cur = pq.top();
        if (asg[i].first > cur) {
          pq.pop();
          need--;
        }
      }
      need++;
      if (need > n) {
        ok = false;
        break;
      }
      pq.push(asg[i].second);
    }
    printf("Plan %d: ", pp);
    if (ok) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}