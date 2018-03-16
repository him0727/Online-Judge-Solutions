#include <bits/stdc++.h>
 
using namespace std;
 
bool is_pld(const string &s, int left, int right) {
  while (left <= right) {
    if (s[left++] != s[right--]) {
      return false;
    }
  }
  return true;
}
 
int main() {
  string s;
  int tt = 1;
  while (cin >> s) {
    int sz = (int) s.size();
    int cost = sz, len = sz;
    for (int i = 0; i < sz; i++) {
      int j = i + 1;
      while (j < sz && is_pld(s, i, j)) {
        j++;
      }
      int cur_cost = sz + i - j;
      int cur_len = sz + abs(sz - i - j); 
      if (cur_cost < cost || (cur_cost == cost && cur_len > len)) {
        cost = cur_cost;
        len = cur_len;
      }
    }
    printf("Case %d, sequence = ", tt++);
    cout << s;
    printf(", cost = %d, length = %d\n", cost, len);
  }
  return 0;
}