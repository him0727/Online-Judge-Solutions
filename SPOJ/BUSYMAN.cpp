#include <bits/stdc++.h>
#define l long int
 
using namespace std;
 
const l SIZE = 100007;
int t;
l n, ans, last_end;
 
struct Task {
  l start, end;
} task[SIZE];
 
bool compare(struct Task t1, struct Task t2) {
  return t1.end == t2.end ? t1.start < t2.start : t1.end < t2.end;
}
 
int main() {
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    last_end = 0;
    scanf("%d", &n);
    for (l i = 0; i < n; i++) {
      scanf("%ld %ld", &task[i].start, &task[i].end);
    }
    sort(task, task + n, compare);
    for (l i = 0; i < n; i++) {
      if (task[i].start >= last_end) {
        last_end = task[i].end;
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
} 