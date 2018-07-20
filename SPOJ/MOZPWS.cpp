#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
const int SZ = 300010;
 
int n, k, ans;
long long a[N], sg[SZ];
vector<long long> mins;
 
void build(int from, int to, int idx) {
  if (from == to) {
    sg[idx] = mins[from];
    return;
  }
  int mid = from + (to - from) / 2;
  int left = 2 * idx + 1, right = 2 * idx + 2;
  build(from, mid, left);
  build(mid + 1, to, right);
  sg[idx] = max(sg[left], sg[right]);
}
 
long long query(int from, int to, int start, int end, int idx) {
  if (start < 0 || start >= n || end < 0 || end >= n) {
    return -1e18 - 1;
  }
  if (start > to || end < from) {
    return -1e18 - 1;
  }
  if (start >= from && end <= to) {
    return sg[idx];
  }
  int mid = start + (end - start) / 2;
  int left = 2 * idx + 1, right = 2 * idx + 2;
  long long left_chd = query(from, to, start, mid, left);
  long long right_chd = query(from, to, mid + 1, end, right);
  return max(left_chd, right_chd);
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int q, l, r;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    {
      long long mi = 1e18 + 1;
      int idx;
      for (int i = 0; i < k; i++) {
        if (a[i] <= mi) {
          mi = a[i];
          idx = i;
        }
      }
      mins.push_back(mi);
      for (int i = k; i < n; i++) {
        if (idx < i - k + 1) {
          mi = 1e18 + 1;
          for (int j = i - k + 1; j <= i; j++) {
            if (a[j] <= mi) {
              mi = a[j];
              idx = j;
            }
          }
        } else {
          if (a[i] <= mi) {
            mi = a[i];
            idx = i;
          }
        }
        mins.push_back(mi);
      }
      int msz = mins.size();
      for (int i = 0; i < n - msz; i++) {
        mins.push_back(mins[msz - 1]);
      }
    }
    build(0, n - 1, 0);
    scanf("%d", &q);
    printf("Case %d:\n", qq);
    while (q--) {
      scanf("%d %d", &l, &r);
      if (r - l + 1 < k) {
        printf("Impossible\n");
        continue;
      }
      l--, r--;
      printf("%lld\n", query(l, r - k + 1, 0, n - 1, 0));
    }
    mins.clear();
  }
  return 0;
}