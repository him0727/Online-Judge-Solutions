#include <bits/stdc++.h>
 
using namespace std;
 
int num[10010];
 
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", num + i);
    }
    sort(num, num + n);
    vector<array<int, 3>> ans;
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && num[i] == num[i - 1]) {    
        continue;
      }
      int l = i + 1;
      int r = n - 1;
      while (l < r) {
        int sum = num[i] + num[l] + num[r];
        if (sum > 0) {
          r--;
          continue;
        }
        if (sum == 0) {
          ans.push_back({num[i], num[l], num[r]});
        }
        do {
          l++;
        } while (l < r && num[l] == num[l - 1]);
      }
    }
    printf("%d\n", ans.size());
    for (auto v : ans) {
      printf("%d %d %d\n", v[0], v[1], v[2]);
    }
  }
  return 0;
}