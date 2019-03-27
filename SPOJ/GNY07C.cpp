#include <bits/stdc++.h>
 
using namespace std;
 
inline void input(string &s){
  getchar_unlocked();
  s = "";
  char ch = getchar_unlocked();
  while (ch != '\n') {
    s.push_back(ch);
    ch = getchar_unlocked();
  }
}
 
int main() {
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    int r, c;
    scanf("%d %d", &r, &c);
    string s;
    input(s);
    vector<vector<int>> m(r, vector<int>(c, 0));
    string before = "";
    for (char c : s) {
      before += c == ' ' ? "00000" : bitset<5>(c - 'A' + 1).to_string();
    }
    int len = before.size();
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int cur = 0;
    while (cur < len) {
      for (int i = left; i <= right; i++) {
        if (cur >= len) {
          break;
        }
        m[top][i] = before[cur++] - '0';
      }
      top++;
      for (int i = top; i <= bottom; i++) {
        if (cur >= len) {
          break;
        }
        m[i][right] = before[cur++] - '0';
      }
      right--;
      for (int i = right; i >= left; i--) {
        if (cur >= len) {
          break;
        }
        m[bottom][i] = before[cur++] - '0';
      }
      bottom--;
      for (int i = bottom; i >= top; i--) {
        if (cur >= len) {
          break;
        }
        m[i][left] = before[cur++] - '0';
      }
      left++;
    }
    printf("%d ", qq);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        printf("%d", m[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}