#include <bits/stdc++.h>
 
using namespace std;
 
int nums[101];
bool used[101];
 
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
      used[i] = false;
    }
    sort(nums, nums + n);
    int bound = nums[n -  1] / 2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      if (nums[i] > bound) {
        break;
      }
      int target = nums[i] * 2;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] == target && !used[j]) {
          used[i] = true;
          used[j] = true;
          ans++;
          break;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}