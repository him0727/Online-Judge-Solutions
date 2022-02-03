#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
      cin >> tasks[i].first;
      tasks[i].second = 0;
      for (int j = 0; j < 4; j++) {
        int dur;
        cin >> dur;
        tasks[i].second = max(tasks[i].second, dur);
      }
      tasks[i].second += tasks[i].first;
    }
    sort(tasks.begin(), tasks.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
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
    for (int i = least; i < n; i++) {
      ans = min(ans, tasks[i].first - pq.top());
      pq.pop();
      pq.push(tasks[i].second);
    }
    cout << ans << '\n';
  }
  return 0;
}