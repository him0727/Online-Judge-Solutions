#include <bits/stdc++.h>
#define l long int
 
using namespace std;
 
l n, k;
l arr[100007];
 
int main() {
  scanf("%lld", &n);
  for (l i = 0; i < n; i++) {
    scanf("%ld", &arr[i]);
  }
  scanf("%d", &k);
  l max_value = -1;
  deque<l> e;
  for (l i = 0; i < k; i++) {
    e.push_back(arr[i]);
    if (arr[i] >= max_value) {
      max_value = arr[i];
    }
  }
  printf("%ld", max_value);
  if (n > k) printf(" ");
  for (l i = k; i < n; i++) {
    if (!e.empty()) {
      l cur_max = e.front();
      e.pop_front();
      e.push_back(arr[i]);
      if (arr[i] >= max_value) {
        max_value = arr[i];
      } else if (max_value == cur_max) {
        max_value = *max_element(e.begin(), e.end());
      }
      printf("%ld", max_value);
      if (i < n - 1) printf(" ");
    }
  }
  printf("\n");
  return 0;
}