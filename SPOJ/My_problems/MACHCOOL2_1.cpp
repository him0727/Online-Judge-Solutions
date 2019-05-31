#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> tasks(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &tasks[i].first);
      tasks[i].second = 0;
      for (int j = 0; j < 4; j++) {
        int tmp;
        scanf("%d", &tmp);
        tasks[i].second = max(tasks[i].second, tmp);
      }
      tasks[i].second += tasks[i].first;
    }
    sort(tasks.begin(), tasks.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
      if (!pq.empty() && pq.top() <= tasks[i].first) {
        pq.pop();
      }
      pq.push(tasks[i].second);
    }
    int least = (int) pq.size();
    while (!pq.empty()) {
      pq.pop();
    }
    int ans = 86400;
    for (int i = 0; i < least; i++) {
      pq.push(tasks[i].second);
    }
    for (int i = least; i < N; i++) {
      ans = min(ans, tasks[i].first - pq.top());
      pq.pop();
      pq.push(tasks[i].second);
    }
    printf("%d\n", ans);
  }
  return 0;
}