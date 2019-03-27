#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> win(1e6 + 1, -1);
 
int main() {
  int k, l, m;
  scanf("%d %d %d", &k, &l, &m);
  int turns[m];
  int max_turn = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", turns + i);
    max_turn = max(max_turn, turns[i]);
  }
  win[1] = win[k] = win[l] = 0;
  for (int i = 2; i <= max_turn; i++) {
    if (win[i] != -1) {
      continue;
    }
    bool asen = false;
    asen |= win[i - 1] == 1;
    if (i - k > 0) {
      asen |= win[i - k] == 1;
    }
    if (i - l > 0) {
      asen |= win[i - l] == 1;
    }
    win[i] = asen ? 0 : 1;
  }
  for (int i = 0; i < m; i++) {
    printf(win[turns[i]] == 0 ? "A" : "B");
  }
  return 0;
}