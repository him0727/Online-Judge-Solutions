#include <bits/stdc++.h>
 
using namespace std;

int count(int extra, vector<pair<int, int>>& tasks) {
  int n = (int) tasks.size();
  vector<pair<int, int>> time(n * 2);
  for (int i = 0; i < n; i++) {
    time[i * 2] = {tasks[i].first, 1};
    time[i * 2 + 1] = {tasks[i].second + extra, -1};
  }
  sort(time.begin(), time.end());
  int cur_least = 0;
  int least = 0;
  for (int i = 0; i < n * 2; i++) {
    cur_least += time[i].second;
    least = max(least, cur_least);
  }
  return least;
}

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
    int least = count(0, tasks);
    int ans = 0;
    int low = 0;
    int high = 86400;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (least >= count(mid, tasks)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}