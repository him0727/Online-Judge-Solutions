#include <bits/stdc++.h>
 
using namespace std;
 
int l, b, sl, sb, t, n;
int room[1001][1001];
int temp[1001];
 
int max_sub_1d() {
  int cur_max_val = 0;
  for (int i = 0; i < sl; i++) {
    cur_max_val += temp[i];
  }
  int max_val = cur_max_val;
  for (int i = 0; i < l - sl; i++) {
    cur_max_val += temp[i + sl] - temp[i];
    max_val = max(max_val, cur_max_val);
  }
  return max_val;
}
 
int max_sub_2d() {
  for (int i = 0; i < l; i++) {
    int max_temp = 0;
    for (int j = 0; j < sb; j++) {
      max_temp += room[i][j];
    }
    temp[i] = max_temp;
  }
  int max_val = max_sub_1d();
  for (int j = 0; j < b - sb; j++) {
    for (int i = 0; i < l; i++) {
      int offset = room[i][j + sb] - room[i][j];
      temp[i] += offset;
    }
    max_val = max(max_val, max_sub_1d());
  }
  return max_val;
}
 
int main() {
  scanf("%d %d", &l, &b);
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < b; j++) {
      scanf("%d", &room[i][j]);
    }
  }
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    vector<pair<int, int>> divisors;
    int x, y;
    for (int i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        x = i;
        y = n / i;
        if ((x <= l && y <= b) || (x <= b && y <= l)) divisors.push_back(make_pair(x, y));
        if (x > l && y > b && x > b && y > l) break;
      }
    }
    if (divisors.size() == 0) {
      printf("-1\n");
      continue;
    }
    int val1, val2, max_val = INT_MIN;
    for (const pair<int, int> &d : divisors) {
      sl = d.first;
      sb = d.second;
      val1 = INT_MIN, val2 = INT_MIN;
      if (sl <= l && sb <= b) {
        val1 = max_sub_2d();
        max_val = max(max_val, val1);
      }
      sl = d.second;
      sb = d.first;
      if (sl <= l && sb <= b) {
        val2 = max_sub_2d();
        max_val = max(max_val, val2);
      }
    }
    printf("%d\n", max_val);
  }
  return 0;
}